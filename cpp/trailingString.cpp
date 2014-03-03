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
                char *s;
                int found = 0;
                s=strtok(str,",");
                char *text=s;
                s = strtok(NULL,",");
                char *c = s;
                int j=0;

                for(int i=strlen(text)-strlen(c); i<strlen(text);i++)
                {
                        if(text[i]==c[j])
                        {
                                found = 1;
                                j++;
                                continue;
                        }
                        else
                        {
                                found = 0;
                                break;
                        }
                }
                cout<<found<<endl;
        }
        return 0;
}
