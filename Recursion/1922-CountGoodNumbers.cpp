#include<iostream>
using namespace std;
const int MOD=1e9+7;
    long long power(long long a, long long b)
    {
        long long res=1;
        while(b)
        {
            if(b&1)
            {
                res=(res*a)%MOD;
            }
            a=(a*a)%MOD;
            b/=2;
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        long long odd=n/2;
        long long even=n-(n/2);
        long long totalcombination=power(4,odd)*power(5,even);
        return totalcombination%MOD;

    }

int main()
{
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    cout<<countGoodNumbers(n);
}