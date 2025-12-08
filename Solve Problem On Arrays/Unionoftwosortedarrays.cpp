#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;


vector<int> unionArray(vector<int>& arr1, vector<int> &arr2)
{
    int n=arr1.size();
    int m=arr2.size();
    int i=0;
    int j=0;
    vector<int> ans;
    while(i<n && j<m)
    {
        if(arr1[i]<=arr2[j]){

        
            if(ans.size()==0 || ans.back()!=arr1[i])
            {
            ans.push_back(arr1[i]);
            }
            i++;
        }
        else{
            if(ans.size()==0 || ans.back()!=arr2[j])
            {
            ans.push_back(arr2[j]);
            }
            j++;
        }
    }
    while(i<n)
    {
        if(ans.size()==0 || ans.back()!=arr1[i])
        {
        ans.push_back(arr1[i]);
        }
        i++;
    }
    while (j<m)
    {
        /* code */
        if(ans.size()==0 || ans.back()!=arr2[j])
            {
            ans.push_back(arr2[j]);
            }
            j++;
    }

    return ans;
    
     
       
}

int main()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    vector<int> arr1(n);
    cout<<"Enter the element in the array: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr1[i];
    }

    int m;
    cout<<"Enter the size of array: ";
    cin>>m;
    vector<int> arr2(m);
    cout<<"Enter the element in the array: ";
    for(int i=0;i<m;i++)
    {
        cin>>arr2[i];
    }

    

    vector<int> result=unionArray(arr1,arr2);
    for(int val:result)
    {
        cout<<val<<" ";
    }

    return 0;
    
   
}