#include<iostream>
#include<stack>
using namespace std;

void SortedInsert(stack<int> &st, int value)
{
    if(st.empty())
    {
        st.push(value);
        return;
    }
    if(st.top()<value)
    {
        st.push(value);
        return;
    }
    int topelement=st.top();
    st.pop();

    SortedInsert(st,value);

    st.push(topelement);
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
    int value;
    cout<<"Enter the value which you want to sorted";
    cin>>value;
    SortedInsert(st,value);

    while(!st.empty())
    {
        cout<<st.top()<< " ";
        st.pop();
    }
}