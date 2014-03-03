#include<iostream>
using namespace std;
union test
{
        int a;
        char b[4];
}u;

int main()
{
        u.a=256;
        if((int)u.b[1]==1)
                cout<<"LittleEndian"<<endl;
        else
                cout<<"BigEndian"<<endl;
        return 0;
}

