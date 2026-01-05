#include<iostream>
using namespace std;
bool checkpower2(int &n)
{
    if(n==1)
    {
        return true;
    }
    if(n<2)
    {
        return false;
    }
    if((n&(n-1))==0)
    {
        return true;
    }
    return false;
}
int main()
{  
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;

    cout<<checkpower2(n);
    

    return 0;
}