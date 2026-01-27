#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

 void solveRecursion(vector<int>& arr,int sum, int index,vector<int> &result)
    {
        if(index>=arr.size())
        {
            result.push_back(sum);
            return;
        }
        // include
        solveRecursion(arr,sum+arr[index],index+1,result);
        
        // exclude
        solveRecursion(arr,sum,index+1,result);
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
    
    

    vector<int> ans;

    solveRecursion(arr,0,0,ans);

    cout << "\nAll subsets are:\n";

    for(int val:ans)
    {
        cout<<val<<" ";
    }


    
    
   
}