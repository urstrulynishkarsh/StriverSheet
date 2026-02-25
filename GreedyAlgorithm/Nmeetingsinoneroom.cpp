#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

static bool mycmp(pair<int, int> &a ,pair<int, int> &b)
    {
        return a.second<b.second;
    }
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        vector<pair<int,int> > schedule;
        for(int i=0;i<start.size();i++)
        {
            pair<int,int> p=make_pair(start[i],end[i]);
            schedule.push_back(p);
        }
        sort(schedule.begin(),schedule.end(),mycmp);
        
        int count=1;
        int ansend=schedule[0].second;
        for(int i=1;i<schedule.size();i++)
        {
            if(schedule[i].first>ansend)
            {
                count++;
                ansend=schedule[i].second;
            }
        }
        return count;
 
    }
int main()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    vector<int> start(n),end(n);

    cout<<"Enter the element in the start: ";
    for(int i=0;i<n;i++)
    {
        cin>>start[i];
    }

    cout<<"Enter the element in the end: ";
    for(int i=0;i<n;i++)
    {
        cin>>end[i];
    }

    

    cout<<maxMeetings(start, end);

    return 0;
    
   
}