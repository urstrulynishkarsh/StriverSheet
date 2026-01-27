#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int picktoy(vector<int>& fruits,int k) {
        int i=0;
        int j=0;
        int maxi=1;
        int n=fruits.size();
        unordered_map<int, int> mp;
        while(j<n)
        {
            mp[fruits[j]]++;
            while(mp.size()>k)
            {
                mp[fruits[i]]--;
                if(mp[fruits[i]]==0)
                {
                    mp.erase(fruits[i]);
                }
                i++;
            }
            if(mp.size()<=k)
            {
                maxi=max(maxi,j-i+1); 
            }
            j++;
        }
        return maxi;

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
    int k=2;
    cout<<picktoy(arr,k);
}