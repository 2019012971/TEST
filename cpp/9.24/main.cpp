#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> ivec;
    cout << ivec.at(0)<<endl;
    cout << ivec[0]<<endl;
    cout << ivec.front()<<endl;
    cout << *(ivec.begin());
    return 0;
}
