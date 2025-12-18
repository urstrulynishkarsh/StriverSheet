#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

int merge(vector<int> &nums, int s , int mid, int e)
{
    int inversion=0;
    int len1=mid-s+1;
    int len2=e-mid;

    vector<int> nums1(len1);
    vector<int> nums2(len2);

    int k=s;
    for(int i=0;i<len1;i++)
    {
        nums1[i]=nums[k++];
    }
    k=mid+1;
    for(int i=0;i<len2;i++)
    {
        nums2[i]=nums[k++];
    }

    int mainindex=s;
    int leftindex=0;
    int rightindex=0;

    while(leftindex<len1 && rightindex<len2)
    {
        if(nums1[leftindex]<=nums2[rightindex])
        {
            nums[mainindex++]=nums1[leftindex++];
        }
        else{
            nums[mainindex++]=nums2[rightindex++];
            // this is the main line don't forget
            inversion+=(len1-leftindex);
        }
    }
    while(leftindex<len1)
    {
        nums[mainindex++]=nums1[leftindex++];
    }
    while(rightindex<len2)
    {
        nums[mainindex++]=nums2[rightindex++];
    }
    return inversion;
    
}
int mergeSort(vector<int> &nums, int s, int e)
{
    int inversion=0;
    if(s<e)
    {
        int mid=s+(e-s)/2;
        inversion+=mergeSort(nums,s,mid);
        inversion+=mergeSort(nums,mid+1,e);
        inversion+=merge(nums,s,mid,e);
    }
    return inversion;
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

    int s=0;
    int e=n-1;

    cout<<mergeSort(arr,s,e);

    return 0;
    
   
}