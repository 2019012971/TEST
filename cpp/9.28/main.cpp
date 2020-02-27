#include <iostream>
#include <string>
#include <forward_list>

using namespace std;

void insert_data(forward_list<string>& slst,string const s1,string const s2)
{
    auto curr = slst.begin();
    auto prev = slst.before_begin();
    while(curr!=slst.end())
    {
        if(*curr==s1){
            slst.insert_after(curr,s2);
            return;
        }
        else{
            prev=curr++;
        }
    }
    slst.insert_after(prev,s2);
}
int main()
{
    forward_list<string> flst{"a","b","c"};
    string s1{"a"},s2{"y"};

    for(auto i: flst) cout<<i<<" ";
    cout<<endl;

    insert_data(flst,s1,s2);

    for(auto i: flst) cout<<i<<" ";
    return 0;
}
