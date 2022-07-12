#include <stdio.h>
#include <math.h>

double sin_cal(int n, double val);
double cos_cal(int n, double val);
double power(double val, int n);
long factorial(int n);

int main(void)
{
    setvbuf(stdout, NULL, _IONBF, 0);
    double x, radian;
    double result;

    x = 0;
    printf("Enter value of degree's:\n");
    scanf("%lf", &x);

    radian = x*(3.14159/180.0);
    int pow = 0;

    printf("Enter value n:\n");

    scanf("%d", &pow);

    result = cos(radian);
    printf("By Math.h -> cos(%.2lf) = %.4lf\n", x, result);

    if(pow % 2 != 0){
        pow--;
    }

    result = cos_cal(pow,radian);
    printf("By Maclaurin -> cos(%.2lf) = %.4lf\n", x, result);

    result = sin(radian);
    printf("By Math.h -> sin(%.2lf) = %.4lf\n", x, result);

    if(pow % 2 == 0){
        pow--;
    }

    result = sin_cal(pow,radian);
    printf("By Maclaurin -> sin(%.2lf) = %.4lf\n", x, result);

    return 0;
}

double sin_cal(int n, double val){
    if(n==1){
        return val;
    }

    if((n-1)/2 % 2 == 0){
        return (sin_cal(n-2,val) + (power(val,n)/factorial(n)));
    }
    else{
        return (sin_cal(n-2,val) - (power(val,n)/factorial(n)));
    }

}

double cos_cal(int n, double val){
    if(n==0){
        return 1;
    }

    if((n-1)/2 % 2 != 0){
        return (cos_cal(n-2,val) + (power(val,n)/factorial(n)));
    }
    else{
        return (cos_cal(n-2,val) - (power(val,n)/factorial(n)));
    }

}

double power(double val, int n){

    if(n==0){
        return 1;
    }
    else{
        double num = 1;

        for(int i=0; i<n; i++){
            num *= val;
        }
        return num;
    }

}

long factorial(int n)
{
    if (n == 0) {
        return 1;
    }
    else {
        return (n * factorial(n - 1));
    }
}