#include<iostream>
#include<vector>
using namespace std;


void transpose(vector<vector<int> > &matrix, int &n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            swap(matrix[i][j],matrix[j][i]);
        }
    }
}
void rotateImage(vector<vector<int> > &matrix, int &n, int &m)
{
    transpose(matrix,n);
    // reverse  each row

    for(int i=0;i<n;i++)
    {
        reverse(matrix[i].begin(),matrix[i].end());
    }

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
    rotateImage(matrix, n, m);


    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

}