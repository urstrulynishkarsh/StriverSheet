
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
    void BFS(int src, int dest)
    {
        queue<int> q;
        unordered_map<int,bool> visited;
        unordered_map<int,int> parent;

        q.push(src);
        visited[src]=true;
        parent[src]=-1;

        while(!q.empty())
        {
            int frontNode=q.front();
            q.pop();
            for(auto nbr:adjacencylist[frontNode])
            {
                if(!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr]=true;
                    parent[nbr]=frontNode;
                }
            }
        }

        vector<int> ans;
        while(dest!=-1)
        {
            ans.push_back(dest);
            dest=parent[dest];
        }
        reverse(ans.begin(),ans.end());
        for(int val:ans)
        {
            cout<<val<<"-";
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
        g.addEdge(u,v,0);
    }
    int src,dest;
    cout<<"Enter the value of source an destination: ";
    cin>>src>>dest;


    g.BFS(src,dest);

}