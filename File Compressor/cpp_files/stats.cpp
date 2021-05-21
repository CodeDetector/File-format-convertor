#include<bits/stdc++.h>
using namespace std;
#include "stats.h"
#include <fstream>
#include "FileReader.h"

stats::stats(std::string file_name):FileReader(file_name)
{

}
void stats::read_file(const char* file_name)
{
    string str;
    file.open(file_name, ios::in);
    while(getline(file, str))
    {
        for(int i=0; i<str.length(); i++)
        {
            if(isspace(str[i])) spaces++;
        }
        total += str.length();
        lines++;
    }
    file.clear();
    total = total + lines -1;
    no_spaces = total - spaces;
    size = file.tellg();
    file.seekg(0,ios::beg);
    while(file>>str)
    {
        words++;
    }
    size--;
    file.clear();
}
void stats::process()
{
    
}
void stats::write_toFile(const char* file_name)
{
    ofstream file_out;
    file_out.open(file_name);
    file_out<<"Number of Lines "<<lines<<"\n";
    file_out<<"Number of Words "<<words<<"\n";
    file_out<<"Total Characters "<<total<<"\n";
    file_out<<"Characters excluding spaces "<<no_spaces<<"\n";
    file_out<<"Total Bytes "<<size<<"\n\n";

    file.seekg(0,ios::beg);
    while(getline(file, str))
    {
        file_out << str << "\n";
    }
    file.close();
    file_out.close();
} 