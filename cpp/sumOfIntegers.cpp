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

                int a[(line.length()/2)+1];
                int i=0;

                ip=strtok(str,",");

                while(ip!=NULL)
                {
                        int num = atoi(ip);
                        a[i++]=num;
                        ip=strtok(NULL,",");
                }
                int sum=0,max=0;
                for(int j=0;j<i;j++)
                {
                        if((sum+a[j])>0)
                                sum+=a[j];
                        else
                                sum=0;
                        if(sum>max)
                                max=sum;
                                
                }
                cout<<max<<endl;
        }
        return 0;
}
