#include <stdio.h>
unsigned long long fibonacciIt(int n);
unsigned long long fibonacciRe(int n);
int main(void) {
    setvbuf(stdout, NULL, _IONBF,0);

    int num = 0;
    unsigned long long temp , str = 0;
    label:
    printf("Please enter a value that's greater or equal to 1\n");
    scanf("%d", &num);

    if(num >= 1) {
        printf("Recursive Fibonacci of %d: ", num);

        for(int i = 0;i<num; i++) {
            printf("%d ", fibonacciRe((i+1)));
        }
        printf("\n");

        printf("Iterative Fibonacci of %d: ", num);
        for(int i = 0;i<num; i++) {
            temp = fibonacciIt((i+1));
            str += temp;
            printf("%d ", temp);
        }
        printf("\n");
        printf("Sum of the first %d nums: %d", num, str);
    }
    else{
        printf("Value doesn't satisfy conditions \n");
        goto label;
    }


    return 0;
}

unsigned long long fibonacciIt(int n)
{
    unsigned long long prepre, pre = 0, nm =1;

  for(int i =1; i<n ;i++)
  {
      prepre = pre;
      pre = nm;
      nm = prepre+pre;
  }
    return nm;
}

unsigned long long fibonacciRe(int n)
{
    if(n <= 1) {
        return n;
    }
    else {
        return (fibonacciRe(n-1) + fibonacciRe(n-2));
    }

}