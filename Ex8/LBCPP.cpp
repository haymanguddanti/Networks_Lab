#include<iostream>
#include<stdlib.h>
#include<time.h>
#define bucketsize 512
using namespace std;
void delay(int);
void bktInput(int a, int b)
{
    if(a>bucketsize)
        cout<<"\n\t\tBucket overflow";
    else
    {
        delay(2);
        while(a>b)
        {
            cout<<"\n\t\t"<<b<<"bytes outputted.";
            a-=b;
            delay(2);
        }
        if(a>0)
        cout<<"\n\t\tLast"<<a<<"bytes sent\t";
        cout<<"\n\t\tBucket output successful\n";
    }
}
void delay(int number_of_seconds) 
{ 
    
    int milli_seconds = 1000 * number_of_seconds; 
  
   
    clock_t start_time = clock(); 
  
   
    while (clock() < start_time + milli_seconds) ; 
} 
int main()
{
    int op,pktSize,j;
    rand();
    cout<<"Enter output rate: ";
    cin>>op;
    for(int i=0;i<=5;i++)
    {
    
        pktSize=rand()%1000;
        cout<<"\nPacket no"<<i<<"\tPacket size="<<pktSize;
        bktInput(pktSize,op);
    }
    return 0;
}
