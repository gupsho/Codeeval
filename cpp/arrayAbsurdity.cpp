#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
int main(int argc, char** argv)
{
        ifstream in(argv[1]);
        string line;
        while(getline(in,line))
        {
                if(line.empty())
                        continue;
                const char *constr = line.c_str();
                char *str = const_cast<char*>(constr);
                char *first=strtok(str,";");
                char *second = strtok(NULL, ";");
                int total = atoi(first); 
                char *num = strtok(second, ",");
                long expected_sum = 0, sum=0;
                expected_sum = ((total-2)*(total-1))/2;
                while(num!=NULL)
                {
                        int n = atoi(num);
                        sum += n;
                        num = strtok(NULL,",");
                }
                cout<<sum-expected_sum<<endl;
        }
        return 0;
}

