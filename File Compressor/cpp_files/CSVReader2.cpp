#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include <sstream>
#include "CSVReader2.h"

using namespace std;

CSVReader2::CSVReader2(string file_name):FileReader(file_name)
{}


void CSVReader2::process()
{

}

void CSVReader2::read_file(const char *file_name)
{
  ifstream myFile(file_name);
  if(!myFile.is_open()) throw runtime_error("Could not open file");
  string line, colname;
  string val;
  if(myFile.good())
  {
    getline(myFile, line);
    stringstream ss(line);
    while(getline(ss, colname,','))
    {
      Dataset.push_back({colname, vector<string> {}});
    }
  }
  while(getline(myFile, line))
  {
    stringstream ss(line);
    int colIdx = 0;
    while(getline(ss,val,','))
    {
      Dataset.at(colIdx).second.push_back(val);
      if(ss.peek() == ',')
      {
        ss.ignore();
      }
      colIdx++;
    }
  }
  myFile.close();
}

void CSVReader2::write_toFile(const char* file_name)
{
    ofstream myFile(file_name);
    for(int i=0;i<Dataset.size();i++)
    {
      myFile<<Dataset.at(i).first;
      myFile<<",";
      for(int j=0;j<Dataset.at(i).second.size();j++)
      {
        myFile<<Dataset.at(i).second.at(j);
        if(j != Dataset.at(i).second.size() - 1) myFile << ",";
      }
        myFile << "\n";
    }
    myFile.close();
} 