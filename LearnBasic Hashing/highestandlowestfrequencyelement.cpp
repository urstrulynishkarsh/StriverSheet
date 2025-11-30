#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>


using namespace std;

void countFrequencies(vector<int>& nums) {
    
        unordered_map<int,int> hash;
        for(int val:nums)
        {
            hash[val]++;
        }
        
        int maxFreq=INT_MIN;
        int minFreq=INT_MAX;
        int minelement=0;
        int maxelement=0;

        for(auto it:hash)
        {
            if(it.second<minFreq)
            {
                minFreq=it.second;
                minelement=it.first;
            }
            if(it.second>maxFreq)
            {
                maxFreq=it.second;
                maxelement=it.first;
            }
        }

        cout << "\nHighest Frequency Element: " << maxelement 
        << " → " << maxFreq << " times" << endl;

   cout << "Lowest Frequency Element: " << minelement 
        << " → " << minFreq << " times" << endl;

    
}


int main()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the element in the array: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    countFrequencies(arr);

    return 0;
    
   
}