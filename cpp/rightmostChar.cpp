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
                int found = -1;
                ip=strtok(str,",");
                char *text=ip;
                ip = strtok(NULL,",");
                char *c = ip;
                for(int i=strlen(text)-1;i>=0;i--)
                {
                        if(text[i]==c[0])
                        {
                                found=1;
                                cout<<i<<endl;
                                break;
                        }
                }
                if(found==-1)
                        cout<<found<<endl;
        }
        return 0;
}

