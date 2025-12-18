#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

void merge(vector<int> &nums, int s, int e)
{
    int mid=(s+e)>>1;
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
        if(nums1[leftindex]<nums2[rightindex])
        {
            nums[mainindex++]=nums1[leftindex++];
        }
        else{
            nums[mainindex++]=nums2[rightindex++];
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

}

int mergecount(vector<int> &nums, int s,int mid, int e)
{
    int count=0;
    int right=mid+1;
    for(int i=s;i<=mid;i++)
    {
        while(right<=e && (long long)nums[i]>2LL*nums[right])
        {
            right++;
        }
        count+=(right-(mid+1));
    }
    return count;
}
int mergesort(vector<int> &nums, int s, int e)
{
    int count=0;
    if(s>=e)
    {
        return 0;
    }
    int mid=(s+e)>>1;
    count+=mergesort(nums,s,mid);
    count+=mergesort(nums,mid+1,e);
    count+=mergecount(nums,s,mid,e);
    merge(nums,s,e);
    return count;

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

    cout<<mergesort(arr,s,e);

    return 0;
    
   
}