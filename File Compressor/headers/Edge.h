#ifndef EDGE_H
#define EDGE_H
#include"Node.h"

class Edge{
    std::string src;
    std::string dest;
    double w;
    public:
    Edge(std::string,std::string,double);
    Edge(const Edge&);
    std::string getSource();
    std::string getDest();
    double getWeight();
};
#endif