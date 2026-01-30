#include<iostream>
#include<vector>
#include<map>
#include<stack>
#include<unordered_map>
using namespace std;


 vector<int> nextSmallerEle(vector<int>& arr) {
        //  code here
        int n=arr.size();
        vector<int> ans(n);
        stack<int> st;
        st.push(-1);
        for(int i=n-1;i>=0;i--)
        {
            int element=arr[i];
            
            while(st.top()>=element)
            {
                st.pop();
            }
            ans[i]=st.top();
            st.push(element);
        }
        return ans;
}


int main()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the element in the array: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
   
    

    vector<int> result=nextSmallerEle(arr);
    for(int val:result)
    {
        cout<<val<<" ";
    }

    return 0;
    
   
}