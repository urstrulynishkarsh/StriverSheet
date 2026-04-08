#include<iostream>
#include<vector>
using namespace std;

int connectSticks(vector<int>& sticks) {
        // Your Code Goes Here
        priority_queue<int,vector<int>,greater<int> > pq;
        for(int i=0;i<sticks.size();i++)
        {
            pq.push(sticks[i]);
        }
        int cost=0;
        while(pq.size()>1)
        {
            int first=pq.top();
            pq.pop();
            int second=pq.top();
            pq.pop();
            int mergelength=first+second;
            pq.push(mergelength);
            cost+=mergelength;
        }
        return cost;
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
   

    cout<<connectSticks(arr);
}