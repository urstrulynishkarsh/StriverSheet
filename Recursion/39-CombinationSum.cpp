#include<iostream>
#include<vector>
using namespace std;


void solveRecursion(int index,  vector<int> &nums, int target, vector<vector<int> > &result, vector<int> ans)
{
    if(target==0)
    {
        result.push_back(ans);
        return;
    }
    if(target<0)
    {
        return;
    }
    for(int i=index;i<nums.size();i++)
    {
        ans.push_back(nums[i]);
        solveRecursion(i,nums,target-nums[i],result,ans);
        ans.pop_back();
    }
}
int main()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the element in the array: ";
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    int target;
    cout<<"Enter the target value: ";
    cin>> target;


    vector<vector<int> > result;
    vector<int> ans;

    solveRecursion(0,nums,target,result,ans);



     for (int i = 0; i < result.size(); i++) {   
    cout << "{ ";
    for (int j = 0; j < result[i].size(); j++) {
        cout << result[i][j] << " ";
    }
    cout << "}\n";
    }

}