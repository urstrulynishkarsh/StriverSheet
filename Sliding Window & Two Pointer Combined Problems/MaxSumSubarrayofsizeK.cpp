#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        int i=0;
        int j=0;
        long long sum=0;
        long long maxsum=INT_MIN;
        while(j<n)
        {
            sum+=arr[j];
            if(j-i+1<k)
            {
                j++;
            }
            else if(j-i+1==k)
            {
                maxsum=max(maxsum,sum);
                sum-=arr[i];
                i++;
                j++;
            }
        }
        return maxsum;
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
    cout<<"Enter the value of k: ";
    cin>>k;
    cout<<maxSubarraySum(arr,k);
}