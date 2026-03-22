#include<iostream>
#include<queue>
using namespace std;

void reverseQueue(queue<int> &q)
{
    stack<int> st;
    while(!q.empty())
    {
        int element=q.front();
        q.pop();
        st.push(element);
    }
    while(!st.empty())
    {
        int element=st.top();
        st.pop();
        q.push(element);
    }
}
int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);


    reverseQueue(q);

    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }


}