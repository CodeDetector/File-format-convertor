#include"Edge.h"
#include"Node.h"
#include<string.h>

//constructor
Edge::Edge(std::string source,std::string d,double weight)
{
    this->src = source;
    this->dest = d;
    this->w = weight;
}
//copy constructor
Edge::Edge(const Edge& e)
{
    this->src = e.src;
    this->dest = e.dest;
    this->w = e.w;
}
//getter
std::string Edge::getSource()
{
    return src;
}
std::string Edge::getDest()
{
    return dest;
}
double Edge::getWeight()
{
    return w;
}
