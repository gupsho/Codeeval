#include<iostream>
#include<fstream>
#include<cstdlib>
#include<map>
using namespace std;
int getSum(int num)
{
        int sum=0;
        while(num)
        {
                sum+= (num%10)*(num%10);
                num /= 10;
        }
        return sum;
}
                
int main(int argc, char** argv)
{
        ifstream in(argv[1]);
        string line;
        while(getline(in,line))
        {
                map<int,int> list;
                const char *constr = line.c_str();
                char *str = const_cast<char*>(constr);  
                int num = atoi(str);
                int found = 0;
                while(getSum(num)!=1)
                {
                        num = getSum(num);
                        if(list.count(num) > 0)
                        {
                                cout<<"0"<<endl;
                                found = 1;
                                break;
                        }
                        else
                                list[num] = 1;

                }
                if(!found)
                        cout<<"1"<<endl;
                list.clear();
        }
        return 0;
}

