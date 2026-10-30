#include<stdio.h>
#include<stdio.h>

/* Call by value */
int addbyvalue(int a,int b)
{
	int res;
	res=a+b;
	return res;
}
/*call by reference*/
void swapbyreference(int*a,int*b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
int main()
{
	int a,b,res;
	int *ptr;
	int *arr;
	int n,i,sum;
	printf("enter the first number:");
	scanf("%d",&a);
	printf("enter the second number:");
	scanf("%d",&b);
	/*pointer demonstration*/
	ptr=&a;
	printf("\npointer demonstration:");
	printf("\nvalue of a=%d",*ptr);
	printf("\naddress of a=%p",(void*)ptr);
	/*call by value*/
	res=addbyvalue(a,b);
	printf("\n\ncall by value:");
	printf("\nsum=%d",res);
	/*call by reference*/
	swapbyreference(&a,&b);
	printf("\n\ncall by reference:");
	printf("\nafter swapping ,first number=%d",a);
	printf("\nafter swapping,second number=%d",b);
	/*dynamic memory allocation*/
	printf("\n\ndynamic memory allocation");
	printf("\nenter the number of elements:");
	scanf("%d",&n);
	if(n<=0)
	{
		printf("invalid number of elements.");
		return 1;
	}
	arr=malloc((size_t)n * sizeof(int));
	if(arr==NULL)
	{
		printf("memory allocation failed.");
		return 1;
	}
	printf("enter %d elements:\n",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	sum=0;
	for(i=0;i<n;i++)
	{
		sum=sum+arr[i];
	}
	printf("sum of dynamically allocated array=%d\n",sum);
	free(arr);
	return 0;
}
	
