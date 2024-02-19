#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int login = 0;
int admin = 0;
char username[100];
char passwd[100] = "this_is_a_super_secret_password";

void writeLog()
{
    char content[1010];
    char log[900];
    char day[100];
    printf("Enter day: ");
    fgets(day, sizeof(day), stdin);
    if (day[strlen(day) - 1] == '\n')
    {
        day[strlen(day) - 1] = '\0';
    }
    printf("Enter log: ");
    fgets(log, sizeof(log), stdin);
    if (log[strlen(log) - 1] == '\n')
    {
        log[strlen(log) - 1] = '\0';
    }
    strcpy(content, "Day ");
    strcat(content, day);
    strcat(content, ": ");
    strcat(content, log);

    FILE *fptr;
    fptr = fopen("/tmp/log.txt", "a");
    fprintf(fptr, "%s\n", content);
    fclose(fptr);
}

void readLog()
{
    FILE *fptr;
    char c;
    fptr = fopen("/tmp/log.txt", "r");
    if (fptr == NULL)
    {
        printf("Can not open log\n");
        return;
    }
    c = fgetc(fptr);
    printf(" _       ___    ____   __  __     _      ____  _   _  ___  _   _  _____\n");
    printf("| |     / _ \\  / ___| |  \\/  |   / \\    / ___|| | | ||_ _|| \\ | || ____|\n");
    printf("| |    | | | || |  _  | |\\/| |  / _ \\  | |    | |_| | | | |  \\| ||  _|\n");
    printf("| |___ | |_| || |_| | | |  | | / ___ \\ | |___ |  _  | | | | |\\  || |___\n");
    printf("|_____| \\___/  \\____| |_|  |_|/_/   \\_\\ \\____||_| |_|___||_| \\_||_____|\n\n");
    printf("===================================================================\n");
    while (c != EOF)
    {
        printf("%c", c);
        c = fgetc(fptr);
    }
    printf("===================================================================\n");
    fclose(fptr);
}

void changePassword()
{
    char newPasswd[1000];
    printf("Enter new password: ");
    gets(newPasswd);
    strcpy(passwd, newPasswd);
}

void logout()
{
    login = 0;
    admin = 0;
}

void exitProgram()
{
    printf("Bye!\n");
    exit(0);
}

void adminFunc()
{
    if (admin && strcmp(username, "admin") == 0)
    {
        printf("This is admin console\n");
        system("/bin/sh");
    }
    else
    {
        printf("You are not admin\n");
    }
}

void menu()
{
    int choice;
    printf("1. Write Log\n");
    printf("2. Read Log\n");
    printf("3. Change Password\n");
    printf("4. Logout\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    while (getchar() != '\n')
        ;

    switch (choice)
    {
    case 1:
        writeLog();
        break;
    case 2:
        readLog();
        break;
    case 3:
        changePassword();
        break;
    case 4:
        logout();
        break;
    case 5:
        exitProgram();
        break;
    case 1337:
        adminFunc();
        break;
    default:
        printf("Invalid choice\n");
        break;
    }
}

int main()
{
    setvbuf(stdout, 0, 2, 0);
    setvbuf(stdin, 0, 2, 0);
    char password[120];
    printf("Welcome to the log machine!\n");

    while (1)
    {
        if (login)
        {
            printf("Logged in as %s\n", username);
            menu();
        }
        else
        {
            printf("Enter username: ");
            fgets(username, sizeof(username), stdin);
            username[strlen(username) - 1] = '\0';

            if (strcmp(username, "employee") != 0)
            {
                printf("Invalid username\n");
                continue;
            }

            printf("Enter password: ");
            fgets(password, sizeof(password), stdin);
            password[strlen(password) - 1] = '\0';

            if (strcmp(password, passwd) != 0)
            {
                printf("Invalid password\n");
                continue;
            }

            printf("Successfully logged in\n");
            login = 1;
        }
    }

    return 0;
}
