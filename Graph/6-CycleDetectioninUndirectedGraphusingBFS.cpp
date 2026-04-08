
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
    


    bool bfsHelper(int src,unordered_map<int,bool> &visited)
    {
        queue<int> q;
        unordered_map<int,int> parent;
        q.push(src);
        visited[src]=true;
        parent[src]=-1;
        while(!q.empty())
        {
            int frontnode=q.front();
            q.pop();
            for(auto nbr:adjacencylist[frontnode])
            {
                if(!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr]=true;
                    parent[nbr]=frontnode;
                }

                else if(visited[nbr]==true && nbr!=parent[frontnode])
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool cycleDetection(bool &ans,unordered_map<int,bool> &visited)
    {   
        for(auto src:nodes)
        {
            if(!visited[src])
            {
                ans=bfsHelper(src,visited);
                if(ans==true)
                {
                    break;
                }
            }
        }
        return ans;
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

    bool ans=false;
    unordered_map<int,bool> visited;

    g.cycleDetection(ans,visited);


    cout << (ans ? "Cycle detected\n" : "No cycle\n");
}