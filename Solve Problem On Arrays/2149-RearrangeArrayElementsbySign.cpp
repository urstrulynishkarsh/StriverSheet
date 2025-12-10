#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

vector<int> rearrangeArray(vector<int>& nums) {
    int n=nums.size();
    vector<int> result(n,0);
    int pos=0;
    int neg=1;
    for(int i=0;i<n;i++)
    {
        if(nums[i]>=0)
        {
            result[pos]=nums[i];
            pos=pos+2;
        }
        else{
            result[neg]=nums[i];
            neg=neg+2;
        }
    }
    return result;
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

    

    vector<int> ans=rearrangeArray(arr);

    for(int val:ans)
    {
        cout<<val<<" ";
    }

    return 0;
    
   
}