#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
int main()
{
	int a, b, i, j, t, x, n, k = 0, flag = 0, prime[100], ech;
	char m[20], pp[20];
	float p[20], c[20];
	double e, d;

	for (i = 0; i < 50; i++)
	{
		flag = 0;
		for (j = 2; j < i / 2; j++)
			if (i % j == 0)
			{
				flag = 1;
				break;
			}
		if (flag == 0)
			prime[k++] = i;
	}
	a = prime[k - 1];
	b = prime[k - 2];
	n = a * b;
	t = (a - 1) * (b - 1);
	e = (double)prime[2];
	d = 1 / (float)e;
	printf("\nKey of encryption is:%lf", d);
	printf("\nEnter the text:");
	scanf("%s", &m);
	x = strlen(m);
	printf("\nSource------------destination");
	printf("\nChar\t\tnumeric\t\tcipher\t\tciphered charecter\tnumeric\t\tchar\n");
	for (i = 0; i < x; i++)
	{
		printf("%c", m[i]);
		printf("\t\t%d", m[i] - 97);
		c[i] = pow(m[i] - 97, (float)e);
		c[i] = fmod(c[i], (float)n);
		printf("\t\t%f", c[i]);
		ech = (int)c[i] % 26 + 97;
		printf("\t\t%c", ech);
		p[i] = pow(c[i], (float)d);
		p[i] = fmod(p[i], (float)n);
		printf("\t\t%f", p[i]);
		pp[i] = p[i] + 97;
		printf("\t%c\n", pp[i]);
	}
	return 0;
}
