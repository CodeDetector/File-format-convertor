#include<iostream>
#include<vector>
#include <utility>
#include "FileReader.h"

using namespace std;

class CSVReader2:public FileReader{
    private:
        vector<pair<string,vector<string>>> Dataset;
        vector<pair<string,vector<string>>> take_input(string filename);
        void transpose_csv();
    public:
        CSVReader2(string file_name);
        void read_file(const char *filename);
        void write_toFile(const char *filename);
        void process();
};