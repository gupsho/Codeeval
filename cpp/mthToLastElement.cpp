#include<iostream>
#include<fstream>
using namespace std;
int main(int argc, char** argv)
{
        int a[26]={0};
        ifstream in(argv[1]);
        string line;
        while(getline(in,line))
        {
                const char *constr = line.c_str();
                char *str = const_cast<char*>(constr);
                char *ip;
                char ch[line.length()];
                int i=0;
                ip = strtok(str, " ");
                while(ip!=NULL)
                {
                        ch[i++]=ip[0];
                        ip=strtok(NULL, " ");
                }
                int num = ch[i-1]-'0';
                cout<<ch[i-1-num]<<endl;
        }
        return 0;
}

