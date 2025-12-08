#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;


int linearSearch(vector<int>& nums, int target) {
    //your code goes here
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]==target)
        {
            return i;
        }
    }
    return -1;
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
    int target;
    cout<<"Enter the target value: ";
    cin>>target;

    

    cout<<linearSearch(arr,target);

    return 0;
    
   
}