#include<iostream>
#include<vector>
using namespace std;


void Permutations(int index,vector<int> &nums,vector<vector<int> > &result)
{
    if(index>=nums.size())
    {
        result.push_back(nums);
        return;
    }
    unordered_map<int,bool> visited;
    for(int j=index;j<nums.size();j++)
    {
        if(visited.find(nums[j])!=visited.end())
        {
            continue;
        }
        visited[nums[j]]=true;
        swap(nums[j],nums[index]);
        Permutations(index+1,nums,result);
        swap(nums[j],nums[index]);
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
    
    vector<vector<int> > result;
    Permutations(0,nums,result);

     for (int i = 0; i < result.size(); i++) {   
    cout << "{ ";
    for (int j = 0; j < result[i].size(); j++) {
        cout << result[i][j] << " ";
    }
    cout << "}\n";
    }

}