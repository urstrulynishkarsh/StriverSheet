#include<iostream>
using namespace std;

int GCD(int a, int b)
    {
        while(a>0 && b>0)
        {
            if(a>b)
            {
                a=a-b;
            }
            else{
                b=b-a;
            }
        }
        return a>b?a:b;
    }
    int findGCD(vector<int>& nums) {
        // max element
        int maxi=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]>maxi)
            {
                maxi=nums[i];
            }
        }

        // min element
        int mini=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(nums[i]<mini)
            {
                mini=nums[i];
            }
        }

        return GCD(mini,maxi);

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

    cout<<findGCD(arr);
    
}