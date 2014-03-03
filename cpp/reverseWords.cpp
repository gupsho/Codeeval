#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
using namespace std;
int main(int argc, char** argv)
{
        ifstream in(argv[1]);
        string line;
        char *out;
        while(getline(in,line))
        {
                const char *constr = line.c_str();
                char *str = const_cast<char*>(constr);
                out = new char[line.length()+1];
                int j=0;
                for(int i=line.length()-1;i>=0;i--)
                        out[i]=str[j++];
                out[j]='\0';
                char *ip;
                ip = strtok(out," ");
                while(ip!=NULL)
                {
                        for(int i=strlen(ip)-1;i>=0;i--)
                                cout<<ip[i];
                        cout<<" ";
                        ip=strtok(NULL," ");
                }
                cout<<endl;
                delete out;
        
        }
        return 0;
}

