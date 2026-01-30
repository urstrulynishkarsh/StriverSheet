#include<iostream>
#include<stack>
using namespace std;

void printmiddlevalue(stack<int> &st, int totalsize)
{
    
    if(st.size()==totalsize/2+1)
    {
        cout<<"middle element is: "<<st.top();
        return;
    }

    if(st.size()==0)
    {
        cout<<"there is not element: ";
        return;
    }
    int topelement=st.top();
    st.pop();
    printmiddlevalue(st,totalsize);
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
    int totalsize=st.size();
    printmiddlevalue(st,totalsize);
}