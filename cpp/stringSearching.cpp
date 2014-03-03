#include<iostream>
#include<fstream>
#include<cstdlib>
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
                char *text = ip;
                ip = strtok(NULL,",");
                char *sstr = ip;
                char *newstr = new char[strlen(sstr)];
                int found =0,first =0, j = 0;
                for(int i=0;i<strlen(sstr);i++)
                {
                        if(sstr[i]=='\\' && sstr[i+1]=='*')
                        {
                                newstr[j++]='*';
                                i++;
                        }
                        else if(sstr[i]=='*' && !first)
                        {
                                j=0;
                                first =1;
                        }
                        else 
                                newstr[j++] = sstr[i];
                }
                newstr[j]='\0';
                for(int i=0;i<strlen(text);i++)
                {
                        for(int j=0;j<strlen(newstr);j++)
                        {
                                while(text[i]==newstr[j])

                                {
                                        i++;
                                        j++;
                                        if(j==strlen(newstr))
                                        {
                                                found = 1;
                                                cout<<"true"<<endl;
                                                break;
                                        }
                                }
                        }
                        if(found)
                                break;
                }       
                if(!found)
                        cout<<"false"<<endl;
        }
        return 0;
}

