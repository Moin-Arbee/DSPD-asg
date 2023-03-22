#include<stdio.h>
#define n 10
#define days 5
//GROUP MEMBERS: 1) BT21CSE118_MOHD MOIN ARBEE IBRAHIM
//2) BT21CSE119 RITESH BANSOD
typedef struct wiz
{
char name[50];
float open[days];
float high[days];
float low[days];
float close_price[days];
float volume[days];
}wiz;


void per_change(wiz A[],int size,int day1,int day2,int w)
{
    printf("\t\t Open\tHigh\tLow\tClose_price \n");
    float a,b,c,d,e;
    printf("Stock:- %s\t",A[w].name);
    a=(((A[w].open[day2] - A[w].open[day1])*1.0)/ A[w].open[day1])*100;
    printf("%.2f\t",a);
    b=(((A[w].high[day2] - A[w].high[day1])*1.0)/ A[w].high[day1])*100;
    printf("%.2f\t",b);
    c=(((A[w].low[day2] - A[w].low[day1])*1.0)/ A[w].low[day1])*100;
    printf("%.2f\t",c);
    d=(((A[w].close_price[day2] - A[w].close_price[day1])*1.0)/ A[w].close_price[day1])*100;
    printf("%.2f\n",d);
    
}

void sortbyvolume(struct wiz A[],int size,int day3)
{
	int i,j;
	struct wiz temp;
    for(i=0;i<n-1;i++)
    {
    	for(j=i+1;j<n;j++)
    	{
    		if(A[i].volume[day3]>A[j].volume[day3])
    		{
    			temp=A[i];
    			A[i]=A[j];
    			A[j]=temp;
			}
			else if(A[i].volume[day3]==A[j].volume[day3])
		    {
			    if(A[i].close_price[day3]>A[j].close_price[day3])
			    {
				    temp=A[i];
	    		    A[i]=A[j];
	    		    A[j]=temp;
			    }
	        }
		}
    }
}

void profit_loss(wiz A[],int size,int day1,int day2)
{
	int i;
	printf("\t\t Open\tHigh\tLow\tClose price \n");
    for(i=0;i<n;i++)
    {
        float a,b,c,d,e;
        printf("Stock:- %s\t",A[i].name);
        a=((A[i].open[day2] - A[i].open[day1])*1.0);
        printf("%.2f\t",a);
        b=((A[i].high[day2] - A[i].high[day1])*1.0);
        printf("%.2f\t",b);
        c=((A[i].low[day2] - A[i].low[day1])*1.0);
        printf("%.2f\t",c);
        d=((A[i].close_price[day2] - A[i].close_price[day1])*1.0);
        printf("%.2f\n",d);
    }
}

void high(wiz A[],int size,int day1,int day2)
{
	int i=0,loc=0;
	float b[n];
	float max=-1000000.0;
    for(i=0;i<n;i++)
    {
        b[i]=(((A[i].high[day2] - A[i].low[day1])*1.0)/ (A[i].low[day1]))*100;
        if(b[i]>max)
        {
    	    max=b[i];
    	    loc=i;
	    }
    }
    for(i=0;i<n;i++)
    {
    	if(b[i]==max)
        {
            printf("Highest performing stock \n");
            printf("%s \n",A[i].name);
   	        printf("%.3f \n",max);    
   	    }     
    }	
    
}

void low(wiz A[],int size,int day1,int day2)
{
	int i=0,loc=0;
	float b[n];
	float min=1000000.0;
    for(i=0;i<n;i++)
    {
        b[i]=(((A[i].low[day2] - A[i].high[day1])*1.0)/ (A[i].high[day1]))*100;
        if(b[i]<min)
        {
    	    min=b[i];
    	    loc=i;
	    }
    }
    for(i=0;i<n;i++)
    {
    	if(b[i]==min)
        {
        	printf("Lowest performing stock \n");
    		printf("%s \n",A[loc].name);
    		printf("%.3f \n",min);
		}
	}
}

void sort(float y[],int size)
{
	int i,j;
	float temp;
    for(i=0;i<n-1;i++)
    {
    	for(j=i+1;j<n;j++)
    	{
    		if(y[i]>y[j])
    		{
    			temp=y[i];
    			y[i]=y[j];
    			y[j]=temp;
			}
		}
	}
}

void inc(wiz A[],int size,int day1,int day2)
{
	int i=0,j;
	float y[n],sum=0,x;
    for(i=0;i<n;i++)
    {
    	for(j=day1;j<day2;j++)
    	{
		    x=(((A[i].close_price[j+1] - A[i].close_price[j])*1.0)/ (A[i].close_price[j]))*A[i].volume[j];
		    sum=sum+x;
        }
        y[i]=sum;
    }
    printf("as per performance \n");
    for(i=0;i<n;i++) 
	{
        printf("%s \t",A[i].name);
        printf("%.2f\n",y[i]);
    }
    sort(y,n);
    printf("\n");
    printf("as per increasing performance order \n");
    for(i=0;i<n;i++) 
	{
        printf("%.2f   ",y[i]);
    }
}

