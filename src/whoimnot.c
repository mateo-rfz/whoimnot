#include <stdio.h>
#include <pwd.h>
#include <unistd.h>



int
main()
{
    struct passwd * pswd;


    const int UID = getuid();


    while ((pswd = getpwent()) != 0)
    {
        if (pswd->pw_uid == UID)
        {
            printf("%s \n" , pswd->pw_name);
        }
    }


    endpwent();
}