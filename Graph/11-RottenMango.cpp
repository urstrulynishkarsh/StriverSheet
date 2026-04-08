#include<iostream>
#include<vector>
using namespace std;
 int dx[4]={-1,1,0,0};
    int dy[4]={0,0,1,-1};

    void dfs(vector<vector<int>>& grid,int i, int j,int time)
    {
         if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size()  || grid[i][j]!=1 && grid[i][j] < time)
        {
            return;
        }

        grid[i][j]=time;
        for(int k=0;k<4;k++)
        {
            int ii=i+dx[k];
            int jj=j+dy[k];
            dfs(grid,ii,jj,time+1);
        }

    }
    int orangesRotting(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int ellapsedtime=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==2)
                {
                    dfs(grid,i,j,2);
                }
            }
        }

         for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if (grid[i][j] == 1){
                  return -1;
                }
    
                ellapsedtime = max(ellapsedtime, grid[i][j] - 2);

            }
        }
        return ellapsedtime;

        


    }

int main()
{
    int row,col;
    cout<<"Enter the number of row and col: ";
    cin>>row>>col;
    vector<vector<int>> grid(row, vector<int>(col));;
    cout << "Enter the elements (0 or 1):\n";
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>grid[i][j];
        }
    }

    cout<<orangesRotting(grid);

}