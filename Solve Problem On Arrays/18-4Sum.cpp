#include<iostream>
#include<vector>
#include<set>
using namespace std;

void  foursum(vector<int> &nums, vector<vector<int> > &result, int &target)
{
    sort(nums.begin(),nums.end());
    int n=nums.size();
    for(int i=0;i<n;i++)
    {
        if(i>0 && nums[i]==nums[i-1])
        {
            continue;
        }
        for(int j=i+1;j<n;j++)
        {
            if(j>i+1 && nums[j]==nums[j-1])
            {
                continue;
            }
            int k=j+1;
            int l=nums.size()-1;
            while(k<l)
            {
                long long sum=(long long)nums[i]+nums[j]+nums[k]+nums[l];
                if(sum<target)
                {
                    k++;
                }
                else if(sum>target)
                {
                    l--;
                }
                else{
                    result.push_back({nums[i],nums[j],nums[k],nums[l]});
                    k++;
                    l--;
                    while(k<l && nums[k]==nums[k-1])
                    {
                        k++;
                    }
                    while(k<l && nums[l]==nums[l+1])
                    {
                        l--;
                    }
                }
            }
        }
    }
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

    vector<vector<int> > result;
    int target;
    cout<<"Enter the target value: ";
    cin>>target;
   
    foursum(arr,result,target);

    cout<<"[";
    for(auto arr:result)
    {
        cout<<"[";
        for(int val:arr)
        {
            cout<<val<<",";
        }
        cout<<"],";
    }
    cout<<"]";

}