
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

                ip=strtok(str," ");

                int total = atoi(ip);

                int a[total];

                int check[3000] ={0};

                int first =0;
                int i;

                for(i=0;i<total;i++)
                {
                        ip=strtok(NULL," ");
                        int num = atoi(ip);
                        if(first)
                        {
                                if(abs(a[i-1]-num) <3000)
                                        check[abs(a[i-1]-num)]=1;
                                else
                                        break;
                        }
                        a[i]=num;
                        first=1;
                }
                int k=0;

                for(int j=1;j<i;j++)
                        if(!check[j])
                        {
                                k=1;
                                cout<<"Not jolly"<<endl;
                                break;
                        }
                if(!k)
                        cout<<"Jolly"<<endl;
                for(int j=0;j<3000;j++)
                        check[j]=0;
        }
        return 0;
}

