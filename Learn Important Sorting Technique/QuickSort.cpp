#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;


void QuickSort(vector<int> &arr, int low, int high)
{
    if(low>=high)
    {
        return;
    }
    int j=low;
    int i=low-1;
    int pivot=high;

    while(j<pivot)
    {
        if(arr[j]<arr[pivot])
        {
            i++;
            swap(arr[i],arr[j]);
        }
        j++;
    }
    i++;
    swap(arr[i],arr[pivot]);
    QuickSort(arr,low,i-1);
    QuickSort(arr,i+1,high);
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
    
    QuickSort(arr,s,e);

    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
    
   
}