#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
using namespace std;

int tree[] = {30,8,52,3,20,-1,-1,-1,-1,10,29,-1,-1,-1,-1};
int size = 15;

int find(int num)
{
	for(int i=0;i<size;i++)
	{
		if(tree[i]==num)
			return i;
	}
}
int main(int argc, char** argv)
{
	ifstream in(argv[1]);
        string line;

        while(getline(in,line))
        {
		const char *constr = line.c_str();
		char *str = const_cast<char*>(constr);
		char *ip;

		ip=strtok(str," ");
		int num1 = atoi(ip);

		ip = strtok(NULL," ");
		int num2 = atoi(ip);

		
		int f1 = find(num1);
		int f2 = find(num2);
		int orig1 = f1;
		int orig2 = f2;

		if(f1==0 || f2==0)
		{
			cout<<"0"<<endl;
			continue;
		}

		while(f1>=0 && f2>=0)
		{
			if((f1%2==0) && (f2%2 !=0))
			{
				if(f1>f2)
					f1 = (f1 -2)/2;
				else
					f2 = (f2 -1)/2;
				if(f1==f2)
				{
					if(orig1==f1)
					{
						if(f1%2==0)
							cout<<tree[(f1-2)/2]<<endl;
						else
							cout<<tree[(f1-1)/2]<<endl;
						break;
					}
					if(orig2==f2)
					{
						if(f2%2==0)
							cout<<tree[(f2-2)/2]<<endl;
						else
							cout<<tree[(f2-1)/2]<<endl;
						break;
					}
					cout<<tree[f1]<<endl;
					break;
				}
			}
			else if((f1%2!=0) && (f2%2 ==0))
			{
				if(f1>f2)
					f1 = (f1 -1)/2;
				else
					f2 = (f2 -2)/2;
				if(f1==f2)
				{
					if(orig1==f1)
					{
						if(f1%2==0)
							cout<<tree[(f1-2)/2]<<endl;
						else
							cout<<tree[(f1-1)/2]<<endl;
						break;
					}
					if(orig2==f2)
					{
						if(f2%2==0)
							cout<<tree[(f2-2)/2]<<endl;
						else
							cout<<tree[(f2-1)/2]<<endl;
						break;
					}
					cout<<tree[f1]<<endl;
					break;
				}
			}
			else if((f1%2!=0) && (f2%2!=0))
			{
				if(f1>f2)
					f1 = (f1 -1)/2;
				else
					f2 = (f2 -1)/2;
				if(f1==f2)
				{
					if(orig1==f1)
					{
						if(f1%2==0)
							cout<<tree[(f1-2)/2]<<endl;
						else
							cout<<tree[(f1-1)/2]<<endl;
						break;
					}
					if(orig2==f2)
					{
						if(f2%2==0)
							cout<<tree[(f2-2)/2]<<endl;
						else
							cout<<tree[(f2-1)/2]<<endl;
						break;
					}
					cout<<tree[f1]<<endl;
					break;
				}
			}
			else
			{
				if(f1>f2)
					f1 = (f1 -2)/2;
				else
					f2 = (f2 -2)/2;
				if(f1==f2)
				{
					if(orig1==f1)
					{
						if(f1%2==0)
							cout<<tree[(f1-2)/2]<<endl;
						else
							cout<<tree[(f1-1)/2]<<endl;
						break;
					}
					if(orig2==f2)
					{
						if(f2%2==0)
							cout<<tree[(f2-2)/2]<<endl;
						else
							cout<<tree[(f2-1)/2]<<endl;
						break;
					}
					cout<<tree[f1]<<endl;
					break;
				}
			}
		}
	}
	return 0;
}

