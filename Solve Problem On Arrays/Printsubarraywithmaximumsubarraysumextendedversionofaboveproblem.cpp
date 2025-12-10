#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;


int maxSubArray(vector<int>& nums) {
    int maxi=INT_MIN;
    int sum=0;
    int start=0;
    int ansStart=-1;
    int ansEnd=-1;
    for(int i=0;i<nums.size();i++)
    {
        if(sum==0)
        {
            start=i;
        }
        sum+=nums[i];
        if(sum>maxi)
        {
            maxi=sum;
            ansStart=start;
            ansEnd=i;
        }
        if(sum<0)
        {
            sum=0;
        }
    }
    cout<<"The Subarray is: [ ";
    for(int i=ansStart;i<=ansEnd;i++)
    {
        cout<<nums[i]<<" ";
    }
    cout<<"]"<<endl;

    return  maxi;
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

    

    cout<<maxSubArray(arr);

    return 0;
    
   
}