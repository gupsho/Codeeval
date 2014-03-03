#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
void check_palindrome(vector<int> num)
{
        for(int i=num.size()-1;i>=0;i--)
                if((num[i]/100) == (num[i]%10))
                {
                        cout<<num[i]<<endl;
                        break;
                }
}
int main()
{
        vector<int>prime;
        prime.push_back(2);
        prime.push_back(3);
        int i=5;
        while(i<1000)
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
                        prime.push_back(i);
                }

                i++;
        }
        check_palindrome(prime);
        return 0;
}

