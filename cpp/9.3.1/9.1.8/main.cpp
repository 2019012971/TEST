#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main()
{
    deque<string> dstr;
    string str;

    while(cin>>str)
        dstr.push_back(str);
    for(auto i=dstr.begin();i!=dstr.end();i++)
    {
        cout<<*i<<" ";
    }
    return 0;
}
