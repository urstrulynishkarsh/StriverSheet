#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

int maxProfit(vector<int>& prices) {
    int maxprofit=0;
    int minprice=prices[0];
    for(int i=1;i<prices.size();i++)
    {
        int profit=prices[i]-minprice;
        maxprofit=max(maxprofit,profit);
        minprice=min(minprice,prices[i]);
    }
    return maxprofit;
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