#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

int old = 2023, new = 2024, p = 5;

bool checkPassword(char *password)
{
    if (password[0] + password[4] != 234)
    {
        return false;
    }
    if (password[0] - password[4] != 2)
    {
        return false;
    }
    if (password[1] + password[2] != 161)
    {
        return false;
    }
    if ((int)(password[1] ^ password[14]) != 12)
    {
        return false;
    }
    if (password[5] * p != 255)
    {
        return false;
    }
    if (password[8] - password[5] != 53)
    {
        return false;
    }
    if (password[6] + password[8] != 220)
    {
        return false;
    }
    if ((char)(password[9] | password[5]) != '3')
    {
        return false;
    }
    if (password[10] % password[9] != 12)
    {
        return false;
    }
    if ((int)(password[11] / password[9]) != 1)
    {
        return false;
    }
    if (password[12] * password[12] != 10000)
    {
        return false;
    }
    if ((int)(password[13] ^ old) != 2003)
    {
        return false;
    }
    if ((int)(password[14] ^ new) != 2001)
    {
        return false;
    }
    if (password[3] != 95 && password[7] != 95)
    {
        return false;
    }
    return true;
}

int main()
{
    printf("    __     __ ____   _       _____        _     ____    ___   ____   _  _\n");
    printf("    \\ \\   / // ___| | |     |_   _|  ___ | |_  |___ \\  / _ \\ |___ \\ | || |\n");
    printf("     \\ \\ / / \\___ \\ | |       | |   / _ \\| __|   __) || | | |  __) || || |_\n");
    printf("      \\ V /   ___) || |___    | |  |  __/| |_   / __/ | |_| | / __/ |__   _|\n");
    printf("       \\_/   |____/ |_____|   |_|   \\___| \\__| |_____| \\___/ |_____|   |_|\n");
    char password[20];
    printf("If you want my secret then you have to give me yours too. This is a fair exchange.\n");
    printf("Your secret: ");
    fflush(stdout);
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0';

    if (checkPassword(password))
    {
        printf("Congratulations! The flag is: VSL{%s}\n", password);
    }
    else
    {
        printf("Wrong password.\n");
    }
    return EXIT_SUCCESS;
}