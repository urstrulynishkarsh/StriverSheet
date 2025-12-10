#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;


int maxSubArray(vector<int>& nums) {
    int sum=0;
    int maxi=INT_MIN;
    for(int i=0;i<nums.size();i++)
    {
        sum+=nums[i];
        maxi=max(sum,maxi);
        if(sum<0)
        {
            sum=0;
        }
    }
    return maxi;
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