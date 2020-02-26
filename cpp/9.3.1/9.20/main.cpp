#include <iostream>
#include <list>
#include <deque>

using namespace std;

int main()
{
    list<int> ilst{0,1,2,3,4,5,6,7,8,9,10};
    deque<int> di_even;
    deque<int> di_odd;

    for(auto ii:ilst)
    {
        if(ii%2==0){
            di_even.push_back(ii);
        }else{
            di_odd.push_back(ii);
        }
    }
    cout<<"EVEN:\n";

    for(auto j:di_even)
    {
        cout<<j<<" ";
    }
    cout<<endl<<"----------"<<endl;

    cout<<"ODD:\n";
    for(auto j:di_odd)
    {
        cout<<j<<" ";
    }
    return 0;
}
