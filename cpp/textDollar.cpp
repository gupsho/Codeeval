#include<iostream>
#include<fstream>
#include<map>
#include<string.h>
using namespace std;

int main(int argc, char** argv)
{
        map<int, string> mapping;
        mapping[0] = "Zero";
        mapping[1] = "One";
        mapping[2] = "Two";
        mapping[3] = "Three";
        mapping[4] = "Four";
        mapping[5] = "Five";
        mapping[6] = "Six";
        mapping[7] = "Seven";
        mapping[8] = "Eight";
        mapping[9] = "Nine";
        mapping[10] = "Ten";
        mapping[11] = "Eleven";
        mapping[12] = "Twelve";
        mapping[13] = "Thirteen";
        mapping[14] = "Fourteen";
        mapping[15] = "Fifteen";
        mapping[16] = "Sixteen";
        mapping[17] = "Seventeen";
        mapping[18] = "Eighteen";
        mapping[19] = "Nineteen";
        mapping[20] = "Twenty";
        mapping[30] = "Thirty";
        mapping[40] = "Fourty";
        mapping[50] = "Fifty";
        mapping[60] = "Sixty";
        mapping[70] = "Seventy";
        mapping[80] = "Eighty";
        mapping[90] = "Ninety";
        

        ifstream in(argv[1]);
        string line;
        while(getline(in,line))
        {
                string text = "";
                int num = atoi(line.c_str());
                if(num == 0)
                        cout<<mapping[num]<<endl;
                while(num>0)
                {
                        int flag = 0;
                        if(num/100000000 > 0)
                        {
                                text = mapping[num/100000000];
                                text += "Hundred";
                                num = num%100000000;
                                flag = 1;
                        }
                        if(num/10000000 >0)
                        {
                                if(num/10000000 >= 2)
                                {
                                        text += mapping[(num/10000000)*10];
                                        num = num%10000000;
                                }
                                else
                                {
                                        text += mapping[num/1000000];
                                        num = num%1000000;
                                }
                                flag = 1;
                        }
                        if(num/1000000 >0)
                        {
                                text += mapping[num/1000000];
                                num = num%1000000;
                                flag = 1;
                        }

                        if(flag)
                                text += "Million";
                        flag = 0;
                        if(num/100000 >0)
                        {
                                text += mapping[num/100000];
                                text += "Hundred";
                                num = num%100000;
                                flag = 1;
                        }
                        if(num/10000 >0)
                        {
                                if(num/10000 >= 2)
                                {
                                        text += mapping[(num/10000)*10];
                                        num = num%10000;
                                }
                                else
                                {
                                        text += mapping[num/1000];
                                        num = num%1000;
                                }
                                flag = 1;
                        }
                        if(num/1000 >0)
                        {
                                text += mapping[num/1000];
                                num = num%1000;
                                flag = 1;
                        }
                        if(flag)
                                text += "Thousand";
                        flag = 0;
                        if(num/100 >0)
                        {
                                text += mapping[num/100];
                                text += "Hundred";
                                num = num%100;

                        }
                        if(num >= 20)
                        {
                                text += mapping[(num/10)*10];
                                num = num%10;
                        }
                        if(num >0)
                                text += mapping[num];

                        text += "Dollars";
                        num = 0;
                        cout<<text<<endl;
                }
        }
        return 0;
}

