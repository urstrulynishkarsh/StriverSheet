#include<iostream>
#include<string.h>
using namespace std;

string customSortString(string &order,string &s)
{
    sort(s.begin(),s.end(),[&](char a, char b){
        return order.find(a)<order.find(b);
    });
    return s;
}
int main()
{
    string order;
    cout<<"Enter the order string: ";
    getline(cin,order);

    string s;
    cout<<"Enter the S string: ";
    getline(cin,s);




    cout<<customSortString(order,s);
}