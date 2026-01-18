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
    int maxiProfit=0;
    int minprice=nums[0];
    for(int i=1;i<nums.size();i++)
    {
        int diff=nums[i]-minprice;
        maxiProfit=max(maxiProfit,diff);
        minprice=min(minprice,nums[i]);
    }
    return maxiProfit;
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