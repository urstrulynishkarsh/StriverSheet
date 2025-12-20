#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

void floorValue(vector<int> &nums, int x, int &floorvalue)
{
    int s=0;
    int e=nums.size()-1;
    while(s<=e)
    {
        int mid=(s+e)>>1;
        if(nums[mid]<=x)
        {
            floorvalue=nums[mid];
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
}

void ceilValue(vector<int> &nums, int x, int &ceilvalue)
{
    int s=0;
    int e=nums.size()-1;
    while(s<=e)
    {
        int mid=(s+e)>>1;
        if(nums[mid]>=x)
        {
            ceilvalue=nums[mid];
            e=mid-1;
        }
        else{
            
            s=mid+1;
        }
    }

}
vector<int> getFloorAndCeil(vector<int> &nums, int x) {
    int floorvalue=-1;
    int ceilvalue=-1;
    floorValue(nums,x,floorvalue);
    ceilValue(nums,x,ceilvalue);
    return{floorvalue,ceilvalue};
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

    int x;
    cout<<"Enter the value of X: ";
    cin>>x;



    vector<int> result=getFloorAndCeil(arr,x);
    for(int val:result)
    {
        cout<<val<<" ";
    }
    return 0;
    
   
}