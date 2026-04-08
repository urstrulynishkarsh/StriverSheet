
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
    void BFS(int src)
{
    queue<int> q;
    unordered_map<int, bool> visited;
    q.push(src);
    visited[src]=true;
    while(!q.empty())
    {
        int frontnode=q.front();
        cout<<frontnode<<" ";
        q.pop();
        for(auto neighbor:adjacencylist[frontnode])
        {
            int node=neighbor;
            if(!visited[node])
            {
            q.push(node);
            visited[node]=true;
            }
        }
    } 
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

    g.BFS(1);

}