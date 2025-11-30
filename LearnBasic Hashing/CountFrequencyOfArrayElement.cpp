#include<iostream>
#include<vector>
#include<map>


using namespace std;

vector<vector<int>> countFrequencies(vector<int>& nums) {
    vector<vector<int>> result;
    map<int,int> hash;
    for(int i=0;i<nums.size();i++)
    {
        hash[nums[i]]++;
    }

    for(auto it:hash)
    {
        result.push_back({it.first,it.second});
    }
    return result;
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

    vector<vector<int>> Frequencies=countFrequencies(arr);
    
    bool visited=false;
    cout<<"[";
    for(auto it:Frequencies)
    {
        if(visited)
        {
            cout<<",";
        }
        cout<<"["<<it[0]<<","<<it[1]<<"]";
        visited=true;
    }
    cout<<"]";
}