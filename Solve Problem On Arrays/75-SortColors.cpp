#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;


void sortColor(vector<int>& nums) {
    int l=0,m=0,h=nums.size()-1;
    while(m<=h)
    {
        if(nums[m]==0)
        {
            swap(nums[l++],nums[m++]);
        }
        else if(nums[m]==1)
        {
            m++;
        }
        else if(nums[m]==2){
            swap(nums[m],nums[h--]);
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
    
    

    sortColor(arr);
    for(int val:arr)
    {
        cout<<val<<" ";
    }

    return 0;
    
   
}