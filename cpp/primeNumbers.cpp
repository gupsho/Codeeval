
#include<iostream>
#include<fstream>
#include<cmath>
#include<vector>
using namespace std;

int main(int argc, char** argv)
{
        ifstream in(argv[1]);
        string str;
        vector<int> prime;
        while(getline(in,str))
        {
                prime.push_back(2);
                prime.push_back(3);
                int num=atoi(str.c_str());
                for(int i=4;i<num;i++)
                {
                        int j;
                        for(j=0;j<prime.size();j++)
                        {
                                if(i%prime[j]==0)
                                        break;

                                else if(prime[j]>sqrt(i))
                                {
                                        j=prime.size();
                                        break;
                                }
                                else 
                                        continue;
                        }
                        if(j == prime.size())
                                prime.push_back(i);
                }
                int j = 0;
                int first = 0;
                while(j<prime.size())
                {
                        if(first)
                                cout<<",";
                        if(prime[j]<num)
                        {
                                cout<<prime[j++];
                                first  = 1;
                        }
                        else

                                break;
                }
                cout<<endl;
                prime.clear();
        }
        return 0;
}

