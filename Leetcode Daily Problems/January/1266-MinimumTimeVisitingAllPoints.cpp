#include<iostream>
#include<vector>
using namespace std;

int minTimeToVisitAllPoints(vector<vector<int> >points)
{
    int time=0;
    for(int i=1;i<points.size();i++)
    {
        int dx=abs(points[i][0]-points[i-1][0]);
        int dy=abs(points[i][1]-points[i-1][1]);
        time+=max(dx,dy);
    }
    return time;
}
int main()
{
    int n;
    cout<<"Enter the value of n: ";

    cin>>n;
    vector<vector<int> >matrix(n,vector<int> (2));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<2;j++)
        {
            cin>>matrix[i][j];
        }
    }
   

  
    cout<<minTimeToVisitAllPoints(matrix);




    

}