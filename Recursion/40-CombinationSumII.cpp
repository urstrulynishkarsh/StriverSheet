#include<iostream>
#include<vector>
using namespace std;


void solveRecursion(int index,vector<int>& candidates, int target,vector<vector<int>> &result,vector<int> ans)
    {
        if(target<0)
        {
            return;
        }
        if(target==0)
        {
            result.push_back(ans);
            return;
        }
        for(int i=index;i<candidates.size();i++)
        {
            if(i>index && candidates[i]==candidates[i-1])
            {
                continue;
            }
            ans.push_back(candidates[i]);
            solveRecursion(i+1,candidates,target-candidates[i],result,ans);
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

    sort(nums.begin(),nums.end());
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