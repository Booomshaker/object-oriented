#include<stdio.h>
int main()
{
	int a,b,sum,m,n;
	scanf("%d %d",&a,&b);
	sum=a+b;
	if(sum<0) 
	{
		printf("-");
		sum=-sum;
	}
	if(sum<1000) printf("%d",sum);
	else if(sum>1000&&sum<1000000)
	{
		m=sum%1000;
		n=sum/1000;
		printf("%d,%03d",n,m);
	}
	else
	{
		m=sum%1000;
		n=sum/1000000;
		printf("%d,%03d,%03d",n,(sum-n*1000000)/1000,m); 
	}
	return 0;	
}
