#include<stdio.h>
#include<string.h>
int main() {
    int id;
    char name[40];
    float salary;
    int days;
    printf("enter the id of the employee\n");
    scanf("%d",&id);
    printf("enter the name of the employee\n");
    scanf("%s",name);
    printf("enter the salary\n");
    scanf("%f",&salary);
    printf("enter the days of working\n");
    scanf("%d",&days);
    //process payrolls
    float bonus=0.0f;
    float gross_salary=0.0f;
    char category[20]="good";

    //calculate bonus
    if(days>25) {
        bonus=(bonus / 100.0f) * 5.0f;
    } else if(days<10) {
        bonus=(-1.0f *((bonus / 100.0f) * 50.0f));
    }
    //final salary
    gross_salary=(bonus + salary);

    //categorize
    if(days>25) {
        strcpy(category,"excellent");
    } else if(days<10) {
        strcpy(category,"needs improvement");
    }
    //display payrolls details
    printf("id:%d\n",id);
    printf("name:%s\n",name);
    printf("salary:%.2f\n",salary);
    if(bonus>0) {
        printf("bonus= %.2f\n",bonus);
    }
    printf("final salary=%.2f\n",gross_salary);
    printf("performance = %s\n",category);

    return 0;
}
