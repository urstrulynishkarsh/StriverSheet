#include<iostream>
using namespace std;
bool checkodd(int &n)
{
    if(n&1)
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

    cout<<checkodd(n);
    

    return 0;
}