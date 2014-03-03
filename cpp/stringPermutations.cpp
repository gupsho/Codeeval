
#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
using namespace std;

#define SWAP(x,y,z) ((z) = (x), (x) = (y), (y) = (z))

vector<string> a;

void perm(char *list, int i, int n)
{
        int temp;
        if(i==n)
        {
                string s;
                for(int j=0;j<n;j++)
                        s+=list[j];
                a.push_back(s);
        }
        else
        {
                for(int j=i;j<n;j++)
                {
                        SWAP(list[i], list[j], temp);
                        perm(list, i+1, n);
                        SWAP(list[j], list[i], temp);
                }
        }
}

int main(int argc, char** argv)
{
        ifstream in(argv[1]);
        string line;
        while(getline(in,line))
        {
                const char *constr = line.c_str();
                char *str = const_cast<char*>(constr);
                perm(str, 0, strlen(str));

                sort(a.begin(),a.end());
                int first=0;
                for(int i=0;i<a.size();i++)
                {
                        if(first)
                                cout<<",";
                        cout<<a[i];
                        first=1;
                }
                cout<<endl;
                a.clear();
        }
        return 0;
}

