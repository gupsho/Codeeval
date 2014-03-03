#include<iostream>
#include<fstream>

using namespace std;

long hexToDec(string a)
{
	long num = 0;
	for(int i=0;i<a.length(); i++)
	{
		switch(a[i])
		{
			case 'a': num = num*16 + 10;
				  break;
			case 'b': num = num*16 + 11;
				  break;
			case 'c': num = num*16 + 12;
				  break;
			case 'd': num = num*16 + 13;
				  break;
			case 'e': num = num*16 + 14;
				  break;
			case 'f': num = num*16 + 15;
				  break;
			default:
				  num = num*16 + (a[i] - '0');
				  break;
		}
	}

	return num;
}

int main(int argc, char** argv)
{
	ifstream in(argv[1]);
	string line;
	while(getline(in,line))
	{
	        cout<<hexToDec(line)<<endl;
	}
	return 0;
}

