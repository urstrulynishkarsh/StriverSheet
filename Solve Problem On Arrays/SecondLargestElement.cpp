#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;


int secondLargestElement(vector<int>& nums)
{
    if(nums.size()< 2)
        return -1;
    int firstmaxi=INT_MIN;
    int secondmaxi=INT_MIN;
    for(int i=0;i<nums.size();i++)
    {
        if(firstmaxi<nums[i])
        {
            secondmaxi=firstmaxi;
            firstmaxi=nums[i];
        }
        else if(nums[i]> secondmaxi && nums[i]!=firstmaxi)
        {
            secondmaxi=nums[i];
        }
        
    }
    return secondmaxi;
       
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

    

    cout<<secondLargestElement(arr);

    return 0;
    
   
}