#include<iostream>
using namespace std;

bool armstrongNumber(int n)
{
    int x=n;
    int cubeSum=0;

    int count=0;
    int temp=n;
    while(temp>0)
    {
        count++;
        temp/=10;
    }
    while(n>0)
    {
       int digit=n%10;
       cubeSum+=pow(digit,count);
       n/=10;
    }
    if(cubeSum==x)
    {
        return true;
    }
    return false;
}
int main()
{
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    cout<<armstrongNumber(n);
}