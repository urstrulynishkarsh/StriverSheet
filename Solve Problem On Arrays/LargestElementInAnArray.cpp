#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;


int LargestElement(vector<int>& nums)
{
    int maxi=nums[0];
    for(int i=1;i<nums.size();i++)
    {
        if(maxi<nums[i])
        {
            maxi=nums[i];
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

    

    cout<<LargestElement(arr);

    return 0;
    
   
}