#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;


int maximumProductSubarray(vector<int>& nums) {
    int prefix=1;
        int suffix=1;
        int maxi=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(suffix==0)
            {
                suffix=1;
            }
            if(prefix==0)
            {
                prefix=1;
            }
            prefix*=nums[i];
            suffix*=nums[n-i-1];
            maxi=max(maxi,max(prefix,suffix));
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

    

    cout<<maximumProductSubarray(arr);

    return 0;
    
   
}