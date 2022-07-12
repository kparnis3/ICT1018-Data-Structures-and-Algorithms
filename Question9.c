#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define QUICK_ARR 353
#define RAND 1025

void q_sort(int array[]);
void quicksort(int array[], int f, int l);
int part(int array[], int f, int l);
void swap(int* x, int* y);
void repeat(const int array[]);

int main(void)
{
    setvbuf(stdout, NULL, _IONBF, 0);
    srand(time(NULL));
    static int B[QUICK_ARR];

    q_sort(B);

    return 0;
}

void q_sort(int arr[])
{
    /*  populating with randomly generated integers */
    for(int i=0;i<QUICK_ARR;i++) {
        arr[i] = rand() % RAND;
    }

    for(int i=0;i<QUICK_ARR;i++) {
        printf(("%d "), arr[i]);
    }

    printf("\n");

    int first = 0;
    int last = QUICK_ARR - 1;

    quicksort(arr, first , last);
    repeat(arr);

}

void quicksort(int arr[], int f, int l){

    if (f < l)
    {
        int Position = part(arr, f, l);

        quicksort(arr, f, Position-1);
        quicksort(arr, Position+1, l);
    }

}

int part(int array[], int f, int l){

    int pivot = array[l];
    int j = (f - 1);

    for(int i = f; i <= l - 1; i++){
        if(array[i] < pivot){
            j++;
            swap(&array[j], &array[i]);
        }
    }

    swap(&array[j+1], &array[l]);

    return (j+1);
}

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void repeat(const int array[]) {
    int a = 0, amount = 0, num_rep = 0, old_a = 0;
    do {

        if(amount != 0 && old_a == amount){
            printf("Value: [%d], Amount Repeated: [%d]\n", array[a-1], amount);
            num_rep++;
            amount = 0;
        }

        old_a = amount;

        if(array[a] == array[a+1]) {
            amount++;
        }

        a++;
    } while (a != QUICK_ARR);
    if(num_rep==0){
        printf("Array doesn't contain any repetitions!");
    }
}

