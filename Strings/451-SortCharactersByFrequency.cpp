#include<iostream>
#include<string.h>
#include<unordered_map>
using namespace std;

string sortCharByFreq(string &str)
{
    unordered_map<char,int> hashmap;
    for(char ch: str)
    {
        hashmap[ch]++;
    }

    vector<pair<char,int> >vec(hashmap.begin(),hashmap.end());

    sort(vec.begin(),vec.end(),[](auto &a, auto &b){
        return a.second>b.second;
    });

    string ans;
    for(auto &p:vec)
    {
        ans.append(p.second,p.first);
    }
    return ans;

}
int main()
{
    string str;
    cout<<"Enter the string: ";
    getline(cin,str);

    cout<<sortCharByFreq(str);
}