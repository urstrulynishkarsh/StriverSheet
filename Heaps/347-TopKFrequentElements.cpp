#include<iostream>
#include<vector>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int val:nums)
        {
            mp[val]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >pq;
        for(auto i=mp.begin();i!=mp.end();i++)
        {
            pq.push({i->second,i->first});
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        vector<int> ans;
        while(!pq.empty())
        {

            ans.push_back(pq.top().second);
            pq.pop();
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
    int k;
    cout<<"Enter the value of k: ";
    cin>>k;

   

    vector<int> ans=topKFrequent(arr,k);
    for(int val:ans)
    {
        cout<<val<<" ";
    }
}