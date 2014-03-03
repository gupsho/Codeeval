#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;

void printIsArmstrong(int num)
{
	double numDigits = 0;
	int a = num;
	while(a>0)
	{
		a = a/10;
		numDigits++ ;
	}

	int sum = 0;
	a = num;
	while(a>0)
	{
		sum+= pow(a%10, numDigits);
		a = a/10;
	}
	if(sum == num)
		cout<<"True"<<endl;
	else
		cout<<"False"<<endl;
}

int main(int argc, char** argv)
{
	ifstream in(argv[1]);
	string line;
	while(getline(in,line))
	{
		int num = atoi(line.c_str());
		printIsArmstrong(num);
	}
	return 0;
}

