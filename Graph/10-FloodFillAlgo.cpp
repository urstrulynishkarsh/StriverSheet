#include<iostream>
#include<vector>
using namespace std;
int dx[4]={0,0,1,-1};
    int dy[4]={-1,1,0,0};
    void dfs(vector<vector<int>>& image, int i, int j, int oldcolor, int newcolor)
    {
        if(i<0 ||i>=image.size() || j<0 || j>=image[0].size() || image[i][j]!=oldcolor)
        {
            return;
        }
        image[i][j]=newcolor;
        for(int k=0;k<4;k++)
        {
            int ii=i+dx[k];
            int jj=j+dy[k];
            dfs(image,ii,jj,oldcolor,newcolor);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newcolor) {
        if(image[sr][sc]==newcolor)
        {
            return image;
        }
        int oldcolor=image[sr][sc];
        dfs(image, sr,sc,oldcolor,newcolor);
        return image;
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

    int i,j;
    cout<<"Enter the valid matrix index: ";
    cin>>i>>j;

    int newcolor;
    cout<<"Enter new color: ";
    cin>>newcolor;
    vector<vector<int>> result=floodFill(grid,i,j,newcolor);

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }


}