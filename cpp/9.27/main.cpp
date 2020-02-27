#include <iostream>
#include <forward_list>

using namespace std;

int main()
{
    forward_list<int> f_ilst{0,1,2,3,4,5,6,7,8,9,10};

    auto prev=f_ilst.before_begin();
    auto curr=f_ilst.begin();

    while(curr!=f_ilst.end())
    {
        if(*curr % 2)
            curr=f_ilst.erase_after(prev);
        else{
            prev=curr;
            curr++;
        }
    }

    for(auto i:f_ilst) cout<<i<<" ";
    return 0;
}
