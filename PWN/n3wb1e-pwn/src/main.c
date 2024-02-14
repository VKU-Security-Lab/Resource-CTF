#include<stdio.h>

void win() {
    printf("You win!\n");
}

void vuln() {
    char buf[0x20];
    printf("Enter your name: ");
    gets(buf);
    printf("Hello, %s\n", buf);
}

int main() {
    vuln();
    return 0;
}