#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
using namespace std;

int numofOnes(int num)
{
        int count=0;
        while(num)
        {
                if(num%2!=0)
                        count++;
                num /=2;
        }
        return count;
}
int main(int argc, char** argv)
{
        ifstream in(argv[1]);
        string line;
        while(getline(in,line))
        {
                const char *constr = line.c_str();

                int num = atoi(constr);
                cout<<numofOnes(num)<<endl;
        }
        return 0;
}

