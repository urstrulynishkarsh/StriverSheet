#include<iostream>
#include<vector>
using namespace std;


int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // kitne petrol kam pad gaya
        int deficient=0;

        // how much petrol remain
        int balance=0;

        // kaha se start karna hai circuit
        int start=0;

        for(int i=0;i<gas.size();i++)
        {
            balance+=gas[i]-cost[i];
            if(balance<0)
            {
                deficient+=abs(balance);
                start=i+1;
                balance=0;
            }
        }
        if(balance>=deficient)
        {
            return start;
        }
        else{
            return -1;
        }

    }
int main()
{
    int n;
    cout<<"Enter the size of gas and cost: ";
    cin>>n;
    vector<int> gas(n);
    cout<<"Enter the element in the gas: ";
    for(int i=0;i<n;i++)
    {
        cin>>gas[i];
    }
    vector<int> cost(n);
    cout<<"Enter the element in the cost: ";
    for(int i=0;i<n;i++)
    {
        cin>>cost[i];
    }

    cout<<canCompleteCircuit(gas,cost);
}