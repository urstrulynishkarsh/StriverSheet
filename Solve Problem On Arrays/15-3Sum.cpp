#include<iostream>
#include<vector>
#include<set>
using namespace std;

void  threesum(vector<int> &arr, vector<vector<int> > &result)
{
    sort(arr.begin(),arr.end());
    int n=arr.size();
    set<vector<int> >st;
    for(int i=0;i<n;i++)
    {
        if(i>0 && arr[i]==arr[i-1])
        {
            continue;
        }
        set<int> hashset;
        for(int j=i+1;j<n;j++)
        {
            int third=-(arr[i]+arr[j]);
            if(hashset.find(third)!=hashset.end())
            {
                st.insert({arr[i],third,arr[j]});
            }
            hashset.insert(arr[j]);
        }
        result.assign(st.begin(),st.end());
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

   
    threesum(arr,result);

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