void aver(wiz A[],int size,int day3)
{
	int i;
	float b,sum=0,c,add=0,ed;
    for(i=0;i<n;i++)
    {
        b=((((A[i].open[day3] + A[i].close_price[day3])*1.0)/2)*A[i].volume[day3]);
        sum=sum+b;
    }
    for(i=0;i<n;i++)
    {
        c=A[i].volume[day3];
        add=add+c;
    }
    ed=sum/add*1.0;
    printf("average value on the day is %.4f",ed);
}

void avg(wiz A[],int size,int day1,int day2)
{
	int i,j;
	float b,sum=0,c,add=0,ed,total,ans;
	for(j=day1;j<day2;j++)
	{
	    for(i=0;i<n;i++)
        {
            b=((((A[i].open[j] + A[i].close_price[j])*1.0)/2)*A[i].volume[j]);
            sum=sum+b;
        }
        for(i=0;i<n;i++)
        {
            c=A[i].volume[j];
            add=add+c;
        }
        ed=sum/add*1.0;
        total=total+ed;
    }
    ans=total/(day2 - day1);
    printf("average of average value of all stock in between is %f",ans);
}

int main()
{ 	
    int day1,day2;
    int i,j,q;
    wiz A[n];
    for(i=0; i<n;i++)
    {
       scanf("%s",A[i].name);
       for(j=0;j<days;j++)
        {
           scanf("%f",&A[i].open[j]);
           scanf("%f",&A[i].high[j]);
           scanf("%f",&A[i].low[j]);
           scanf("%f",&A[i].close_price[j]);
           scanf("%f",&A[i].volume[j]);
       }
    }
    printf("What do you wish to do?\n");
    printf("1. Find change in the price of a stock from start to end date.\n");
    printf("2. Sort given stock <volume-wise, close prices> wise on a particular day.\n");
    printf("3. Find profit/loss of two or more stocks, for two dates.\n");
    printf("4. Find the highest performing stock for a specified duration\n");
    printf("5. Find lowest performing stock for the specified duration.\n");
    printf("6. List all stock as per increasing the overall performance, for a specified duration.\n");
    printf("7. To find the average value of all stock at any instant of time, average of all average values.\n");
    scanf("%d",&q);
    if(q==1)
    {
    int w;
    printf("Press 1 for SBIN\n");
    printf("Press 2 for TATAM\n");
    printf("Press 3 for PNB\n");
    printf("Press 4 for YESBANK\n");
    printf("Press 5 for TECHM\n");
    printf("Press 6 for INFY\n");
    printf("Press 7 for TCS\n");
    printf("Press 8 for TITA\n");
    printf("Press 9 for ONGC\n");
    printf("Press 10 for IOC\n");
    scanf("%d",&w);
    printf("enter days, first day and last day \n");
    scanf("%d %d", &day1, &day2);
    per_change(A,n,day1-1,day2-1,w-1);
    }
    else if(q==2)
    {
    	int day3;
        printf("enter a day ");
        scanf("%d",&day3);
        sortbyvolume(A,n,day3-1);
        for(i=0;i<n;i++)
        {
        	printf("%s \t",A[i].name);
    	    printf("%.2f \t",A[i].volume[day3-1]);
			printf("%.2f\n",A[i].close_price[day3-1]);			
	    }
    }
    else if(q==3)
    {
    printf("enter days, first day an last day \n");
    scanf("%d %d", &day1, &day2);
    profit_loss(A,n,day1-1,day2-1);
    }
    else if(q==4)
    {
    printf("enter days, first day an last day \n");
    scanf("%d %d", &day1, &day2);
    high(A,n,day1-1,day2-1);
    }
    else if(q==5)
    {
    printf("enter days, first day and last day \n");
    scanf("%d %d", &day1, &day2);
    low(A,n,day1-1,day2-1);
    }
    else if(q==6)
    {
    printf("enter days, first day and last day \n");
    scanf("%d %d", &day1, &day2);
    inc(A,n,day1-1,day2-1);
    }
    else if(q==7)
    {
    int day3;
    printf("enter a day \n");
    scanf("%d", &day3);
    aver(A,n,day3-1);
    printf("\n");
    printf("enter days, first day and last day \n");
    scanf("%d %d", &day1, &day2);
    avg(A,n,day1-1,day2-1);
	}
    else if(q>7)
    {
    	printf("Please enter a valid choice.");
	}
}
