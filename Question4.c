#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define RAND 1023

void ran_gen(int array[], int length);

int main(void)
{
    setvbuf(stdout, NULL, _IONBF, 0);
    srand(time(NULL));
    int len = 0;

    printf("Enter the length of list\n");

    scanf("%d", &len);
    while(len<=0){
        printf("Please enter a number greater then 0\n");
        scanf("%d", &len);
    }
    int B[len];

    ran_gen(B, len);

    return 0;
}

void ran_gen(int arr[], int length)
{
    /*  populating with randomly generated integers */
    for(int i=0;i<length;i++) {
        arr[i] = (rand() % RAND)+1;
    }

    printf("Randomly generated list: \n");

    for(int i=0;i<length;i++) {
        printf(("%d "), arr[i]);
    }
    printf("\n");
    printf("\n");

    int matrix[length][length];

    for(int i=0;i<length;i++) {
        for(int j=0;j<length;j++){
            if(i==j || i>j){
                matrix[i][j] = 0;
            }
            else {
                matrix[i][j] = arr[i] * arr[j];
            }
           // printf("%d ",matrix[i][j]);
        }
        //printf("\n");

    }

    int store;
    int count=0;

    for(int i=0;i<length;i++) {
        for(int j=0;j<length;j++){
            if (i<j) {
                store = matrix[i][j];

                for(int k=(i+1);k<length;k++) {
                    for(int l=0;l<length;l++) {
                         if(store==matrix[k][l] && store!=0 && arr[i] != arr[l] && arr[i] != arr[k]){
                             count++;
                             printf("%d. (%d,%d) , (%d,%d) which is equal to %d \n",count, arr[i],arr[j],arr[l],arr[k], matrix[k][l]);
                             matrix[k][l] = 0;
                             matrix[i][j] = 0;
                         }
                    }
                }

            }
        }
    }
    if(count==0){
        printf("There are no 2-pairs in this list!");
    }


}