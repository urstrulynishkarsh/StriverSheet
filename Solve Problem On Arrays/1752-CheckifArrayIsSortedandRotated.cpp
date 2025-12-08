#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;


bool checkArraySorted(vector<int>& nums) {
    //your code goes here
    int n=nums.size();
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(nums[i]>nums[(i+1)%n])
        {
            count++;
        }
        if(count>1)
        {
            return false;
        }
    }
    return true;
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
    
   

    

    cout<<checkArraySorted(arr);

    return 0;
    
   
}