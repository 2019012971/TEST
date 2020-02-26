#include <iostream>
#include <list>
#include <string>
using namespace std;

int main()
{
    list<string> dstr;
    string str;

    while(cin>>str)
        dstr.push_back(str);
    for(auto iter=dstr.begin();iter!=dstr.end();iter++)
    {
        cout<<*iter<<" ";
    }
    return 0;
}
