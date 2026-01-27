#include<iostream>
#include<string.h>
#include<string>
using namespace std;

string addStrings(string num1, string num2) {
        int n=num1.size();
        int m=num2.size();
        int i=n-1;
        int j=m-1;
        string ans;
        int carry=0;
        while(i>=0 || j>=0 ||carry)
        {
            int sum=carry;
            if(i>=0)
            {
                sum+=num1[i--]-'0';
            }
            if(j>=0)
            {
                sum+=num2[j--]-'0';
            }
            ans+=sum%10+'0';
            carry=sum/10;
        }
        reverse(ans.begin(),ans.end());
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




    cout<<addStrings(s,t);
}