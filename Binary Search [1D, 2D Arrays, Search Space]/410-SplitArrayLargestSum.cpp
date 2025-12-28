#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<numeric>
using namespace std;

bool possibleSolution(vector<int> &pages, int M, int mid)
{
    int pagesum=0;
    int c=1;
    for(int i=0;i<pages.size();i++)
    {
        if(pages[i]>mid)
        {
            return false;
        }
        if(pages[i]+pagesum>mid)
        {
            c++;
            pagesum=pages[i];
            if(c>M)
            {
                return false;
            }
        }
        else{
            pagesum+=pages[i];
        }
    }
    return true;
}
int splitArray(vector<int> &pages, int M, int n)
{
    if(M>n)
    {
        return -1;
    }
    int s=0;
    int e=accumulate(pages.begin(),pages.end(),0);
    int ans=-1;
    while(s<=e)
    {
        int mid=(s+e)>>1;
        if(possibleSolution(pages,M,mid))
        {
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return ans;

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

    int M;
    cout<<"Enter the value of m: ";
    cin>>M;


    cout<<splitArray(arr,M,n);




}