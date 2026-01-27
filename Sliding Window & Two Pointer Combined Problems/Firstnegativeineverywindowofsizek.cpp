#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

  vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        int n=arr.size();
        int i=0;
        int j=0;
        vector<int> ans;
        queue<int> q;
        while(j<n)
        {
            if(arr[j]<0)
            {
                q.push(arr[j]);
            }
            if(j-i+1<k)
            {
                j++;
            }
            else if(j-i+1==k)
            {
                if (q.empty()) {
                    ans.push_back(0);
                } else {
                    ans.push_back(q.front());
                }

                // remove outgoing element
                if (!q.empty() && q.front() == arr[i]) {
                    q.pop();
                }
                
                i++;
            j++;
            }
            
            
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
    vector<int> result=firstNegInt(arr,k);
    for(int val:result)
    {
        cout<<val<<" ";
    }
}