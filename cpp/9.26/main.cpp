#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main()
{
    int ia[]={0,1,1,2,3,5,8,13,21,55,89};
    //拷贝
    vector<int> ivec;
    ivec.assign(begin(ia),end(ia));
    list<int> ilst;
    ilst.assign(begin(ia),end(ia));

    //删除
    auto v=ivec.begin();
    while(v!=ivec.end())
    {
        if(*v % 2 ==0)
            v = ivec.erase(v);
        else
            v++;
    }

    auto l=ilst.begin();
    while(l!=ilst.end())
    {
        if(*l % 2!=0)
            l = ilst.erase(l);
        else
            l++;
    }
    //打印
    for(auto pv:ivec) cout<<pv<<" ";
    cout<<endl;
    for(auto pl:ilst) cout<<pl<<" ";
    return 0;
}
