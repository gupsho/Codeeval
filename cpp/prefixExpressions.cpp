#include<iostream>
#include<stack>
#include<fstream>
#include<string>
using namespace std;

int main(int argc, char** argv)
{
        ifstream in(argv[1]);
        string str;
        while(getline(in, str))
        {
                stack<int> st;

                int num=0;
                int number=0;
                for(int i=str.size()-1;i>=0;i--)
                {
                        if(str[i]==' ')
                                continue;
                        else if(str[i]=='+' || str[i]=='*' ||str[i]=='/')
                        {
                                int num1 = st.top();
                                st.pop();
                                int num2 = st.top();
                                st.pop();
                                switch(str[i])
                                {
                                        case '+':st.push(num1+num2);
                                                break;
                                        case '*':st.push(num1*num2);
                                                break;
                                        case '/':st.push(num1/num2);
                                                break;
                                }
                        }
                        else
                        {

                                st.push(str[i]-'0');
                        }
                }
                cout<<st.top()<<endl;
                st.pop();
        }
        return 0;
}

