#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main()
{
        vector<int>prime;
        int sum = 5;
        prime.push_back(2);
        prime.push_back(3);
        int i=5;
        int count = 2;
        while(count <1000)
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
                {
                        sum+=i;
                        prime.push_back(i);
                        count++;
                }
                i++;
        }
        cout<<sum<<endl;
        return 0;
}

