#include"CSVReader.h"
#include<iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <cmath>

CSVReader::CSVReader(std::string name,std::vector<std::string> columns_toSort):FileReader(name){
    convert_to_column_num(columns_toSort);
}

void CSVReader::convert_to_column_num(std::vector<std::string> columns_toSort)  //This functon converts the column names (like A,C,AA) to their resepecive column numbers
{
    for(int i =0;i<columns_toSort.size();i++)
    {
        int num = 0;
        for(int j=0;j<columns_toSort.at(i).length();j++)
        {
            num += int(pow(26,columns_toSort.at(i).length() - j - 1) * (columns_toSort.at(i).at(j) - 64));
        }
        columns_to_sort.push_back(num-1);
    }
}

void CSVReader::read_file(const char *file_name)
{
    std::string txt,intermediate;                       
    
    std::ifstream csv_file(file_name);

    int rows=0,columns = 0;

    while(getline(csv_file,txt))
    {
        std::vector<std::string> temp;
        
        table.push_back(temp);                       //Push an empty 1d vector for each row.

        columns = 0;
             
        std::stringstream check(txt); 
        
        while(getline(check, intermediate, ','))    //Splits the elements with commas.  
        { 
            table[rows].push_back(intermediate);    //Push each element to that empty vector.
            columns++;
        } 
        rows++;
    }}

void CSVReader::write_toFile(const char *file_name)      //Writes the 2d vector to a csv file.
{
    std::ofstream myfile;

    myfile.open(file_name);

    for(int i=0;i<table.size();i++)
    {
        int j = 0;
        while(j < table.at(i).size())
        {
            myfile << table.at(i).at(j);
            if(j != table.at(i).size()-1)
            {
                myfile<<",";
            }
            else
            {
                myfile<<"\n";                    
            }
            j++;
        }
    }
    myfile.close();
}

void CSVReader::process()
{
    int rows = table.size();

    sort_single_column(0,rows-1,columns_to_sort.at(0));     //Sorts first column in the columns to sort vector.

    for(int n = 1;n<columns_to_sort.size();n++)             //Finds the elements which are common in the (n-1)th column given by the user to sort and sorts those . 
    {                                                       //with respect to the second column given by the user to sort.
        for(int i = 0; i<rows;i++)
        {
            int j = i;
            
            while(((i+1)<table.size()) && strcmp(table.at(i).at(columns_to_sort.at(n-1)).c_str(),table.at(i+1).at(columns_to_sort.at(n-1)).c_str()) == 0)
            {   
                i++;                                        //Finds the starting and ending indeces of the common elements in (n-1)th column after sorting. 
            }

            if(j!=i) sort_single_column(j,i,columns_to_sort.at(n)); //sorts the nth column (between ith and jth rows) wherever there are common elements range in the (n-1)th column after sort.  
        }
    }
}

void CSVReader::sort_single_column(int start,int end,int col){
    
    int k;
    std::string sort_type ;                                     

    for(k=0;k<table.size();k++)                                     //Reads all the elements in the column to set the sort type  
    {   
        int j;
        for(j = 0;j < table.at(k).at(col).length();j++)
        {
            char char_at = table.at(k).at(col).at(j);
            if((char_at<48  || char_at >57 ) && char_at!=46)        //If  atleast one character in the colomn is anything other than 0 to 9 or '.'(float values like - 3 . 14)  
            {                                                       //we conclude the sort type as lexicographical.
                break;
            }
        }
        if(j!=table.at(k).at(col).length()) break;
    }
    
    if(k==table.size())    sort_type = "Numerical";          
    else    sort_type = "Lexicographical";


    std::vector<std::string> temp;

    for(int i=start;i<end;i++)                                          //Using bubble sort.
    {
        for(int j=start;j<end-(i-start);j++)
        {
            if(sort_type.compare("Lexicographical")==0)                 //If the sort type is lexicographical, then swaps accordingly.       
            {
                if(table.at(j).at(col).compare(table.at(j+1).at(col)) > 0)
                {
                    temp = table.at(j);
                    table.at(j) = table.at(j+1);
                    table.at(j+1) = temp;
                    
                }
            }
            else if(sort_type.compare("Numerical")==0)                  //If the sort type is Numerical, then swaps accordingly.
            {
                if(std::stoi(table.at(j).at(col)) > std::stoi(table.at(j+1).at(col)) )
                {
                    temp = table.at(j);
                    table.at(j) = table.at(j+1);
                    table.at(j+1) = temp;
                }
            }
        }
    }
}
