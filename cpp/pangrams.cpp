#include<iostream>
#include<fstream>
using namespace std;
int main(int argc, char** argv)
{
        int a[26]={0};
        ifstream in(argv[1]);
        string str;
        while(getline(in,str))
        {
                int flag=0;
                for(int i=0;i<str.length();i++)
                {
                        char c=tolower(str[i]);
                        if(c>='a' && c<='z')
                                a[c-'a']=1;
                }

                for(int i=0;i<26;i++)
                {
                        if(a[i]==0)
                        {
                                flag=1;
                                cout<<(char)('a'+i);
                        }
                }
                if(flag==0)
                        cout<<"NULL";
                cout<<endl;
                for(int i=0;i<26;i++)
                        a[i]=0;
        }
        return 0;
}

