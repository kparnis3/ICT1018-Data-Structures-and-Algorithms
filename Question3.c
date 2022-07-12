#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define RAND 1025

void extreme_pts(int array[], int length);

int main(void)
{
    setvbuf(stdout, NULL, _IONBF, 0);
    srand(time(NULL));
    int n = 0;
    int count = 0;

    printf("Enter size of array n: \n");
    scanf("%d", &n);
    int A[n];

    extreme_pts(A, n);
    printf("Its extreme points: ");

    for(int i=1;i<n-1;i++) {
        if((A[i] > A[i+1] && A[i-1] < A[i]) || (A[i] < A[i+1] && A[i-1] > A[i])) {
            printf(("%d "), A[i]);
            count++;
        }

    }
    if(count==0) {
        printf("SORTED");
    }
    return 0;
}

void extreme_pts(int array[], int length)
{
    /* populating with randomly generated integers */
    for(int i=0;i<length;i++) {

        array[i] = rand() % RAND;
    }

    printf("Randomly generated array : ");

    for(int i=0;i<length;i++) {
        printf(("%d "), array[i]);
    }
    printf("\n");


}








