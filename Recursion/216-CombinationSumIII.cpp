#include<iostream>
#include<vector>
using namespace std;


void solveRecursion(int k, int target,vector<vector<int> > &result,vector<int> ans,int index)
{   
    if(target==0 && k==0)
    {
        result.push_back(ans);
        return;
    }
    for(int i=index;i<=9;i++)
    {
        if(i>target || k<=0)
        {
            break;
        }
        ans.push_back(i);
        solveRecursion(k-1,target-i,result,ans,i+1);
        ans.pop_back();
    }
}
int main()
{
    int k;
    cout<<"Enter the value of k: ";
    cin>>k;
    int n;
    cout<<"Enter the value of n: ";
    cin>> n;
    


    vector<vector<int> > result;
    vector<int> ans;

    solveRecursion(k,n,result,ans,1);



    for (int i = 0; i < result.size(); i++) {   
    cout << "{ ";
    for (int j = 0; j < result[i].size(); j++) {
        cout << result[i][j] << " ";
    }
    cout << "}\n";
    }

}