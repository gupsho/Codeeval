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
                char *text=ip;
                ip = strtok(NULL,",");
                char *c = ip;
                if(c[0]==' ')
                        c++;
                char out[strlen(text)];
                int j=0;
                for(int i=0;i<strlen(text);i++)
                {
                        int found=0;
                        for(int k=0;k<strlen(c);k++)
                        {
                                if(text[i]==c[k])
                                {
                                        found=1;
                                        break;
                                }
                        }
                        if(!found)
                                out[j++]=text[i];
                }
                out[j]='\0';
                cout<<out<<endl;
        }
        return 0;
}

