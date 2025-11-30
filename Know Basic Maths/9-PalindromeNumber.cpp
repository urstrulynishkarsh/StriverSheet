#include<iostream>
using namespace std;

bool checkPalindrome(int n)
{
   if(n<0)
   {
        return false;
   }
   int x=n;
   int reversed=0;
   while(n!=0)
   {
        int digit=n%10;
        // this case everyone forget
        if(reversed>INT_MAX/10 || reversed<INT_MIN/10)
        {
            return 0;
        }
        reversed=reversed*10+digit;
        n/=10;
   }
   if(reversed==x)
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
    cout<<checkPalindrome(n);
}