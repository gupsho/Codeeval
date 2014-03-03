#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cmath>
using namespace std;

int reverse(int num)
{
        int orig = num;
        int num_of_digits = 0,newNum = 0;
        while(num)
        {
                num_of_digits++;
                num/=10;
        }
        num = orig;
        for(int i=num_of_digits-1;i>=0;i--)
        {
                newNum += (num%10)*(pow((double)10,i));
                num/=10;
        }
        return newNum;
}

int main(int argc, char** argv)
{
        ifstream in(argv[1]);
        string line;
        while(getline(in,line))
        {
                const char *constr = line.c_str();
                char *str = const_cast<char*>(constr);
                int num = atoi(str);
                int count = 0;
                while(num!=reverse(num))
                {
                        int newNum = num + reverse(num);
                        count++;
                        num = newNum;
                }

                cout<<count<<" "<<num<<endl;
        }
        return 0;
}

