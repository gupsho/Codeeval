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

                ip=strtok(str,";");
                int a[(strlen(ip)/2) +1];
                char * num = ip;
                ip = strtok(NULL,";");
                int sum = atoi(ip);
                ip = strtok(num,",");
                int i=0;
                while(ip!=NULL)
                                {
                        a[i++]=atoi(ip);
                        ip=strtok(NULL,",");
                }
                int j=0,k=i-1;
                int first =0;
                while(j<k)
                {
                        if((a[j]+a[k])==sum)                    
                        {
                                if(first)
                                        cout<<";";
                                cout<<a[j++]<<","<<a[k--];
                                first =1;
                        }
                        else if((a[j]+a[k])<sum)
                        {
                                j++;
                        }
                        else
                                k--;
                }
                if(!first)
			cout<<"NULL";
                cout<<endl;
        }
        return 0;
}

