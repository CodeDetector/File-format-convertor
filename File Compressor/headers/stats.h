#ifndef stats_h
#define stats_h
#include "FileReader.h"
#include <fstream>

class stats:public FileReader{
    public:
        int lines;
        int words;
        int size;
        int total;
        std::string str;
        int no_spaces;
        int spaces;
        std::ifstream file;
        stats(std::string file_name);
        virtual void read_file(const char *filename);
        virtual void write_toFile(const char *filename);
        virtual void process();
};
#endif
