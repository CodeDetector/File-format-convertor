#ifndef GDF_to_CSV_H
#define GDF_to_CSV_H
#include<bits/stdc++.h>
#include"Node.h"
#include"Edge.h"
#include"FileReader.h"

using namespace std;

class GDF_to_CSV:public FileReader{
        char *name;
        vector<Node> List_Of_Nodes;
        vector<Edge> EdgeList;
        std::fstream fptr;
    public:
        GDF_to_CSV(char*);
        GDF_to_CSV(GDF_to_CSV &);
        void read_file(const char *file_name);
        void write_toFile(const char *file_name);
        void process();
        void readEdges(vector<string>&);
        double isNeighbour(Node&,Node&);
        void Sequences();    
};
#endif