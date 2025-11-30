#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;


void selectionSort(vector<int> &arr)
{
    int n=arr.size();
    for(int i=0;i<n-1;i++)
    {
        int minIndex=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[minIndex])
            {
                minIndex=j;
            }
        }
        swap(arr[i],arr[minIndex]);
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

    

    selectionSort(arr);

    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
    
   
}