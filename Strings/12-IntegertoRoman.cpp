#include<iostream>
#include<unordered_map>
#include<string.h>
using namespace std;

string IntToRoman(int n)
{
    vector<pair<int,string> >vec{
        {1000,"M"},
        {900,"CM"},
        {500,"D"},
        {400,"CD"},
        {100,"C"},
        {90,"XC"},
        {50,"L"},
        {40,"XL"},
        {10,"X"},
        {9,"IX"},
        {5,"V"},
        {4,"IV"},
        {1,"I"}
    };

    string ans;
    for(auto &p:vec)
    {
        while(n>=p.first)
        {
            n-=p.first;
            ans+=p.second;
        }
    }
    return ans;

    
}
int main()
{
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    

    cout<<IntToRoman(n);

}