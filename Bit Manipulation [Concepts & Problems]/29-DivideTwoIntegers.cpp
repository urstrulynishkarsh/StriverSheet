#include<iostream>
using namespace std;

int divideTwoNumber(int dividend, int divisor)
{
    if(dividend==INT_MIN && divisor==-1)
    {
        return INT_MAX;
    }
    int sign=((dividend<0)^(divisor<0))?-1:1;
    long long int n=abs((long long int)dividend);
    long long int d=abs((long long int)divisor);
    long long int ans=0;

    while(n>=d)
    {
        int count=0;
        while(n>=d<<(count+1))
        {
            count++;
        }
        ans+=(1<<count);
        n-=(d<<count);
    }
    return ans*sign;
}
int main()
{  
    int dividend,divisor;
    cout<<"Enter the value of dividend and divisor: ";
    cin>>dividend>>divisor;

    cout<<divideTwoNumber(dividend,divisor);

   
}