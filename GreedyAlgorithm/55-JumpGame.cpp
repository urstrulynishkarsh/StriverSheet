#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

bool canjump(vector<int>& nums) {
    int maxindex=0;
    for(int i=0;i<nums.size();i++)
    {
        if(i>maxindex)
        {
            return false;
        }
        maxindex=max(maxindex,nums[i]+i);
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

    

    cout<<canjump(arr);

    return 0;
    
   
}