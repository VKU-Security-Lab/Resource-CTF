#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    setvbuf(stdout, NULL, _IONBF, 0);
    int auth = 0;
    char password[32];
    char *pwd;
    char username[32];
    char msg[64];

    printf("Enter username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = '\0';

    printf("Enter password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0';

    pwd = getenv("PASSWORD");

    if (pwd != NULL && strcmp(username, "admin") == 0 && strcmp(password, pwd) == 0)
    {
        auth = 1;
    }

    if (auth == 1)
    {
        puts("\nAccess granted!\n");
        system("cat /flag.txt");
        exit(0);
    }
    else
    {
        puts("Access denied!\n");
        puts("Now, you are using the program as a guest.\n");
    }

    while (1)
    {
        printf("> ");
        fgets(msg, sizeof(msg), stdin);
        printf(msg);
    }

    return 0;
}
