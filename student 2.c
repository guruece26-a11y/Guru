#include<stdio.h>
struct employee
{
	int id;
	float salary;
};
union department
{
	int deptno;
};
int main()
{
	struct employee e;
	union department d;
	FILE*fp;
	char ch;
	printf("enter employee ID:");
	scanf("%d",&e.id);
	printf("enter salary:");
	scanf("%f",&e.salary);
	printf("enter department number:");
	scanf("%d",&d.deptno);
	fp=fopen("emp.txt","w");
	fprintf(fp,"employee ID:%d\n",e.id);
	fprintf(fp,"salary:%.2f\n",e.salary);
	fprintf(fp,"department number:%d\n",d.deptno);
	fclose(fp);
	fp=fopen("emp.txt","r");
	printf("\nemployee details:\n");
	while((ch=fgetc(fp))!=EOF)
	{
		printf("%c",ch);
	}
	fclose(fp);
	return 0;
}
