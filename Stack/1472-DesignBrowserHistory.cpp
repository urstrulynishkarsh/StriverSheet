#include<iostream>
#include<string.h>
#include<vector>
#include<stack>
using namespace std;

class BrowserHistory{
    public:
    stack<string> browserstack, forwardstack;
    BrowserHistory(string homepage)
    {
        browserstack.push(homepage);
    }

    void visit(string url)
    {
        while(!forwardstack.empty())
        {
            forwardstack.pop();
        }
        browserstack.push(url);
    }

    string back(int steps)
    {
        while(steps--)
        {
            if(browserstack.size()>1)
            {
                forwardstack.push(browserstack.top());
                browserstack.pop();
            }
            else{
                break;
            }
        }
        return browserstack.top();
    }


    string forward(int steps)
    {
        while(steps--)
        {
            if(forwardstack.size()>0)
                {
                    browserstack.push(forwardstack.top());
                    forwardstack.pop();
                }
                else{
                    break;
                }
        }
        return browserstack.top();
    }

};


int main()
{
    string homepage;
    cout << "Enter homepage: ";
    cin >> homepage;

    BrowserHistory browser(homepage);

    int q;
    cout << "Enter number of operations: ";
    cin >> q;

    cout << "\nCommands:\n";
    cout << "1 url        -> visit url\n";
    cout << "2 steps      -> back steps\n";
    cout << "3 steps      -> forward steps\n\n";

        while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            string url;
            cin >> url;
            browser.visit(url);
            cout << "Visited: " << url << endl;
        }
        else if (type == 2) {
            int steps;
            cin >> steps;
            cout << "Current page after back: "
                 << browser.back(steps) << endl;
        }
        else if (type == 3) {
            int steps;
            cin >> steps;
            cout << "Current page after forward: "
                 << browser.forward(steps) << endl;
        }
        else {
            cout << "Invalid command\n";
        }
    }

    return 0;
}
