#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;


void rotateArray(vector<int>& nums, int k) {
    int n=nums.size();
    int finalshift=k%n;
    if(finalshift==0)
    {
        return;
    }
    reverse(nums.begin(),nums.end());
    reverse(nums.begin(),nums.begin()+(n-finalshift));
    reverse(nums.begin()+(n-finalshift),nums.end());
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
    

    rotateArray(arr,k);
    for(int val:arr)
    {
        cout<<val<<" ";
    }

    return 0;
    
   
}