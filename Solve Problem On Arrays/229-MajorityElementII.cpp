#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

vector<int>  MajorityElementII(vector<int>& nums) {
    int candidate1=0;
    int candidate2=0;
    int count1=0;
    int count2=0;
    int n=nums.size();
    for(int val:nums)
    {
        if(val==candidate1)
        {
            count1++;
        }
        else if(val==candidate2)
        {
            count2++;
        }
        else if(count1==0)
        {
            candidate1=val;
            count1++;
        }
        else if(count2==0)
        {
            candidate2=val;
            count2++;
        }
        else{
            count1--;
            count2--;
        }
    }
    count1=0;
    count2=0;
    for(int val:nums)
    {
        if(val==candidate1)
        {
            count1++;
        }
        else if(val==candidate2)
        {
            count2++;
        }
    }
    vector<int> res;
    if(count1>n/3)
    {
        res.push_back(candidate1);
    }
    if(count2>n/3){
        res.push_back(candidate2);
    }
    return res;

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

    

    vector<int> result=MajorityElementII(arr);

    for(int val:result)
    {
        cout<<val<<" ";
    }

    return 0;
    
   
}