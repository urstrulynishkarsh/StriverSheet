#include<iostream>
#include<vector>
using namespace std;

static bool mycmp(vector<int> &v1,vector<int> &v2)
{
    return v1[0]<v2[0];
}
void MergeIntervals(vector<vector<int> > &intervals,vector<vector<int> > &result)
{
    sort(intervals.begin(),intervals.end(),mycmp);
    int n=intervals.size();
    result.push_back(intervals[0]);
    for(int i=1;i<=n-1;i++)
    {
        if(intervals[i][0]<=result.back()[1])
        {
            result.back()[1]=max(result.back()[1],intervals[i][1]);
        }
        else{
            result.push_back(intervals[i]);
        }
    }

}
int main()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    vector<vector<int> >intervals(n,vector<int>(2));

    for(int i=0;i<n;i++)
    {
        cin>>intervals[i][0]>>intervals[i][1];
    }
    vector<vector<int> >result;

    MergeIntervals(intervals,result);



     // Print to verify
     for (auto v : result) {
        cout << "[" << v[0] << "," << v[1] << "] ";
    }

    return 0;
}