#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;


int findTarget(vector<int>& arr, int target) {
    // code here
    int n=arr.size();
    int s=0;
    int e=n-1;
    
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        if(arr[mid]==target)
        {
            return mid;
        }
        else if(mid-1>=0 && arr[mid-1]==target)
        {
            return mid-1;
        }
        else if (mid+1<n && arr[mid+1]==target)
        {
            return mid+1;
        }
        else if(target>arr[mid]){
            s=mid+2;
        }
        else{
            e=mid-2;
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

   int target;
   cout<<"Enter the target value: ";
   cin>>target;

    cout<<findTarget(arr,target);

    return 0;
    
   
}