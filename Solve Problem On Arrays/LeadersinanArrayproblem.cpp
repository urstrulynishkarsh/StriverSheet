#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

vector<int> leadersArray(vector<int> &nums)
{
    vector<int> result;
    int n=nums.size();
    result.push_back(nums[n-1]);
    int maxi=nums[n-1];
    for(int i=n-2;i>=0;i--)
    {
        if(nums[i]>=maxi)
        {
            result.push_back(nums[i]);
            maxi=nums[i];
        }
    }
    reverse(result.begin(),result.end());
    return result;
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

    

    vector<int> result=leadersArray(arr);

    for(int val:result)
    {
        cout<<val<<" ";
    }

    return 0;
    

    return 0;
    
   
}