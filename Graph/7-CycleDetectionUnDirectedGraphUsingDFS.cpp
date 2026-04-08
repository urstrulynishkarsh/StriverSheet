
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<set>
#include<list>
using namespace std;

class Graph{
    public:
        unordered_map<int,list<int> > adjacencylist;
        set<int> nodes;

    void addEdge(int u, int v, bool direction)
    {
        nodes.insert(u);
        nodes.insert(v);
        if(direction==0)
        {
            adjacencylist[u].push_back(v);
            adjacencylist[v].push_back(u);
        }
        else{
            adjacencylist[u].push_back(v);
        }
    }
    void printAdjacencyList()
    {
        for(auto node : nodes)
        {
        cout << node << ": {";

        auto it = adjacencylist[node].begin();

        while(it != adjacencylist[node].end())
        {
            cout << *it;
            it++;

            if(it != adjacencylist[node].end())
                cout << ",";
        }

        cout << "}" << endl;
        }
    }

    bool checkcycle(int src, unordered_map<int, bool> &visited, int parent)
    {
        visited[src]=true;
        for(auto nbr:adjacencylist[src])
        {
            if(nbr==parent)
            {
                continue;
            }
            if(!visited[nbr])
            {
                bool iscycle=checkcycle(nbr,visited,src);
                if(iscycle)
                {
                    return true;
                }
            }
            else if(visited[nbr]==true)
            {
                return true;
            }
        }
        return false;
    }
    
    bool cycleDetection()
    {
        unordered_map<int, bool> visited;
        for(auto node:nodes)
        {
            if(!visited[node])
            {
                int parent=-1;
                bool iscycle=checkcycle(node,visited,parent);
                if(iscycle)
                {
                    return true;
                }
            }
        }
        return false;
    }

    


};

// 


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
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v,0);
    }

    bool ans=g.cycleDetection();



    cout << (ans ? "Cycle detected\n" : "No cycle\n");
}