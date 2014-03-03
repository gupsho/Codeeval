#include<iostream>
#include<fstream>
using namespace std;
int main(int argc, char** argv)
{
        ifstream in(argv[1]);
        string line;
        while(getline(in,line))
        {
                if(line=="")
                        continue;
                int invalid=0;
                for(int i=0;i<line.length();i++)
                        if(line[i]==' ' || line[i]=='<' || line[i]=='>')
                        {
                                cout<<"false"<<endl;
                                invalid=1;
                                break;
                        }
                if(invalid)
                        continue;
                int wrong =0,countAt =0, countDot =0,firstchar=0;
                for(int i=0;i<line.length();i++)
                {
                        if( (countAt||!firstchar) && (line[i] == '@'))
                        {
                                cout<<"false"<<endl;
                                wrong =1;
                        }
                        else if( line[i] == '@')
                                countAt++;
                        else if( countDot && (line[i] == '.'))
                        {
                                cout<<"false"<<endl;
                                wrong =1;
                        }
                        else if(line[i]=='.')
                                countDot++;
                        firstchar++;
                }

                if(wrong)
                        continue;
                if(!countDot || !countAt)
                {
                        cout<<"false"<<endl;
                        continue;
                }
                cout<<"true"<<endl;
        }
        return 0;
}

