#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<numeric>
using namespace std;

int calculatedays(vector<int>& weights, int capacity)
{
    int loads=0;
    int c=1;
    for(int i=0;i<weights.size();i++)
    {
        if(weights[i]+loads>capacity)
        {
            c++;
            loads=weights[i];
        }
        else{
            loads+=weights[i];
        }
    }
    return c;
}
int shipWithinDays(vector<int>& weights, int days) {
    int sum=accumulate(weights.begin(),weights.end(),0);
    int maxi=*max_element(weights.begin(),weights.end());
    int s=maxi;
    int e=sum;
    int ans=sum;
    while(s<=e)
    {
        int mid=(s+e)>>1;
        int reqdays=calculatedays(weights,mid);
        if(reqdays<=days)
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

    int d;
    cout<<"Enter the value of days: ";
    cin>>d;


    cout<<shipWithinDays(arr,d);




}