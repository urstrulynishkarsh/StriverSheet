#include<iostream>
#include<string.h>
#include<string>
using namespace std;

string multiplystring(string &s, string &t)
{
   if(s=="0" || t=="0")
   {
        return "0";
   }
   int n=s.size();
   int m=t.size();
   vector<int> res(n+m,0);
   for(int i=n-1;i>=0;i--)
   {
        for(int j=m-1;j>=0;j--)
        {
            res[i+j+1]+=(s[i]-'0')*(t[j]-'0');
            res[i+j]=res[i+j+1]/10;
            res[i+j+1]%=10;
        }
   }
   int i=0;
   string ans;
   while(res[i]==0)
   {
        i++;
   }
   while(i<res.size())
   {
        ans+=(to_string(res[i++]));
   }
   return ans;
}
int main()
{
    string s;
    cout<<"Enter the s string: ";
    getline(cin,s);

    string t;
    cout<<"Enter the t string: ";
    getline(cin,t);




    cout<<multiplystring(s,t);
}