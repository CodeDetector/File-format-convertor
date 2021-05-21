#ifndef NODE_H
#define NODE_H
#include<bits/stdc++.h>
#include<string.h>
#include"Edge.h"

class Node{
    std::string node_name;
    std::string node_label;
    std::vector<double> seq;
    public:
    Node(std::vector<std::string>);
    Node(){};
    Node(const Node&);
    ~Node();
    std::string getNodeLabel();
    std::string getNodeName();
    void addSequence(double);
    std::vector<double> getSequence();
};
#endif