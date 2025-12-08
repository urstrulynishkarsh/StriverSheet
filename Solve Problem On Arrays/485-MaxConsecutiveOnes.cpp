#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int maxi=0;
    int count=0;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]==1)
        {
            count++;
        }
        else{
            maxi=max(maxi,count);
            count=0;
        }
    }
    return max(count,maxi);
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

    

    cout<<findMaxConsecutiveOnes(arr);

    return 0;
    
   
}