#include <stdio.h>
#include <stdlib.h>

void secret(int banana_one, int banana_two)
{
    if (banana_one == 0xbabebabe && banana_two == 0xdeedfeed)
    {
        puts("Access granted!\n");
        system("cat /flag.txt");
    }
    else
    {
        puts("Access denied!\n");
    }
}

void public_func()
{
    char msg[0x20];
    printf("Hello, please enter a message: ");
    scanf("%s", msg);
    printf("Hi there, here is your message: %s\n", msg);
}

int main()
{
    setvbuf(stdout, 0, 2, 0);
    public_func();
    return 0;
}