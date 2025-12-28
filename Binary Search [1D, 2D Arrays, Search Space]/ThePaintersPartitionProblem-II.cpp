#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<numeric>
using namespace std;

bool possibleSolution(vector<int>& arr, int k, int mid)
    {
        int paintime=0;
        int c=1;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]>mid)
            {
                return false;
            }
            if(arr[i]+paintime>mid)
            {
                c++;
                paintime=arr[i];
                if(c>k)
                {
                    return false;
                }
            }
            else{
                paintime+=arr[i];
            }
        }
        return true;
    }
    int minTime(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        if(k>n)
        {
            return -1;
        }
        int s=0;
        int e=accumulate(arr.begin(),arr.end(),0);
        int ans=-1;
        while(s<=e)
        {
            int mid=(s+e)>>1;
            if(possibleSolution(arr,k,mid))
            {
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
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

    int M;
    cout<<"Enter the value of m: ";
    cin>>M;


    cout<<minTime(arr,M);




}