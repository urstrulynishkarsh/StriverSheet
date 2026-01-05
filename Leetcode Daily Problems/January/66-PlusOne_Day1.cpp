#include<iostream>
#include<vector>
using namespace std;

vector<int> plusone(vector<int> &nums)
{
    int n=nums.size();
    int sum=0;
    int carry=1;
    vector<int> result;
    for(int i=n-1;i>=0;i--)
    {
        sum=nums[i]+carry;
        result.push_back(sum%10);
        carry=sum/10;
    }
    if(carry==1)
    {
        result.push_back(1);
    }
    reverse(result.begin(),result.end());
    return result;
}
int main()
{
    int n;
    cout<<"Enter the size of Array: ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the element in the array: ";
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    vector<int> result=plusone(nums);
    for(int val:result)
    {
        cout<<val<<" ";
    }
}