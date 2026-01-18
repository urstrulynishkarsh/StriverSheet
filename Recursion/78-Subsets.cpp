#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;


void solveRecursion(vector<int>& nums, int i, vector<vector<int>> &result,vector<int> ans)
    {
        if(i>=nums.size())
        {
            result.push_back(ans);
            return;
        }
        // include
        ans.push_back(nums[i]);
        solveRecursion(nums,i+1,result,ans);

        // exclude with backtrack
        ans.pop_back();
        solveRecursion(nums,i+1,result,ans);

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
    
    

    vector<vector<int> >result;
    vector<int> ans;

    solveRecursion(arr,0,result,ans);

    cout << "\nAll subsets are:\n";

    for (int i = 0; i < result.size(); i++) {   
    cout << "{ ";
    for (int j = 0; j < result[i].size(); j++) {
        cout << result[i][j] << " ";
    }
    cout << "}\n";
    }


    
    
   
}