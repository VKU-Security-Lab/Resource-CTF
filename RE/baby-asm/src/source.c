#include<stdio.h>

long long mysteryFunc(unsigned char *s)
{
    char key[] = "VSLRE";
    long long res = 0;
    for (int i = 0; s[i] != 0; i++) {
        res += (s[i] ^ key[i % 5]) * 0x13337;
    }
    return res;
}

int main(int argc, char *argv[])
{
    long long res = 0;
    for (int i = 0; i < argc; i++) {
        res += mysteryFunc(argv[i]);
    }
    printf("%lld\n", res);
    return 0;
}