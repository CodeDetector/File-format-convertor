#include<bits/stdc++.h>
#include<fstream>
#include<string.h>
#include"Node.h"
#include"Edge.h"
#include"GDF_to_CSV.h"

//constructor
GDF_to_CSV::GDF_to_CSV(char* filename):FileReader(filename){
    name = filename;
}
//copy constructor
// GDF_to_CSV::GDF_to_CSV(GDF_to_CSV& g)
// {
//     this->name = g.name;
// }
//file convertor
void GDF_to_CSV::read_file(const char *file_name)
{
    std::ifstream f(file_name);
    string text;
    bool nodedef = false;
    bool edgedef = false;
    int index;
    while(getline(f,text))
    {
        bool flag = false;
        if((index = text.find("nodedef"))!= string::npos)//NodeDef line
        {
            flag = true;
            nodedef = true;
            edgedef = false;
        }
        if((index = text.find("edgedef"))!= string::npos)//EdgeDef line
        {
            flag = true;
            edgedef = true;
            nodedef = false;
        }
        if(flag==false)//Content of nodeDef and EdgeDef
        {   
            string s;
            stringstream X(text);
            vector<string> v;
            while(getline(X,s,','))
            {
                v.push_back(s);
            }
            if(nodedef)//Content of NodeDef
            {
                Node n(v);
                List_Of_Nodes.push_back(n);//Storing Nodes
            }
            else//Content of EdgeDef
            {
                if(!v.empty())
                {
                    readEdges(v);//read edges
                }
            }
        }
    }
    Sequences();
    f.close();
}
void GDF_to_CSV::write_toFile(const char *file_name)
{
    remove(file_name);//remove the existing csv file
    fptr.open(file_name, ios::out | ios::app);//creating or opening a csv file
    for(Node n : List_Of_Nodes)
    {
        fptr<<";"<<n.getNodeName();//printing into the csv file
    }
    fptr<<"\n";
    for(Node n:List_Of_Nodes)
    {
        vector<double> v = n.getSequence();
        fptr<<n.getNodeName();
        for(double i:v)
        {
            fptr<<";"<<i;//printing into the csv file
        }
        fptr<<"\n";
    }
    fptr.close();
}
void GDF_to_CSV::readEdges(std::vector<std::string> &v)
{
    for(Node &n: List_Of_Nodes)
    { 
        for(Node &nn: List_Of_Nodes)
        {
            if(n.getNodeName()==v[0] && nn.getNodeName()==v[1])//To store the neighbours
            {
                double W = stold(v[3]);
                if(v[2]=="true")//If directed edge
                { 
                    Edge e(n.getNodeName(),nn.getNodeName(),W);
                    EdgeList.push_back(e);//Adding the edge to the list of edges
                }
                else //If undirected edge
                {
                    double w = stold(v[4]);
                    Edge e(n.getNodeName(),nn.getNodeName(),W);//adding edge to edgelist
                    EdgeList.push_back(e);
                    Edge ee(nn.getNodeName(),n.getNodeName(),w);//adding edge to edgelist
                    EdgeList.push_back(ee);
                }
            }
        }
    }
}
void GDF_to_CSV::process(){

}
void GDF_to_CSV::Sequences()//updating the sequence of the node
{
    for(Node &n:List_Of_Nodes)
    {
        for(Node &nn : List_Of_Nodes)
        {
            n.addSequence(isNeighbour(n,nn));//add weight to the sequence
        }
    }
}
//checks if two nodes are neighbours
double GDF_to_CSV::isNeighbour(Node &n,Node &nn)
{
    for(Edge e:EdgeList)
    {
        if(e.getSource()==n.getNodeName() && e.getDest()==nn.getNodeName())
        {
            return e.getWeight();
        }
    }
    return 0;
}
