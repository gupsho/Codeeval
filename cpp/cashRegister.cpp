#include<iostream>
#include<fstream>
#include<vector>
#include<cmath>
using namespace std;
int main(int argc, char** argv)
{
        ifstream in(argv[1]);
        string line;
        double val[12] = {.01,.05,.1,.25,.5,1,2,5,10,20,50,100};
        string names[12]={"PENNY", "NICKEL", "DIME", "QUARTER", "HALF DOLLAR", "ONE", "TWO", "FIVE", "TEN", "TWENTY", "FIFTY", "ONE HUNDRED"};
        while(getline(in,line))
        {
                const char *constr = line.c_str();
                char *str = const_cast<char*>(constr);
                char *p;
                p=strtok(str,";");
                double cost = strtod(p,NULL);
                p = strtok(NULL,";");
                double paid = strtod(p,NULL);
                double change = paid - cost;
                if(change<0)
                {
                        cout<<"ERROR"<<endl;
                        continue;
                }
                if(change == 0)
                {
                        cout<<"ZERO"<<endl;
                        continue;
                }
                vector<string> out;
                for(int i=11;i>=0;i--)
                {

                        if((change>=val[i]) || (fabs(change - val[i])<.001))
                        {
                                out.push_back(names[i]);
                                change -= val[i];
                                if(change == 0)
                                        break;
                        }
                }
                sort(out.begin(), out.end());
                int first = 0;
                for(int i=0;i<out.size();i++)
                {
                        if(first)
                                cout<<",";
                        cout<<out[i];
                        first = 1;
                }
                cout<<endl;
        }
        return 0;

}

