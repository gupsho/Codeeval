#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
int main(int argc, char** argv)
{
        ifstream in(argv[1]);
        string str;
        int sum=0;
        while(getline(in,str))
        {
                sum+=atoi(str.c_str());
        }
        cout<<sum<<endl;
        return 0;
}

