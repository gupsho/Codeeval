#include<iostream>
#include<fstream>
using namespace std;

void LCS(char* f, char*s)
{
        int m = strlen(f);
        int n = strlen(s);
        int c[m+1][n+1];
        for(int i=m;i>=0;i--)
                for(int j=n;j>=0;j--)
                {
                        if(f[i]=='\0'|| s[j]=='\0')
                                c[i][j] = 0;
                        else if(f[i]==s[j])
                        {
                                c[i][j] = c[i+1][j+1] +1;
                        }
                        else
                                c[i][j] = max(c[i+1][j], c[i][j+1]);
                }       
        int i = 0, j = 0;
        while (i < m && j < n)
        {
                if (f[i]==s[j])
                {
                        cout<<f[i];
                        i++;
                        j++;
                }       
                else if (c[i+1][j] >= c[i][j+1]) 
                        i++;
                else 
                        j++;
        }
        cout<<endl;
}

int main(int argc, char** argv)
{

        ifstream in(argv[1]);
        string line;
        while(getline(in,line))
        {
                const char* str = line.c_str();
                char *s = const_cast<char*>(str);
                char *first = strtok(s,";");
                char *second = strtok(NULL,";");
                LCS(first,second);
        }
        return 0;
}

