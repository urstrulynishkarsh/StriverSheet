#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

int singleNumber(vector<int>& nums) {
    int ans=0;
    for(int i=0;i<nums.size();i++)
    {
        ans^=nums[i];
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

    

    cout<<singleNumber(arr);

    return 0;
    
   
}