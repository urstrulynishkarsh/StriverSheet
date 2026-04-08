
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

    bool DFS(int src,unordered_map<int,bool> &visited,unordered_map<int,bool> &dfstracker)
    {
        visited[src]=true;
        dfstracker[src]=true;

        for(auto nbr:adjacencylist[src])
        {   
            if(!visited[nbr])
            {
                bool isccycle=DFS(nbr,visited,dfstracker);
                if(isccycle)
                {
                    return true;
                }
            }
            if(visited[nbr]==true && dfstracker[nbr]==true)
            {
                return true;
            }
        }
        dfstracker[src]=false;
        return false;

    }


    bool cycleDetection()
    {
        unordered_map<int,bool> visited;
        unordered_map<int,bool> dfstracker;
        for(auto node:nodes)
        {
            if(!visited[node])
            {
                bool isccycle=DFS(node,visited,dfstracker);
                if(isccycle)
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
        g.addEdge(u,v,1);
    }

    bool ans=g.cycleDetection();



    cout << (ans ? "Cycle detected\n" : "No cycle\n");
}