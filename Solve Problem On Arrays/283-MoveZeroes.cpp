#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;


void moveZero(vector<int>& nums) {
    //your code goes here
    int j=0;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]!=0)
        {
            int temp=nums[i];
            nums[i]=nums[j];
            nums[j]=temp;
            j++;
        }
    }
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
    
   

    

    moveZero(arr);
    for(int val:arr)
    {
        cout<<val<<" ";
    }


    return 0;
    
   
}