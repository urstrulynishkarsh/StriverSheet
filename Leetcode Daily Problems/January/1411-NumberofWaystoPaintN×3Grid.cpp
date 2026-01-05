#include<iostream>
using namespace std;
 int numOfWays(int n) {
        long long int color3=6;
        long long int color2=6;
        long long int MOD=1e9+7;
        for(int i=2;i<=n;i++)
        {
            long long int temp=color3;
            color3=((2*color3)+(2*color2))%MOD;
            color2=((2*temp)+(3*color2))%MOD;
        }
        return (color2+color3)%MOD;
    }
int main()
{  
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;

    cout<<numOfWays(n);
    

    return 0;
}