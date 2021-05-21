#include<iostream>
#include"CSVReader.h"
#include"CSVReader2.h"
#include "PPM.h"
#include "GDF_to_CSV.h"
#include "stats.h"

int main(int argc, char *argv[])
{   
/////////////////////////////////////////////////////// Dhruv's Part
    GDF_to_CSV cnvet(argv[1]);

    cnvet.read_file(argv[1]);
    cnvet.write_toFile("reportcard.csv");
    cnvet.process();
/////////////////////////////////////////////////////// Shivyansh's Part
    char* filename = argv[2];

    PPM ppm(filename);
    
    ppm.read_file(filename);
    ppm.process();
    ppm.write_toFile("outfile.ppm");

/////////////////////////////////////////////////////// Shrey's Part
    CSVReader2 csvreader(argv[3]);

    csvreader.read_file(argv[3]);
    csvreader.process();
    csvreader.write_toFile("transpose.csv");

///////////////////////////////////////////////////// Rohit's part
    stats obj(argv[4]);
    obj.read_file(argv[4]);
    obj.process();
    obj.write_toFile("stats_output.txt");

///////////////////////////////////////////////////// Dhamodhar's part

    std::vector<std::string> myvector;     //Stores the columns which are to be sorted.
    for(int i=6;i<argc;i++)
    {
        myvector.push_back(argv[i]);
    }

    CSVReader csv_file(argv[5],myvector);   //Creates CSVReader instance.
    
    csv_file.read_file(argv[5]);
    csv_file.process();
    csv_file.write_toFile("sorted_csv.csv");    
}