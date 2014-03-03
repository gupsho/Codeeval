#include<iostream>
#include<fstream>

using namespace std;

int printGCD(int a, int b)
{
        int k = 0;
        while((a-k*b) >= b)
                k++;

        return a-k*b;
}

int main(int argc, char** argv)
{
        ifstream in(argv[1]);
        string line;
        while(getline(in,line))
        {
                const char *constr = line.c_str();
                char *str = const_cast<char*>(constr);
                char *first=strtok(str,",");
                char *second=strtok(NULL, ",");
                int num = atoi(first);
                int num2 = atoi(second);
                cout<<printGCD(num, num2)<<endl;
        }
        return 0;
}

