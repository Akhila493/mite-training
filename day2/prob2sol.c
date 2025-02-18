#include<stdio.h>

int main() {
    int count;
    int weight;

    printf("Enter the number of products\n");
    scanf("%d",&count);

int acceptedCount=0;
int rejectedCount=0;

    for(int i=1;i<=count;i++) {
        printf("enter weights (in grms):");
        scanf("%d",&weight);

        if(weight>=950 && weight<=1050){
            acceptedCount++;
        }else {
            rejectedCount++;
        }
    }
    printf("\nAccepted products:%d\n",acceptedCount);
    printf("Rejected products:%d\n",rejectedCount);

    return 0;
}
