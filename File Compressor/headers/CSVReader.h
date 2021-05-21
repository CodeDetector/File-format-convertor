#include<vector>
#include"FileReader.h"
class CSVReader:public FileReader{
    private:
        std::ifstream file();
        std::vector<std::vector<std::string>> table;
        std::vector<int> columns_to_sort;

        void sort_single_column(int start,int end,int col);
        void convert_to_column_num(std::vector<std::string> columns_toSort);
    
    public:
        CSVReader(std::string file_name,std::vector<std::string> columns_to_sort);

        void read_file(const char *filename);
        void process();
        void write_toFile(const char *filename);
};