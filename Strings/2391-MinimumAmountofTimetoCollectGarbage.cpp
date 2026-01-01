#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

int garbageCollection(vector<string> &garbage,vector<int> &travel)
{
    // truck M
    int pickTimeM=0;
    int travelTimeM=0;
    int lastHouseM=0;

    // truck P 
    int pickTimeP=0;
    int travelTimeP=0;
    int lastHouseP=0;

    // truck G 
    int pickTimeG=0;
    int travelTimeG=0;
    int lastHouseG=0;


    for(int i=0;i<garbage.size();i++)
    {
        string current=garbage[i];
        for(int j=0;j<current.size();j++)
        {
            // for p
            if(current[j]=='M')
            {
                pickTimeM++;
                lastHouseM=i;
            }

             if(current[j]=='P')
            {
                pickTimeP++;
                lastHouseP=i;
            }

             if(current[j]=='G')
            {
                pickTimeG++;
                lastHouseG=i;
            }
        }
    }

    for(int i=0;i<lastHouseM;i++)
    {
        travelTimeM+=travel[i];
    }

    for(int i=0;i<lastHouseP;i++)
    {
        travelTimeP+=travel[i];
    }

    for(int i=0;i<lastHouseG;i++)
    {
        travelTimeG+=travel[i];
    }


    int totalpicktime=pickTimeM+pickTimeP+pickTimeG;
    int totaltraveltime=travelTimeM+travelTimeP+travelTimeG;

    return totalpicktime+totaltraveltime;




}

int main()
{
    int n;
    cout<<"Enter the no of string: ";
    cin>>n;
    vector<string> garbage;
    cout<<"Enter the string: ";
    while(n--)
    {
        string str;
        cin>>str;
        garbage.push_back(str);
    }
    int m;
    cout<<"Enter the travel size: ";
    cin>>m;
    vector<int> travel;
    cout<<"Enter the string: ";
    while(m--)
    {
        int num;
        cin>>num;
        travel.push_back(num);
    }
    cout<<garbageCollection(garbage,travel);


   
}