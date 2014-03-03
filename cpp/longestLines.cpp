#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
using namespace std;
bool fun(const string& a, const string& b)
{
        return (a.length() >b.length());
}

int main(int argc, char** argv)
{
        ifstream in(argv[1]);
        string line;
        getline(in,line);
        const char *s = line.c_str();
        char * c = const_cast<char*>(s);
        int num = atoi(c);
        vector<string> strings;
        vector<int> length;
        while(getline(in, line))
        {
                strings.push_back(line);
                length.push_back(line.length());
        }
        sort(strings.begin(), strings.end(), fun);
        for(int i=0;i<num;i++)
                cout<<strings[i]<<endl;


        return 0;
}
