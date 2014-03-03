#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
int getSum(string num)
{
        int sum=0;
        for(int i=num.length()-1;i>=0;i--)
        {
                sum+= (num[i] -'0');
        }
        return sum;
}

int main(int argc, char** argv)
{
        ifstream in(argv[1]);
        string str;
        while(getline(in,str))
        {
                cout<<getSum(str)<<endl;
        }
        return 0;
}
