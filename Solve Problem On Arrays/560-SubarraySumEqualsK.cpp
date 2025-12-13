#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int subarraySum(vector<int> &nums, int k)
{
    unordered_map<int,int> hashmap;
    // forget this
    hashmap[0]=1;
    int prefix=0;
    int count=0;
    for(int i=0;i<nums.size();i++)
    {
        prefix+=nums[i];
        if(hashmap.find(prefix-k)!=hashmap.end())
        {   
            count+=hashmap[prefix-k];
        }
        hashmap[prefix]++;
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
    int k;
    cout<<"Enter the value of k: ";
    cin>>k;
    cout<<subarraySum(arr,k);
}