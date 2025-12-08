#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;


void rotateArrayByOne(vector<int>& nums) {
    int val=nums[0];
    for(int i=0;i<nums.size()-1;i++)
    {
        nums[i]=nums[i+1];
    }
    nums[nums.size()-1]=val;
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

    

    rotateArrayByOne(arr);
    for(int val:arr)
    {
        cout<<val<<" ";
    }

    return 0;
    
   
}