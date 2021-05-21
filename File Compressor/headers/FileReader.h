#include<iostream>

#ifndef FR_H
#define FR_H

class FileReader{
    private:
        std::string file_name;
    public:
        FileReader(std::string name);
        virtual void read_file(const char *filename) = 0;
        virtual void write_toFile(const char *filename) = 0;
        virtual void process() = 0;
        std::string get_file_name();
};
#endif