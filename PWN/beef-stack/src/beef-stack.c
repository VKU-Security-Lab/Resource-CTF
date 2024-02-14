#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
    int auth = 0;
    char password[32];
    char pwd[32];
    char username[32];

    setvbuf(stdout, 0, 2, 0);

    printf("Enter username: ");
    gets(username);

    printf("Enter password: ");
    gets(password);

    FILE *file = fopen("password", "r");
    if (file) {
        fgets(pwd, 32, file);
        fclose(file);
    }

    if (strcmp(username, "admin") == 0 && strcmp(password, pwd) == 0) {
        auth = 0x62656566;
    }

    if (auth == 0x62656566)
    {
        system("cat /flag.txt");
        printf("\nAccess granted!\n");
    }
    else
    {
        printf("Access denied!\n");
    }

    return 0;
}