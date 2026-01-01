#include<iostream>
#include<vector>
using namespace std;


bool possibleSolution(vector<int> &cookRank , int nP, int mid)
{
    int currP=0;
    for(int i=0;i<cookRank.size();i++)
    {
        int rank=cookRank[i];
        int j=1;
        int timetaken=0;
        while(true)
        {
            if(timetaken+j*rank<=mid)
            {
                currP++;
                timetaken+=j*rank;
                j++;
            }
            else{
                break;
            }
        }
        if(currP>=nP)
        {
            return true;
        }
    }
    return false;
}

int minTimeToCompleteOrder(vector<int> &cookRank , int nP)
{
    int s=0;
    int maximum=*max_element(cookRank.begin(),cookRank.end());
    int e=maximum*(nP*(nP+1)/2);
    int ans=-1;
    while(s<=e)
    {
        int mid=(s+e)>>1;
        if(possibleSolution(cookRank,nP,mid))
        {
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return ans;
}

int main()
{
    int t;
    cout<<"Enter the number of test cases: ";
    cin>>t;
    while(t--)
    {
        int nP,nC;
        cout<<"Enter the number of paratha and cook:";
        cin>>nP>>nC;
        vector<int> cookRanks;
        cout<<"Enter the ranks: ";
        while(nC--)
        {
            int R;
            cin>>R;
            cookRanks.push_back(R);
        }
        cout<<minTimeToCompleteOrder(cookRanks,nP)<<endl;
    }
}