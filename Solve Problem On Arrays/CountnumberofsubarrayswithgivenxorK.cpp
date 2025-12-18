#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

int subarraysWithXorK(vector<int> &nums, int k) {
    unordered_map<int,int> hashmap;
    int count=0;
    int xr=0;
    hashmap[0]=1;
    for(int i=0;i<nums.size();i++)
    {
        xr^=nums[i];
        int need=xr^k;
        count+=hashmap[need];
        hashmap[xr]++;
    }
    return count;
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
    int  k;
    cout<<"Enter the k value: ";
    cin>>k;
    
    cout<<subarraysWithXorK(arr,k);

    return 0;
    
   
}