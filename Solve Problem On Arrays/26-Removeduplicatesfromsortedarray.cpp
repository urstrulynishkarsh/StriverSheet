#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int i=1;
    int j=0;
    while(i<nums.size())
    {
        if(nums[i]==nums[j])
        {
            i++;
        }
        else{
            nums[++j]=nums[i++];
        }
    }
    return j+1;
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

    cout<<removeDuplicates(arr);

    return 0;
    
   
}