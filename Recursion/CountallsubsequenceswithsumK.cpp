#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

 void solveRecursion(vector<int>& nums,int n, int i, int target, int sum, int &count)
    {
        if(n==i)
        {
            if(sum==target)
            {
                count++;
            }
            return;
        }
        solveRecursion(nums,n,i+1,target,sum+nums[i],count);
        solveRecursion(nums,n,i+1,target,sum,count); 
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
    cout<<"Enter the k value: ";
    cin>>k;
    
        int count=0;
        solveRecursion(arr,n,0,k,0,count);
        cout<<count;
        



    
    
   
}