#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;


int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int sum=0;
        int start=0;
        int resfreq=0;
        for(int end=0;end<nums.size();end++)
        {
            sum+=nums[end];
            while((end-start+1)*nums[end]-sum>k)
            {
                sum-=nums[start];
                start++;
            }
            resfreq=max(resfreq,end-start+1);
        } 
        return resfreq;
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
    cout<<"Enter the value of K: ";
    cin>>k;

    cout<<maxFrequency(arr,k);

    return 0;
    
   
}