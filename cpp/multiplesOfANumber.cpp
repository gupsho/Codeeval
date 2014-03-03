#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
using namespace std;

int check_power(int num)
{
        int power=0;
        while(num)
        {
                num /= 2;
                power++;
        }
        if(power>0)
                return power-1;
        return 0;
}
int power(int pow)
{
        if(pow==0)
                return 1;
        return 2*power(pow-1);
}
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
                int num = atoi(ip);

                ip = strtok(NULL,",");
                int num2 = atoi(ip);
                
                int p = check_power(num);
                if(num <= num2)
                        cout<<num<<endl;
                else if(num>num2)
                        cout<<power(p+1)<<endl;
        }
        return 0;
}

