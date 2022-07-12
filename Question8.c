#include <stdio.h>
#define LARGE_NUM 9999

double newt_approx(double num);

int main(void)
{
    setvbuf(stdout, NULL, _IONBF, 0);
    double num = 0;

    printf("Enter a number for an approximation of its sq.root\n");
    scanf("%lf", &num);

    double  value = newt_approx(num);
    if(value == -1){
        printf("Error complex number!");
    }
    else{
        printf("Approximation of sq. root: [%.3lf]", value);
    }
    return 0;
}

double newt_approx(double num){

    if(num == 0){

        return num;

    } else if(num <= -1){

        return -1;
    }

    double difference = LARGE_NUM, guess, update_guess, err = 0.001;

    guess = num;

    do{
        update_guess = guess - (((guess*guess) - num) / (guess*2));
        difference = update_guess - guess;

        if(difference < 0){
            difference *= -1;
        }

        guess = update_guess;

    }while(difference > err);


    return guess;
}