#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<climits>
#include<numeric>
using namespace std;



int maxProfit(vector<int> nums)
{
    int release1=0;
    int hold1=INT_MIN;
    int release2=0;
    int hold2=INT_MIN;
    for(int i:nums)
    {
        hold1=max(hold1,-i);
        release1=max(release1,hold1+i);
        release2=max(release2,hold2+i);
            hold2=max(hold2,release1-i);
    }
    return release2;
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
    
    

    cout<<maxProfit(arr);
   

    return 0;
    
   
}