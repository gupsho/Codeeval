#include<iostream>
#include<fstream>
#include<vector>
#include<cmath>
using namespace std;

int main(int argc, char** argv)
{
        ifstream in(argv[1]);
        string str;
        in>>str;
        int num_of_cases=atoi(str.c_str());
        int arr[num_of_cases];

        for (int i=0;i<num_of_cases;i++)
        {
                arr[i]=0;
                in >> str;
                int num = atoi(str.c_str());
                float x = sqrt(num);
                for(int j=0;j<=x;j++)
                {
                        int temp = num - pow((double)j,2);
                        int sqTemp = sqrt(temp);
                        if(sqTemp*sqTemp == temp && j<=sqTemp)
                                arr[i]++;
                }
        }

        for(int i=0;i<num_of_cases;i++)
                cout<<arr[i]<<endl;

        return 0;
}

