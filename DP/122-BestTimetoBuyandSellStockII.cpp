#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<climits>
#include<numeric>
using namespace std;



int maxProfit(vector<int> nums)
{
    int n=nums.size();
    int maxiprofit=0;
    int minPrice=nums[0];
    for(int i=1;i<n;i++)
    {
        if(nums[i]>minPrice)
        {
            maxiprofit+=nums[i]-minPrice;
            minPrice=nums[i];
        }
        minPrice=min(minPrice,nums[i]);
    }
    return maxiprofit;
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
    
    

    cout<<maxProfit(arr);
   

    return 0;
    
   
}