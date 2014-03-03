#include<iostream>
#include<fstream>
using namespace std;
int fibonacci(int num)
{
        if(num==0)
                return 0;
        if(num==1)
                return 1;
        return fibonacci(num-1)+fibonacci(num-2);
}
int main(int argc, char** argv)
{
        ifstream in(argv[1]);
        string str;
        int sum=0;
        while(getline(in,str))
        {
                cout<<fibonacci(atoi(str.c_str()))<<endl;
        }
        return 0;
}
