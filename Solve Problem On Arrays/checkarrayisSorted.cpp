#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;


bool checkArrayIsSorted(vector<int> &nums)
{
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]>nums[i+1])
            {
                return false;
            }
        }
        return true;
       
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

    

    cout<<checkArrayIsSorted(arr);

    return 0;
    
   
}