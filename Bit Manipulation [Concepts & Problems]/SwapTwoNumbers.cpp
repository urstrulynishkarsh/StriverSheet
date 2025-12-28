#include<iostream>
using namespace std;
void swap(int &a, int &b) {
    // Your code goes here
    a=a+b;
    b=a-b;
    a=a-b;
}
int main()
{  
    int a,b;
    cout<<"Enter the value of a and b: ";
    cin>>a>>b;

    swap(a,b);

    cout<<"value of a is: "<<a<<endl;
    cout<<"value of b is: "<<b;
}