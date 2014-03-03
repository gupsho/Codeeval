#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
void countNum(int *a,int num)
{
        int sum=0;
        while(num)
        {
                a[num%10]++;
                num /= 10;
        }
}
                
int main(int argc, char** argv)
{
        ifstream in(argv[1]);
        string line;
        while(getline(in,line))
        {
                int a[10]={0};
                const char *constr = line.c_str();
                char *str = const_cast<char*>(constr);  
                int num = atoi(str);
                int found = 0;
                int pos=strlen(str)-1;
                if(pos>9)
                {
                        cout<<"0"<<endl;
                        continue;
                }
                countNum(a,num);
                while(pos)
                {
                        if(a[pos] == (num%10))
                        {       
                                num /= 10;
                                pos--;
                                continue;
                        }

                        else
                        {
                                found=1;
                                break;
                        }
                }
                if(found)
                        cout<<"0"<<endl;
                else
                        cout<<"1"<<endl;
                for(int i=0;i<10;i++)
                        a[i]=0;
        }
        return 0;
}

