#include<stdio.h>
#define max 10
int main()
{
int path[max][max],i,j,min,a[max][max],p,st=1,ed,stp,edp,t[max],index,ord;
printf("Enter the order of the matrix:");
scanf("%d",&ord);
ed=ord;
printf("enter the cost matrix\n");
for(i=1;i<=ord;i++)
for(j=1;j<=ord;j++)
scanf("%d",&a[i][j]);
printf("enter the number of paths\n");
scanf("%d",&p);
printf("enter possible paths\n");
for(i=1;i<=p;i++)
for(j=1;j<=ord;j++)
scanf("%d",&path[i][j]);
for(i=1;i<=p;i++)
{
t[i]=0;
stp=st;
for(j=1;j<=ord;j++)
{
edp=path[i][j+1];
t[i]=t[i]+a[stp][edp];
if(edp==ed)
break;
else
stp=edp;
}
}
min=t[st];index=st;
for(i=1;i<=p;i++)
{
if(min>t[i])
{
min=t[i];
index=i;
}  
}
printf("minimum cost %d",min);
printf("\n minimum cost path ");
for(i=1;i<=ord;i++)
{
printf("--> %d",path[index][i]);
if(path[index][i]==ed)
break;
}
return 0;
}
