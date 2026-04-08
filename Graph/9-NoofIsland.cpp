#include<iostream>
#include<vector>
using namespace std;

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

void dfs(vector<vector<char>> &grid, int i, int j)
{
    if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]!='1')
    {
        return;
    }
    grid[i][j]='2';
    for(int k=0;k<4;k++)
    {
        int ii=i+dx[k];
        int jj=j+dy[k];
        dfs(grid,ii,jj);
    }
}

int main()
{
    int row,col;
    cout<<"Enter the number of row and col: ";
    cin>>row>>col;
    vector<vector<char>> grid(row, vector<char>(col));;
    cout << "Enter the elements (0 or 1):\n";
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>grid[i][j];
        }
    }

    int count=0;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(grid[i][j]=='1')
            {
            dfs(grid,i,j);
            count++;
            }
        }
    }
    cout<<"Number of islands: "<<count;
}
