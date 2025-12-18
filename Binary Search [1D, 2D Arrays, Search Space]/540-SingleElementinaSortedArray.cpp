#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;


int singleNonDuplicate(vector<int>& nums) {
    int n=nums.size();
    int s=0;
    int e=n-1;
    while(s<=e)
    {
        int mid=(s+e)>>1;
        if(s==e)
        {
            return nums[mid];
        }

        int currentvalue=nums[mid];
        int leftvalue=-1;
        if(mid-1>=0)
        {
            leftvalue=nums[mid-1];
        }
        int rightvalue=-1;
        if(mid+1<n)
        {
            rightvalue=nums[mid+1];
        }

        if(currentvalue!=leftvalue && currentvalue!=rightvalue)
        {
            return currentvalue;
        }

        if(currentvalue==leftvalue && currentvalue!=rightvalue)
        {
            int pairstartingindex=mid-1;
            if(pairstartingindex&1)
            {
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }

        if(currentvalue!=leftvalue && currentvalue==rightvalue)
        {
            int pairstartingindex=mid+1;
            if(pairstartingindex&1)
            {
                s=mid+1;
            }
            else{
                
                e=mid-1;
            }
        }


    }
    return -1;
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

   

    cout<<singleNonDuplicate(arr);

    return 0;
    
   
}