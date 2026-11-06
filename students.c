#include<stdio.h>
struct Student
{
	int rollno;
	char name[50];
	float mark;
};
union contact
{
	char phone[15];
	char email[50];
};
int main()
{
	struct Student s;
	union contact c;
	FILE *fp;
	
	printf("enter student roll number:");
	scanf("%d",&s.rollno);
	
	printf("enter student name:");
	scanf("%s",s.name);
	
	printf("enter student mark:");
	scanf("%f",&s.mark);
	
	printf("enter phone number:");
	scanf("%s",c.phone);
	
	//writing data into file
	fp=fopen("student.txt","w");
	
	if(fp==NULL)
	{
		printf("unable to open file.");
		return 1;
	}
	fprintf(fp,"roll number:%d\n",s.rollno);
	fprintf(fp,"name:%s\n",s.name);
	fprintf(fp,"mark:%.2f\n",s.mark);
	fprintf(fp,"phone:%s\n",c.phone);
	fclose(fp);
	printf("\nstudent details written to file succesfully.\n");
	//reading data from file
	fp=fopen("student.txt","r");
	if(fp==NULL)
	{
		printf("unable to open file.");
		return 1;
	}
	printf("\n----STUDENT DETAILS----\n");
	char line[100];
	while(fgets(line,sizeof(line),fp)!=NULL)
	{
		printf("%s",line);
	}
	fclose(fp);
	return 0;
}
