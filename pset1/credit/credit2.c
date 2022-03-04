#include <cs50.h>
#include <stdio.h>

int main(void)
{
    typedef int IntX10[10];
    IntX10 gems;

    gems[1] = get_int("");

    printf("%d\n",gems[1]);
    return 0;
}