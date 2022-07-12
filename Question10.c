#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define RAND 1025

void ran_gen(int array[], int length);
int large_num(int array[], int length);

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
        arr[i] = rand() % RAND;
    }

    printf("Randomly generated list: \n");

    for(int i=0;i<length;i++) {
        printf(("%d "), arr[i]);
    }
    printf("\n");

    printf("Largest num is: %d\n", large_num(arr, length));
}

int large_num(int array[], int length){
    int prev, curr;

    if(length==1){
        return array[length-1];
    }
    else{
        prev = large_num(array, length-1);
        curr = array[length-1];
        if (prev > curr){
            return prev;
        }
        else{
            return curr;
        }
    }

}

