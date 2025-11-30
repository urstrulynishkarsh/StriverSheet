#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;


int lowerBound(vector<int> &arr,int k)
{
    int s=0;
    int e=arr.size()-1;
    int ans=-1;
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        if(arr[mid]==k)
        {
            ans=mid;
            e=mid-1;

        }
        else if(arr[mid]<k)
        {
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return ans;
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

    cout<<lowerBound(arr,k);

    return 0;
    
   
}