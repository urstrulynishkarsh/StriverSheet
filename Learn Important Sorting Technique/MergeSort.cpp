#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

void Merge(vector<int> &arr, int s, int e)
{
    int mid=s+(e-s)/2;
    int len1=mid-s+1;
    int len2=e-mid;
    vector<int> v1(len1);
    vector<int> v2(len2);

    int k=s;
    for(int i=0;i<len1;i++)
    {
        v1[i]=arr[k++];
    }
    k = mid + 1;
    for(int i=0;i<len2;i++)
    {
        v2[i]=arr[k++];
    }

    int leftindex=0;
    int rightindex=0;
    int mainindex=s;
    while(leftindex<len1 && rightindex<len2)
    {
        if(v1[leftindex]<=v2[rightindex])
        {
            arr[mainindex++]=v1[leftindex++];
        }
        else{
            arr[mainindex++]=v2[rightindex++];
        }
    }
    while(leftindex<len1)
    {
        arr[mainindex++]=v1[leftindex++];
    }
    while(rightindex<len2)
    {
        arr[mainindex++]=v2[rightindex++];
    }
}
void MergeSort(vector<int> &arr, int s, int e)
{

    if(s>=e)
    {
        return;
    }
    int mid=s+(e-s)/2;
    MergeSort(arr,s,mid);
    MergeSort(arr,mid+1,e);
    Merge(arr,s,e);
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
    int e=arr.size()-1;
    

    MergeSort(arr,s,e);

    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
    
   
}