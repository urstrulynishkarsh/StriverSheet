#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> NGL(vector<int> &nums)
{
    vector<int> ans;
    stack<pair<int,int>> st;
    for(int i=0;i<nums.size();i++)
    {
        if(st.empty())
        {
            ans.push_back(-1);
        }
        else if(st.size()>0 && st.top().first>nums[i])
        {
            ans.push_back(st.top().second);
        }
        else if(st.size()>0 && st.top().first<=nums[i])
        {
            while(st.size()>0 && st.top().first<=nums[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                ans.push_back(-1);
            }
            else{
                ans.push_back(st.top().second);
            }
        }
        st.push({nums[i], i});
    }
    return ans;
}
int main()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    vector<int> v(n);
    cout<<"Enter the element in the array: ";
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    vector<int> result=NGL(v);
    // for(auto val:result)
    // {
    //     cout<<val<<" ";
    // }

    for(int i=0;i<result.size();i++)
    {
        result[i]=i-result[i];
    }

    for(auto val:result)
    {
        cout<<val<<" ";
    }

}