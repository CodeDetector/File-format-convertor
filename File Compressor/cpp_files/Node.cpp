#include<iostream>
#include<bits/stdc++.h>
#include<string.h>
#include"Node.h"

using namespace std;

//constructor
Node::Node(vector<string> v)
{
    this->node_name = v[0];
    this->node_label = v[1];
}
//copy constructor
Node::Node(const Node& n)
{
    this->node_label = n.node_label;
    this->node_name = n.node_name;
    this->seq = n.seq;
}
//destructor
Node::~Node(){}

string Node::getNodeLabel()//getter for the node label
{
    return node_label;
}

// GETTERS

string Node::getNodeName()//getter for the name of the node
{
    return node_name;
}
vector<double> Node::getSequence()//sequence in which 0 indicates that the node is not a neighbour and 1 indicates that the node is a neighbour.
{
    return seq;
}
void Node::addSequence(double d)//adds the value of 1/0 to the sequence
{
    seq.push_back(d);
}