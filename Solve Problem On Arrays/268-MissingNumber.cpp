#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;


int missingNumber(vector<int>& nums) {
    int n=nums.size();
    int totalsize=(n*(n+1))/2;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=nums[i];
    }
    return totalsize-sum;
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

    

    cout<<missingNumber(arr);

    return 0;
    
   
}