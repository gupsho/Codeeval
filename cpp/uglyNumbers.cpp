#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

void dec2bin(char* bin, int num)
{
        for(int i=0;i<13;i++)
                bin[i] = '0';
        int size=0;
        while(num)
        {
                bin[size++]=(num%3)+'0';
                num /=3;
        }
}

//0== nothing , 1 == + , 2 == -
int main(int argc, char** argv)
{
        ifstream in(argv[1]);
        string line;
        while(getline(in,line))
        {
                int count = 0;
                int D = line.length();
                int total = pow((double)3,D-1);
                char* bin = new char[13];
                for(int i=0;i<total;i++)
                {
                        int num1 = -1, num2 = -1;
                        //long int num = 0;
                        double num = 0;
                        char op = '3';
                        dec2bin(bin,i);
                        string str="";
                        str += line[0];
                        for(int j=0;j<(D-1);j++)

                        {
                                if(bin[j]=='0')
                                        str+=line[j+1];
                                else
                                {
                                        if(num1 == -1)
                                        {
                                                //num1 = atol(str.c_str());
                                                num1 = strtod(str.c_str(),NULL);
                                                if(op == '1')
                                                {
                                                        num+= num1;
                                                        num1 = -1;
                                                }
                                                else if(op == '2')
                                                {
                                                        num-= num1;
                                                        num1 = -1;
                                                }
                                                op = bin[j];
                                                str = line[j+1];
                                        }
                                        else
                                        {
                                                //num2 = atol(str.c_str());
                                                num2 = strtod(str.c_str(),NULL);
                                                if(op =='1')
                                                        num+= (num1+num2);
                                                else if(op == '2')
                                                        num+= (num1-num2);

                                                op = bin[j];
                                                num1 = -1;
                                                num2 = -1;
                                                str = line[j+1];
                                                
                                        }
                                }

}
                        if(num1==-1)
                                num1 = 0;
                        num2 = atoi(str.c_str());
                        if(op =='1')
                                num+= (num1+num2);
                        else if(op == '2')
                                num+= (num1-num2);
                        else
                                //num = atol(str.c_str());
                                num = strtod(str.c_str(),NULL);
                        //if(((num%2) ==0) || ((num%3) == 0) || ((num%5) == 0) || ((num%7) ==0))
                        if((fmod(num,2) ==0) || (fmod(num,3) == 0) || (fmod(num,5) == 0) || (fmod(num,7) ==0))
                                count++;
                }
                cout<<count<<endl;

        }
        return 0;
}

