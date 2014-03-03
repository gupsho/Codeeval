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
                char *first=strtok(str,";");
                char *second = strtok(NULL, ";");
                char *num = strtok(first, ",");
                int a[strlen(first)];
                int b[strlen(second)];
                int sizea=0,sizeb=0;
                while(num!=NULL)
                {
                        a[sizea++] = atoi(num);
                        num=strtok(NULL,",");
                }
                num = strtok(second, ",");
                while(num!=NULL)
                {
                        b[sizeb++] = atoi(num);
                        num=strtok(NULL,",");
                }
                int i=0,j=0,flag=0;
                while(i<sizea && j<sizeb)
                {
                        if(a[i]==b[j])
                        {
                                if(flag==1)
                                        cout<<",";
                                cout<<a[i];
                                                                i++;
                                j++;
                                flag=1;
                        }
                        else if(a[i]>b[j])
                                j++;
                        else
                                i++;
                }
                cout<<endl;
        }
        return 0;
}

