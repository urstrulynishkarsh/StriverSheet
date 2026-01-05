#include<iostream>
using namespace std;
bool checkkbit(int &n, int &k)
{
    if(n&(1<<k))
    {
        return true;
    }
    return false;
}
int main()
{  
    int n,k;
    cout<<"Enter the value of n and k: ";
    cin>>n>>k;

    cout<<checkkbit(n,k);
    

    return 0;
}