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
    for(auto iter=dstr.begin();iter!=dstr.end();iter++)
    {
        cout<<*iter<<" ";
    }
    return 0;
}
