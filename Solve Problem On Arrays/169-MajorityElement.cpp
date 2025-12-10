#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

int MajorityElement(vector<int>& nums) {
    // create variable 
    int i,votes=0,candidate=-1;
    int n=nums.size();
    for(i=0;i<nums.size();i++)
    {
        if(votes==0)
        {
            candidate=nums[i];
            votes=1;
        }
        else{
            if(nums[i]==candidate)
            {
                votes++;
            }
            else{
                votes--;
            }
        }
    }
    int count=0;
    for(i=0;i<n;i++)
    {
        if(nums[i]==candidate)
        {
            count++;
        }
    }
    if(count>n/2)
    {
        return candidate;
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

    

    cout<<MajorityElement(arr);

    return 0;
    
   
}