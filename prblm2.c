#include<stdio.h>
#include<string.h>
int main() {
    int id;
    char name[40];
    int unit;
    // customer details
    printf("enter customer name\n");
    scanf("%s",name);
    printf("enter customer id:\n");
    scanf("%d",&id);
    printf("enter total units consumed\n");
    scanf("%d",&unit);
    base_bill=100;
   
   
    //calculate bill
    if(0>=unit<=100) {
      base_bill= unit * 5.0f;
    } else if(101<=unit<=300) {
       base_bill=(100 * 5.0f)+ unit * 7.0f;
    } else {
        base_bill= (100 * 5.0f)+(200 * 7.0f) +unit * 10.0f;
    }
    //total bill
   if(base_bill>1000){
    surcharge=(base_bill+(5/100));
   }
total_bill=base_bill+surcharge;
  
    //display details
    printf("customer name:%s\n",name);
    printf("customer id:%d\n",id);
    printf("units consumed:%.2d\n",unit);
     printf("base bill:%d\n",base_bill);
    printf("surcharge:%d\n",surcharge);
    printf("total bill:%d\n",total_bill);
    return 0;
}
