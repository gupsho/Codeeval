#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
int main(int argc, char** argv)
{
        ifstream in(argv[1]);
        string line;
        while(getline(in,line))
        {
                for(int i=0;i<line.length();i++)
                {
                        int found =0;
                        for(int j=0;j<line.length();j++)
                        {
                                if(i!=j && line[i]==line[j])
                                {
                                        found=1;
                                        break;
                                }
                        }
                        if(found)
                                continue;
                        else
                        {
                                cout<<line[i]<<endl;
                                break;  
                        }
                }
                
        }
        return 0;
}

