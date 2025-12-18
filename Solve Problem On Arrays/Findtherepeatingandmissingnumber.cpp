#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;


vector<int> findMissingRepeatingNumbers(vector<int> nums) {
    int n=nums.size();
    long long total = (1LL * n * (n + 1)) / 2;
    unordered_map<int, int> hashmap;
    vector<int> result;
    int x=-1;
    for(int val:nums)
    {
        hashmap[val]++;
    }
    for(auto it:hashmap)
    {
        if(it.second>1)
        {
            x=it.first;
            result.push_back(x);
            break;
        }
    }
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=nums[i];
    }
    sum=sum-x;
    int missing=total-sum;
    result.push_back(missing);
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

    

    vector<int> result=findMissingRepeatingNumbers(arr);
    for(int val:result)
    {
        cout<<val<<" ";
    }

    return 0;
    
   
}