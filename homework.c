#include<stdio.h>
int main(){
    char name[30];
    int id , units , total , bill;
    float surcharge;
    printf("Enter Customer Name : ");
    scanf("%s",name);
    printf("Enter Customer ID : ");
    scanf("%d",&id);
    printf("Enter Total Units Consumed : ");
    scanf("%d",&units);
   
    if(units>=0 && units<=100){
        bill = 100 + (5*units);
    }else if(units>=101 && units<=300){
         bill = 100 + (7*units);
    }else if(units>=300 && units<=1000){
         bill = 100 + (10*units);
    }else{
        printf("Invalid Input");
    }
   
    printf("Customer  Name : %s\n", name);
    printf("Customer ID : %d\n", id);
    printf("Units Consumed : %d\n", units);
   
    if(bill>1000){
        surcharge = bill*5/100;
        total = bill + surcharge;
        printf("Base Bill : %d \n",bill);
        printf("Surcharge : %f\n", surcharge);
        printf("Total Bill : %d\n",total);
    }else if(bill<=1000){
       printf("Base Bill : %d\n", bill);
       printf("Surcharge : 0.0\n");
       printf("Total Bill : %d\n", bill);
    }
return 0;
   
}
