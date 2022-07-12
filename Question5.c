#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int StackFull(const int *StackTop);
int StackEmpty(const int *StackTop);
char StackPush(char var, int *StackTop, char array[]);
double StackPushCal(double var, int *StackTop, double array[]);
double StackPopCal(int *StackTop, const double array[]);
char StackPop(int *StackTop, const char array[]);
void infixtoRPN(char array[], char Rev[]);
void calc(char Rev[]);

int main(void)
{
    setvbuf(stdout, NULL, _IONBF, 0);
    char str[MAX];
    char RPN[100];
    int num_present = 0;
    label:
    printf("Enter an arithmetic expression in infix:\n");
    scanf("%s", &str);

    for(int i=0; i<strlen(str); i++){

        if(str[i]>47 && str[i]<58){
            num_present = 1;
        }
        else if ((str[i]>39 && str[i]<44) || str[i]==45 || str[i] ==47){

        }
        else{
            printf("Error input invalid: ");
            printf("%c\n", str[i]);
            goto label;
        }

        if(num_present == 0){
            printf("Syntax error\n");
            goto label;

        }

    }

    infixtoRPN(str, RPN);

    printf("RPN format: ");

    for(int i=0; i<strlen(RPN); i++){
        printf("%c", RPN[i]);
    }
    printf("\n");

    calc(RPN);

    return 0;
}

void calc(char Rev[]){
    int Top = -1;
    double first, last;
    double stack_2[100];

    for(int i=0; i<strlen(Rev); i++) {
        if(Rev[i] == 43 || Rev[i] == 45 || Rev[i] == 42 || Rev[i] == 47){
            first = StackPopCal(&Top, stack_2);
            last = StackPopCal(&Top, stack_2);
            if(Rev[i]==43){
                StackPushCal((last+first), &Top, stack_2);
            }
            else if(Rev[i]==45){
                StackPushCal((last-first), &Top, stack_2);
            }
            else if(Rev[i]==42){
                StackPushCal((last*first), &Top, stack_2);
            }
            else{
                StackPushCal((last/first), &Top, stack_2);
            }

        }else{
            StackPushCal(Rev[i]- 48 , &Top, stack_2);
        }

    }
    printf("%.2lf",stack_2[0]);

}


void infixtoRPN(char array[], char Rev[]){
    char stack[100];
    char pre, temp;
    int Top = -1, k = 0;

    for(int i=0; i<strlen(array); i++) {
        if (array[i] > 47 && array[i] < 58) { //between 0-9
            Rev[k] = array[i];
            k++;
        }
        else if ((array[i] < 48 || array[i] > 57) && StackEmpty(&Top)) { //other than 0-9 and stack is empty 1+2*(3-4)
            pre = StackPush(array[i], &Top, stack);
        }
        else if (array[i] == 40) { // ( always put
            pre = StackPush(array[i], &Top, stack);
        }
        else if (array[i] == 41) { //always pop at )
            do{
                temp=StackPop(&Top, stack);

                if(temp!=40) {
                    Rev[k] = temp;
                    k++;
                }
                pre = 40;
                if(k==100){
                    printf("Error incorrect brackets");
                    exit(-1);
                }
            }while(temp!=40);
        }
        else if(pre == 40 && (array[i] == 42 || array[i] == 43 || array[i] == 45 || array[i] == 47)){ // on stack ( push any arithmetic
            pre = StackPush(array[i], &Top, stack);
        }
        else if((pre == 43 || pre == 45) && (array[i] == 42 || array[i] == 47)){ //* and - highest precedence
            pre = StackPush(array[i], &Top, stack);
        }
    }

    while(!StackEmpty(&Top)){
        Rev[k] = StackPop(&Top, stack);
        k++;
    }

}

int StackFull(const int *StackTop){
    if(*StackTop == MAX){
        return 1;
    }
    else{
        return 0;
    }

}

int StackEmpty(const int *StackTop){
    if(*StackTop == -1){
        return 1;
    }
    else{
        return 0;
    }
}

char StackPush(char var, int *StackTop, char array[]){
    if(!StackFull(StackTop)){
        *StackTop = *StackTop+1;
        array[*StackTop] = var;
        return var;
    }else{
        return 0;
    }

}

double StackPushCal(double var, int *StackTop, double array[]){
    if(!StackFull(StackTop)){
        *StackTop = *StackTop+1;
        array[*StackTop] = var;
        return var;
    }else{
        return 0;
    }

}

char StackPop(int *StackTop, const char array[]){
    char temp_var;
    if(!StackEmpty(StackTop)){
        temp_var = array[*StackTop];
        *StackTop = *StackTop -1;

        return temp_var;
    }
    else{
        return 0;
    }
}

double StackPopCal(int *StackTop, const double array[]){
    double temp_var;
    if(!StackEmpty(StackTop)){
        temp_var = array[*StackTop];
        *StackTop = *StackTop -1;

        return temp_var;
    }
    else{
        return 0;
    }
}