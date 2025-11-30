#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;


void bubbleSort(vector<int> &arr)
{
    int n=arr.size();
    for(int i=0;i<n-1;i++)
    {
        bool flag=false;
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                flag=true;
                swap(arr[j],arr[j+1]);
            }
        }
        if(flag==false)
        {
            break;
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

    

    bubbleSort(arr);

    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
    
   
}