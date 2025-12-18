#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i=m-1;
    int j=n-1;
    int k=n+m-1;
    while(j>=0 && i>=0)
    {
        if(nums1[i]>nums2[j])
        {
            nums1[k--]=nums1[i--];
        }
        else{
            nums1[k--]=nums2[j--];
        }
    }
    while(j>=0)
    {
        nums1[k--]=nums2[j--];
    }
}

int main()
{
    int m;
    cout<<"Enter the m size: ";
    cin>>m;

    int n;
    cout<<"Enter the n size: ";
    cin>>n;

    int totalsize=n+m;
    vector<int> nums1(totalsize);
    cout<<"Enter the element in the first array: ";
    for(int i=0;i<m;i++)
    {
        cin>>nums1[i];
    }
    for(int i=m;i<totalsize;i++)
    {
        nums1[i]=0;
    }
    vector<int> nums2(n);
    cout<<"Enter the element in the second array: ";
    for(int i=0;i<n;i++)
    {
        cin>>nums2[i];
    }
    merge(nums1,m,nums2,n);

    for(int i=0;i<totalsize;i++)
    {
        cout<<nums1[i]<<" ";
    }
    

}