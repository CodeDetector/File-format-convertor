#include"FileReader.h"

FileReader::FileReader(std::string name){
    file_name = name;
}

std::string FileReader::get_file_name()
{
    return file_name;
}

