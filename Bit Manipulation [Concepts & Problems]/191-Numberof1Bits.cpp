#include<iostream>
using namespace std;
int hammingWeight(int n) {
        string res;
        while(n!=0)
        {
            if(n%2==1)
            {
                res+='1';
            }
            else{
                res+='0';
            }
            n/=2;
        }
        int count=0;
        for(int i=0;i<res.length();i++)
        {
            if(res[i]=='1')
            {
                count++;
            }
        }
        return count;
    }
int main()
{  
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;

    cout<<hammingWeight(n);
    

    return 0;
}