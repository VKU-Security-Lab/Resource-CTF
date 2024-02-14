#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void vuln()
{
    int auth;
    char password[32];
    char pwd[32];

    puts("Welcome back to the BeefStack!\n");

    printf("Enter password: ");
    gets(password);

    FILE *file = fopen("password", "r");
    if (file)
    {
        fgets(pwd, 32, file);
        fclose(file);
    }

    if (strcmp(password, pwd) == 0)
    {
        auth = 0x000D0A00;
    }

    if (auth == 0x000D0A00)
    {
        system("cat /flag.txt");
        puts("\nAccess granted!\n");
    }
    else
    {
        puts("Access denied!\n");
    }
}

int main()
{
    setvbuf(stdout, 0, 2, 0);
    vuln();
    return 0;
}