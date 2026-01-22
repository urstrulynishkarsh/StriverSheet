#include<iostream>
using namespace std;


double pow(double x, int n)
{
    long long m=n;
    double ans=1.0;

    if(m<0)
    {
        x=1.0/x;
        m=-m;
    }
    while(m>0)
    {
        if(m&1)
        {
            ans*=x;
            m=m-1;
        }
        else{
            x=x*x;
            m/=2;
        }
    }
    return ans;
}

int main()
{
    double x;
    cout<<"Enter the value of x: ";
    cin>>x;

    int n;
    cout<<"Enter the value of n: ";
    cin>>n;

    cout<<pow(x,n);
}
