#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, int n, vector<int>& nums2, int m)
{
    if(n>m)
    {
        return findMedianSortedArrays(nums2,m,nums1,n);
    }
    int s=0;
    int e=n;
    int totalsize=n+m;
    int left=(n+m+1)/2;
    while(s<=e)
    {
        int mid1=(s+e)>>1;
        int mid2=left-mid1;

        int l1=INT_MIN;
        int l2=INT_MIN;

        int r1=INT_MAX;
        int r2=INT_MAX;

        if(mid1<n)
        {
            r1=nums1[mid1];
        }

        if(mid2<m)
        {
            r2=nums2[mid2];
        }

        if(mid1-1>=0)
        {
            l1=nums1[mid1-1];
        }
        
        if(mid2-1>=0)
        {
            l2=nums2[mid2-1];
        }

        if(l1<=r2 && l2<=r1)
        {
            if(totalsize&1)
            {
                return max(l1,l2);
            }
            return ((double)max(l1,l2)+min(r1,r2))/2.0;
        }
        if(l1>r2)
        {
            e=mid1-1;
        }
        else{
            s=mid1+1;
        }
    }
    return 0;

}

int main()
{
    int n;
    cout<<"Enter the size of first array: ";
    cin>>n;
    vector<int> nums1(n);
    cout<<"Enter the element in the first array: ";
    for(int i=0;i<n;i++)
    {
        cin>>nums1[i];
    }

    int m;
    cout<<"Enter the size of second array: ";
    cin>>m;

     vector<int> nums2(m);
    cout<<"Enter the element in the second array: ";
    for(int i=0;i<m;i++)
    {
        cin>>nums2[i];
    }

    cout<<findMedianSortedArrays(nums1,n,nums2,m);

    return 0;
    
   
}