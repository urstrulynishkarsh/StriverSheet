#include<iostream>
#include<unordered_map>
#include<vector>
#include<string.h>
using namespace std;


void allcombination(string &digits, unordered_map<int,string> &mp, string ans, vector<string> &result,int index)
    {
        // base case
        if(index>=digits.size())
        {
            result.push_back(ans);
            return;
        }
        int digit=digits[index]-'0';
        string value=mp[digit];
        for(int j=0;j<value.length();j++)
        {
            ans.push_back(value[j]);
            allcombination(digits,mp,ans,result,index+1);  
            ans.pop_back();
        }
    }

int main()
{
    string str;
    cout << "Enter the string: ";
    getline(cin, str);

    if (str.empty())
        return 0;

    vector<string> result;
    string ans;

    unordered_map<int, string> mp = {
        {2, "abc"},
        {3, "def"},
        {4, "ghi"},
        {5, "jkl"},
        {6, "mno"},
        {7, "pqrs"},
        {8, "tuv"},
        {9, "wxyz"}
    };

    allcombination(str, mp, ans, result, 0);

    for (auto &s : result)
        cout << s << " ";

    return 0;
}