#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
using namespace std;
int main(int argc, char** argv)
{
        ifstream in(argv[1]);
        string line;
        while(getline(in,line))
        {
                const char *constr = line.c_str();
                char *str = const_cast<char*>(constr);
                char *ip;

                ip=strtok(str,",");
                if(ip==NULL)
                        continue;
                int lastnum = atoi(ip);
                cout<<lastnum;

                ip = strtok(NULL,",");

                if(ip==NULL)
                        continue;

                while(ip!=NULL)
                {
                        int num = atoi(ip);
                        if(num!=lastnum)
                                cout<<","<<num;
                        lastnum = num;
                        ip=strtok(NULL,",");
                }
                cout<<endl;
        }
        return 0;
}

