#include<iostream>
#include<vector>
using namespace std;

void generatePermutation(vector<int> &arr, int i, vector<vector<int> > &result)
{
    if(i>=arr.size())
    {
        result.push_back(arr);
        return;
    }
    for(int j=i;j<arr.size();j++)
    {
        swap(arr[i],arr[j]);
        generatePermutation(arr,i+1,result);
        // backtrack
        swap(arr[i],arr[j]);
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

    int i=0;
    generatePermutation(arr,i,result);

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