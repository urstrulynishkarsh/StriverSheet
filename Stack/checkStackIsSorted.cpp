#include<iostream>
#include<stack>
using namespace std;

bool checkStackisSorted(stack<int> &st, int element1)
{
    if(st.empty())
    {
        return true;
    }
    int element2=st.top();
    st.pop();
    if(element2<element1)
    {
        bool ans=checkStackisSorted(st,element2);
        return ans;
    }
    else{
        return false;
    }


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
    int element1=INT_MAX;
    cout<<checkStackisSorted(st,element1);
}