#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
using namespace std;

int main( int argc, char** argv )
{
        struct stat filestatus;
        stat(argv[ 1 ], &filestatus);
        cout<<filestatus.st_size<<endl ;
        return 0;
}

