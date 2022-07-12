#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SHELL_ARR 301
#define QUICK_ARR 353
#define MERG_ARR (SHELL_ARR + QUICK_ARR)
#define RAND 1025

void s_sort(int array[]);
void q_sort(int array[]);

void shellsort(int array[], int k);
void quicksort(int array[], int f, int l);
void mergesort(const int arr_A[],const int arr_B[], int arr_C[]);

int part(int array[], int f, int l);
void swap(int* x, int* y);

int main(void)
{
    setvbuf(stdout, NULL, _IONBF, 0);
    srand(time(NULL));

    static int A[SHELL_ARR];
    static int B[QUICK_ARR];
    static int C[MERG_ARR];

    s_sort(A);
    q_sort(B);
    mergesort(A,B,C);

    printf("ShellSort: ");

    for(int i=0;i<SHELL_ARR;i++) {
        printf(("%d "), A[i]);
    }

    printf("\nQuickSort: ");

    for(int i=0;i<QUICK_ARR;i++) {
        printf(("%d "), B[i]);
    }

    printf("\nMergeSort: ");

    for(int i=0;i<MERG_ARR;i++) {
        printf(("%d "), C[i]);
    }


    return 0;
}

void s_sort(int array[])
{
    /* populating with randomly generated integers */
    for(int i=0;i<SHELL_ARR;i++) {

        array[i] = rand() % RAND;
    }
    int g = SHELL_ARR/2;
    shellsort(array, g);
}

void shellsort(int array[], int k){
    while (k > 0){
        int j;
        for(int i = k; i < SHELL_ARR; i++){

            int temp = array[i];

        for(j = i; j >= k && array[j - k] > temp; j -= k){
            array[j] = array[j - k];
        }
        array[j] = temp;
        }

        if (k == 2){
            k = 1;
        }

        else{
           k = k/2;
        }
    }
}


void q_sort(int arr[])
{
   /*  populating with randomly generated integers */
    for(int i=0;i<QUICK_ARR;i++) {
        arr[i] = rand() % RAND;
    }

    int first = 0;
    int last = QUICK_ARR - 1;

   quicksort(arr, first , last);

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

void mergesort(const int arr_A[], const int arr_B[], int arr_C[]){

    int point_A = 0, point_B = 0, point_C = 0;

    do{
          if (arr_A[point_A] <= arr_B[point_B]) {
              arr_C[point_C++] = arr_A[point_A++];
          } else {
              arr_C[point_C++] = arr_B[point_B++];
          }

    }while(point_A < SHELL_ARR && point_B < QUICK_ARR);

    while(point_A < SHELL_ARR){
        arr_C[point_C++] = arr_A[point_A++];
    }

    while (point_B < QUICK_ARR){
        arr_C[point_C++] = arr_B[point_B++];
    }

}