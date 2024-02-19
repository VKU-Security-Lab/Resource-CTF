#include <stdio.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int seed[2];
    if (ptrace(PTRACE_TRACEME, 0, 1, 0) == -1)
    {
        printf("Nooo, don't debug me!\n");
        return 1;
    }

    FILE *f = fopen("flag.txt", "r");
    fseek(f, 0LL, 2);
    int size = ftell(f);

    fseek(f, 0LL, 0);
    void *ptr = malloc(size);
    fread(ptr, size, 1uLL, f);
    fclose(f);

    seed[0] = 18022024;
    srand(seed[0]);
    
    for (int i = 0; i < size; i++)
    {
        ((char *)ptr)[i] ^= rand();
        seed[1] = rand();
    }

    FILE *f2 = fopen("flag.enc", "w");
    fwrite(seed, 1uLL, 4uLL, f2);
    fwrite(ptr, 1uLL, size, f2);
    fclose(f2);
    

    return 0;
}
