#include <iostream>
#include <pwd.h>
#include <unistd.h>



using namespace std;



int
main(int argc , char * argv[])
{

    static int UID = getuid();
    passwd * pswd;

    while ((pswd = getpwent()) != 0)
    {
        if (pswd->pw_uid != UID && pswd-> pw_uid > 999 )
        {
            cout << pswd->pw_name << endl;
        }
    }

    endpwent();
}   