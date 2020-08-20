#include <stdio.h>
int main()
{
    unsigned int compad[4];
    unsigned int mask[4];
    unsigned int netadr[4];
    int i;
    printf("Enter the ip address:\n");
    scanf("%u%*c%u%*c%u%*c%u%*c", &compad[3], &compad[2], &compad[1], &compad[0]);
    printf("Enter the subnet address:\n");
    scanf("%u%*c%u%*c%u%*c%u%*c", &mask[3], &mask[2], &mask[1], &mask[0]);
    for (i = 0; i < 4; i++)
    {
        netadr[i] = compad[i] & mask[i];
    }
    printf("\nNetwork address is:\n");
    printf("%u.%u.%u.%u", netadr[3], netadr[2], netadr[1], netadr[0]);
    printf("\nsubnet address is:\n");
    printf("%u.%u.%u.%u", mask[3], mask[2], mask[1], mask[0]);
    printf("\nip address is:\n");
    printf("%u.%u.%u.%u", compad[3], compad[2], compad[1], compad[0]);
    printf("\n");
    return 0;
}
