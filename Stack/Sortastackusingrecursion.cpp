#include<iostream>
#include<stack>
using namespace std;

void sortedPushData(stack<int> &st, int element)
{
    if(st.empty() || st.top()<=element)
    {
        st.push(element);
        return;
    }
    int topelement=st.top();
    st.pop();
    sortedPushData(st,element);
    st.push(topelement);

}
void sortStack(stack<int> &st)
{
    if(st.empty())
    {
        return;
    }

    int topelement=st.top();
    st.pop();
    sortStack(st);
    sortedPushData(st,topelement);
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
    sortStack(st);

    while(!st.empty())
    {
        cout<<st.top()<< " ";
        st.pop();
    }
}