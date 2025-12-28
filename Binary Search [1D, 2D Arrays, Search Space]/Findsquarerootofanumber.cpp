#include<iostream>
#include<vector>
using namespace std;

int floorSqrt(int n)  {
    int s=0;
    int e=n;
    int ans=-1;
    while(s<=e)
    {
        long long mid=(s+e)>>1;
        if(mid*mid==n)
        {
            return mid;
        }
        else if(mid*mid<n)
        {
            ans=mid;
            s=mid+1;
        }
        else if(mid*mid>n)
        {
            e=mid-1;
        }
    }
    return ans;
}
int main()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    cout<<floorSqrt(n);

  

}