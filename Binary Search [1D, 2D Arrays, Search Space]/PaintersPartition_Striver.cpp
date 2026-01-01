#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<numeric>
using namespace std;
static const int MOD=10000003;


bool possibleSolution(vector<int> &nums,int A,int mid)
{
    long long int pages=0;
    long long int c=1;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]>mid)
        {
            return false;
        }
        if(nums[i]+pages>mid)
        {
            c++;
            pages=nums[i];
            if(c>A)
            {
                return false;
            }
        }
        else{
            pages+=nums[i];
        }
    }
    return true;

}
int paint(vector<int> &nums,int A, int B)
{
    long long int s=0;
    long long int e=accumulate(nums.begin(),nums.end(),0);
    long long int ans=e;
    while(s<=e)
    {
        long long int mid=s+(e-s)/2;
        if(possibleSolution(nums,A,mid))
        {
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return (ans % MOD * B % MOD) % MOD;
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

    int A;
    cout<<"Enter the value of A: ";
    cin>>A;

    int B;
    cout<<"Enter the value of B: ";
    cin>>B;


    cout<<paint(arr,A,B);




}