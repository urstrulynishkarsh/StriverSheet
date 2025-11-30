#include<iostream>
using namespace std;

bool PrimeNumber(int n)
{
    if(n<=1)
    {
        return false;
    }
    for(int i=2;i<n;i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
    
}
int main()
{
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    cout<<PrimeNumber(n);
}