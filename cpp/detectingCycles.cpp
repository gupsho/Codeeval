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
                const char *constr = line.c_str();
                char *str = const_cast<char*>(constr);
                char *ip = strtok(str, " ");
                int a[(line.length()/2)+1];
                int i=0;
                while(ip!=NULL)
                {
                        int num = atoi(ip);
                        a[i++] = num;
                        ip = strtok(NULL, " ");
                }
                string out;
                int match=0,found=0;
                for(int j=0;j<i;j++)
                        for(int k=j+1;k<i;k++)
                        {
                                if(a[j]==a[k])
                                {
                                        int m=j,n=k;
                                        while(m<i && n<i)
                                        {
                                                if((m<n-match || m>n+match) && (a[m] == a[n]))
                                                {
                                                        if(match)
                                                                out += " ";
                                                        if(a[m]>9)
                                                        {
                                                                out+= ((a[m]/10) + '0');
                                                                out+= ((a[m]%10) + '0');

                                                        }
                                                        else
                                                                out+= (a[m] +'0');
                                                        match++;
                                                        m++;
                                                        n++;
                                                }
                                                else
                                                        break;
                                        }
                                        found=1;
                                        break;
                                }
                                if(found)
                                        break;
                        }
                if(found)
                        cout<<out<<endl;
        }
        return 0;
}

