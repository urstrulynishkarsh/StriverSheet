#include<iostream>
#include<stack>
using namespace std;

void InsertAtBottom(stack<int> &st, int value)
{
    if(st.empty())
    {
        st.push(value);
        return;
    }
    int topelement=st.top();
    st.pop();

    InsertAtBottom(st,value);

    st.push(topelement);
}

void reverseStack(stack<int> &st)
{
    // base case
    if(st.empty())
    {
        return;
    }


    int element=st.top();
    st.pop();
    reverseStack(st);
    InsertAtBottom(st,element);
    
}
int main()
{
    int n;
    cout<<"Enter the value of n:";
    cin>>n;
    stack<int> st;
    for(int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        st.push(val);
    }
    
    reverseStack(st);

    while(!st.empty())
    {
        cout<<st.top();
        st.pop();
    }
}