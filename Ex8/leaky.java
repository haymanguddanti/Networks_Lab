import java.util.*;
public class leaky
{
    static int min(int x,int y)
    {
        if(x<y)
            return x;
        else
            return y;
    }
    public static void main(String args[])
    {
        int drop=0,mini,nsec,cap,count=0,i,process;
        int inp[]=new int[25];
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the bucket Size\n");
        cap=sc.nextInt();
        System.out.println("Enter the Operation Rate\n");
        process=sc.nextInt();
        System.out.println("Enter the no of seconds you want to stimulate:\n");
        nsec=sc.nextInt();
        for(i=0;i<nsec;i++)
        {
            System.out.println("Enter the size of the packet entering at"+i+1+"sec");
            inp[i]=sc.nextInt();

        }
        System.out.println("\nSecond|Packet Recieved|Packet Sent|Packet LEft|Packet Dropped|\n");
        for(i=0;i<nsec;i++)
        {
            count+=inp[i];
            if(count>cap)
            {
                drop=count-cap;
                count=cap;
            }
            System.out.print(i+1);
            System.out.print("\t\t"+inp[i]);
            mini=min(count,process);
            System.out.print("\t\t"+mini);
            count=count-mini;
            System.out.print("\t\t"+count);
            System.out.print("\t\t"+drop);
            drop=0;
            System.out.println();
        }
        for(;count!=0;i++)
        {
            if(count>cap)
            {
                drop=count-cap;
                count=cap;
            }
            System.out.print(i+1);
            System.out.print("\t\t0");
            mini=min(count,process);
            System.out.print("\t\t"+mini);
            count=count-mini;
            mini=min(count,process);
            System.out.print("\t\t"+mini);
            count=count-mini;
            System.out.print("\t\t"+count);
            System.out.print("\t\t"+drop);
            System.out.println();
        }
    }
}

