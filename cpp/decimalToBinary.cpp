#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
using namespace std;

void printBinary(int num)
{
        int a[32]={0};
        int size=0;
        while(num)
        {
                if(num%2==0)
                        a[size++]=0;
                else
                        a[size++]=1;
                num /=2;
        }
        for(int i=size-1;i>=0;i--)
                cout<<a[i];
}
int main(int argc, char** argv)
{
        ifstream in(argv[1]);
        string line;
        while(getline(in,line))
        {
                const char *constr = line.c_str();

                int num = atoi(constr);
                printBinary(num);
                cout<<endl;
        }
        return 0;
}
