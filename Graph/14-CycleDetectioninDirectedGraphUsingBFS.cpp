
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<set>
#include<list>
#include<map>
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

   void topologicalsortBFS(int n)
   {
        queue<int> q;
        unordered_map<int,int> indegree;
        // calculate indegree
        for(auto node:adjacencylist)
        {
            for(auto nbr:node.second)
            {
                indegree[nbr]++;
            }
        }
        // push  indegree 0 in queue
        for(auto node:nodes)
        {
            if(indegree[node]==0)
            {
                q.push(node);
            }
        }
        int count=0;

        while(!q.empty())
        {
            int frontnode=q.front();
            q.pop();
            // cout<<frontnode<<",";
            count++;
            for(auto nbr:adjacencylist[frontnode])
            {
                indegree[nbr]--;
                if(indegree[nbr]==0)
                {
                    q.push(nbr); 
                }
            }
        }
        // int 
        // for(auto)

        if(count!=n)
        {   
            cout<<"cycle exist";
        }
        else{
            cout<<"cycle not present";
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
    // stack<int> st;
    g.topologicalsortBFS(n);

    // while(!st.empty())
    // {
    //     cout<<st.top()<<" ";
    //     st.pop();
    // }

}