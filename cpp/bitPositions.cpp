#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
using namespace std;
int power(int pow)
{
        if(pow==0)
                return 1;
        return 2*power(pow-1);
}

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
                int num = atoi(ip);
                ip = strtok(NULL,",");
                int p1 = atoi(ip);
                ip=strtok(NULL,",");
                int p2 = atoi(ip);
                int a=(num&(power(p1-1)));
                int b=(num&(power(p2-1)));
                if(((a==0) && (b==0)) || (a==(power(p1-1)) && (b==(power(p2-1)))))
                        cout<<"true"<<endl;
                else
                        cout<<"false"<<endl;
        }
        return 0;
}

