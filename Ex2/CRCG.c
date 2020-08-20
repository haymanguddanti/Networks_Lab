#include <stdio.h>
#include <string.h>
#define N strlen(gen)
char t[50], cs[50], gen[50];
int a, e, c, b;
void operation();

void xor () 
{
    for (c = 1; c < N; c++)
        cs[c] = ((cs[c] == gen[c]) ? '0' : '1');
}
void crc()
{
    for (e = 0; e < N; e++)
        cs[e] = t[e];
    do
    {
        if (cs[0] == '1')
            xor();
        for (c = 0; c < N - 1; c++)
            cs[c] = cs[c + 1];
        cs[c] = t[e++];
    } while (e <= a + N - 1);
}
int main()
{
    int op;
    do
    {
        printf("\n1)CRC-12\n2)CRC-16\n3)CRC-CCITT\n4)exit");
        printf("\nEnter your option-");
        scanf("%d", &op);
        if(op==1)
        {
		    strcpy(gen, "1100000001111");
		    operation();
		}
        else if(op==2)
        {
            strcpy(gen, "11000000000000101");
            operation();
    	}
        else if(op==3)
        {
		    strcpy(gen, "10001000000100001");
  			operation();
		}
    }while(op<4);
    return 0;
}

void operation()
{
	int op;
	printf("Generating Polynomial:%s", gen);
	printf("\nEnter Polynomial:");
    scanf("%s", t);
    a = strlen(t);
    for (e = a; e < a + N - 1; e++)
        t[e] = '0';
	printf("\nModified data :%s", t);
    crc();
    printf("\nChecksum value:%s", cs);
    for (e = a; e < a + N - 1; e++)
        t[e] = cs[e - a];
    printf("\nEnd Codeword is : %s", t);
	printf("\nError Detection Test \n1=yes \n2=no)?:");
    scanf("%d", &op);
    if (op== 1)
    {
    	e=0;
        do
        {
            printf("\nEnter the Location where error is to be inserted:");
            scanf("%d", &e);
        } while (e == 0 || e > a + N - 1);
        t[e - 1] = (t[e - 1] == '0') ? '1' : '0';
        printf("\nErroneous data:%s\n", t);
    }
    else if(op==2)
    {
	    crc();
        for (e = 0; (e < N - 1) && (cs[e] != '1'); e++)
            ;
        if (e < N - 1)
            printf("\nerror detected");
        else
            printf("no error detected\n");
    }
	return;
}




