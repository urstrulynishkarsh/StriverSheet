#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        int j=0;
        int zero=0;
        int maxi=INT_MIN;
        while(j<n)
        {
            // calculation
            if(nums[j]==0)
            {
                zero++;
            }
            // shrink window
            while(zero>k)
            {
                if(nums[i]==0)
                {
                    zero--;
                }
                i++;
            }
            maxi=max(maxi,j-i+1);
            j++;
        }
        return maxi;
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
    cout<<longestOnes(arr,k);
}