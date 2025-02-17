#include<stdio.h>
int main() {
    int choice;
   printf("1.order placed\n");
   printf("2.order confirmed\n");
   printf("3.out for delivery\n");
   printf("4.order delivered\n");
   printf("enter the order status:");
   scanf("%d",&choice)
   switch(choice) {
      case 1 : printf("your order has been placed successfully\n");
      break ;
      case 2: printf("your food is being prepared\n");
      break ;
      case 3: printf("your order is out for delivery\n ");
      break;
      case 4: printf("your order has been delivered.enjoy your meal!");
      break;
      default: printf("invalid input\n");
      break;
   }
    return 0;
}
