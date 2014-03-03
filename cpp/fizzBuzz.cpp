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

                ip=strtok(str," ");
                int a = atoi(ip);

                ip = strtok(NULL," ");
                int b = atoi(ip);

                ip = strtok(NULL," ");
                int n = atoi(ip);

                int first=0;
                int c= a*b;
                for(int i=1;i<=n;i++)
                {
                        if(first)
                                cout<<" ";
                        first=1;
                        if(i%c==0)
                                cout<<"FB";
                        else if(i%a==0)
                                cout<<"F";
                        else if(i%b==0)
                                cout<<"B";
                        else
                                cout<<i;
                                                }
                cout<<endl;

        }
        return 0;
}

