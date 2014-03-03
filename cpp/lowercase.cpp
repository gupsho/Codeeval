#include<iostream>
#include<fstream>
using namespace std;
int main(int argc, char** argv)
{
        ifstream in(argv[1]);
        string str;
        while(getline(in,str))
        {
                for(int i=0;i<str.length();i++)
                        cout<<(char)tolower(str[i]);
                cout<<endl;
        }
        return 0;
}

