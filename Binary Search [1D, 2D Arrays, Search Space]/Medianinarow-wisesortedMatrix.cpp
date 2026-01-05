#include<iostream>
#include<vector>
using namespace std;

 int median(vector<vector<int>> &mat) {
        // code here
        vector<int> arr;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                arr.push_back(mat[i][j]);
            }
        }
        sort(arr.begin(),arr.end());
        
        int totalsize=arr.size();
        if(totalsize&1)
        {
            return arr[totalsize/2];
        }
        return -1;
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

  

  
    cout<<median(matrix);




    

}