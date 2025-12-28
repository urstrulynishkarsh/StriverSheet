#include<iostream>
#include<vector>
using namespace std;

int NthRoot(int N, int M) {
    int s=0;
    int e=M;
    while(s<=e)
    {
       long long  mid=(s+e)>>1;
       if(pow(mid,N)==M)
       {
           return mid;
       }
       else if(pow(mid,N)<M)
       {
           s=mid+1;
       }
       else{
         e=mid-1;
       }
    }
    return -1;
 }
int main()
{
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    int m;
    cout<<"Enter the value of m: ";
    cin>>m;

    cout<<NthRoot(n,m);

  

}