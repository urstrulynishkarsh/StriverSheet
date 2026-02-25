#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

 bool isPalindrome (string & s, int i, int j){
    while(i<j)
    {
        if(s[i]!=s[j]) 
        {
            return false;
        }
        i++; 
        j--;
    }
    return true;
}

 int solve (string & s, int i, int j, vector<int> & dp)
 {    
        if(i>=j || isPalindrome(s, i, j)) 
        {
            return 0;
        }

        if(dp[i]!=-1)
        {
            return dp[i];
        } 
        int ans = INT_MAX;
        for(int k=i; k<j; k++)
        {
            if(isPalindrome(s, i, k))
            {                         
                int temp = solve (s, k+1, j, dp) + 1;
                ans = min (ans, temp);
            }
        }
        return dp[i] = ans;
}


int main()
{
    string str;
    cout<<"Enter the string: ";
    cin>>str;
    int n =str.length();
    vector<int> dp (n+1, -1);   
    cout<<solve(str, 0, n-1, dp);
    
    

   



    
    
   
}