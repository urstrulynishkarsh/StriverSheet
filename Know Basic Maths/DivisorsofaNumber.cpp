#include<iostream>
using namespace std;

vector<int> divisorNumber(int n)
{
    vector<int> answer;
    for(int i=1;i<=n;i++)
    {
        if(n%i==0)
        {
            answer.push_back(i);
        }
    }
    return answer;
}
int main()
{
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    vector<int> result=divisorNumber(n);
    bool track = false;
    for (int val : result)
    {
        if (track)
            cout << ",";
        cout << val;
        track = true;
    }
}