#include<iostream>
#include<vector>
using namespace std;

int rowWithMax1s(vector < vector < int >> & mat) {
    int row=mat.size();
    int col=mat[0].size();
    
    int maxone=0;
    int rowno=-1;
    for(int i=0;i<row;i++)
    {
      int one=0;
      for(int j=0;j<col;j++)
      {
        if(mat[i][j]==1)
        {
            one++;
        }
      }
      if (one > maxone) {
            maxone = one;
            rowno = i;
        }
    }
    return rowno;
}
int main()
{
    int n,m;
    cout<<"Enter the size of row: ";
    cin>>n;
    cout<<"Enter the size of col: ";
    cin>>m;

    vector<vector<int> >matrix(n,vector<int> (m));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>matrix[i][j];
        }
    }
    cout<<endl;

  
    cout<<rowWithMax1s(matrix);




    

}