#include <iostream>
#include <pwd.h>
#include <unistd.h>



using namespace std;





string 
noobiArgParser (int argc , char * argv[] , string target)
{
    for (int i = 0 ; i < argc ; i++)
    {
        if (argv[i] == target)
        {
            return argv[i+1];
        }
    }
    return "";
}



int
main(int argc , char * argv[])
{

    static int UID = getuid();
    passwd * pswd;



    //filter by min uid
    string arg = noobiArgParser(argc , argv , "--uid-min");
    if (arg != "")
    {
        while ((pswd = getpwent()) != 0)
    {
        if (pswd->pw_uid != UID && pswd->pw_uid > stoi(arg))
        {
            cout << pswd->pw_name << endl;
        }
    }
    }



    //filter by shell
    arg = noobiArgParser(argc , argv , "--shell");
    if (arg != "")
    {
        while ((pswd = getpwent()) != 0)
    {
        if (pswd->pw_uid != UID && pswd->pw_shell == arg)
        {
            cout << pswd->pw_name << endl;
        }
    }
    }








    while ((pswd = getpwent()) != 0)
    {
        if (pswd->pw_uid != UID)
        {
            cout << pswd->pw_name << endl;
        }
    }

    endpwent();
}   