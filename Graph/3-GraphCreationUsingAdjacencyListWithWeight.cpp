#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
#include<set>
using namespace std;

class Graph{
        public:
        unordered_map<int,list<pair<int,int>> > adjacencylist;
        set<int> nodes;

        void addEdge(int u, int v, int weight, bool direction)
        {
            nodes.insert(u);
            nodes.insert(v);
            if(direction==0)
            {
                adjacencylist[u].push_back({v,weight});
                adjacencylist[v].push_back({u,weight});
            }
            else{
                adjacencylist[u].push_back({v,weight});
            }
    }

    void printAdjacencyList()
    {
        for(auto node:nodes)
        {
            cout<<node<<": {";
            auto it=adjacencylist[node].begin();
            while(it!=adjacencylist[node].end())
            {
                cout<<"(";
                cout<<it->first;
                cout<<",";
                cout<<it->second;
                cout<<")";
                it++;
                if(it!=adjacencylist[node].end())
                {
                    cout<<",";
                }
            }
            cout << "}" << endl;
        }
    }


};


int main()
{
    int n;
    cout<<"Enter the number of nodes: ";
    cin>>n;

    int e;
    cout<<"Enter the number of edges: ";
    cin>>e;

    Graph g;

    for(int i=0;i<e;i++)
    {
        int u,v,weight;
        cin>>u>>v>>weight;

        g.addEdge(u,v,weight,0);
    }
    g.printAdjacencyList();
}