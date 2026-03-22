#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

int trap(vector<int>& heights)
{
    int n=heights.size();
    vector<int> maxl(n);
    vector<int> maxr(n);
    vector<int> water(n);

    maxl[0]=heights[0];
    maxr[n-1]=heights[n-1];

    for(int i=1;i<n;i++)
    {
        maxl[i]=max(maxl[i-1],heights[i]);
    }

    for(int i=n-2;i>=0;i--)
    {
        maxr[i]=max(maxr[i+1],heights[i]);
    }

    for(int i=0;i<n;i++)
    {
        water[i]=min(maxl[i],maxr[i])-heights[i];
    }

    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=water[i];
    }
    return sum;

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
    

    

    cout<<trap(arr);

    return 0;
    
   
}