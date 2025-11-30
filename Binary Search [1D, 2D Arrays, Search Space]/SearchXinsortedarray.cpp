#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;


int SearchX(vector<int> &arr,int k)
{
    int s=0;
    int e=arr.size()-1;
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        if(arr[mid]==k)
        {
            return mid;
        }
        else if(arr[mid]<k)
        {
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return -1;
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

    int k;
    cout<<"Enter the value of X: ";
    cin>>k;

    cout<<SearchX(arr,k);

    return 0;
    
   
}