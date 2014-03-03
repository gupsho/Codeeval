#include<iostream>
#include<stack>
#include<fstream>
using namespace std;
int main(int argc, char** argv)
{
        ifstream in(argv[1]);
        string line;
        while(getline(in, line))
        {
                stack<int> st;
                const char *constr = line.c_str();
                char *str = const_cast<char*>(constr);
                char *ip = strtok(str, " ");
                while(ip!=NULL)
                {
                        int num = atoi(ip);
                        st.push(num);
                        ip = strtok(NULL, " ");;
                }
                int first =0;
                while(!st.empty())
                {
                        if(first)
                                cout<<" ";
                        cout<<st.top();
                        first =1;
                        st.pop();
                        if(!st.empty())
                                st.pop();
                }
                cout<<endl;
        }
        return 0;
}

