#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void SieveofEratosthenes(int n);
bool func(int isprime);

int main(void)
{
    int num;
    setvbuf(stdout, NULL, _IONBF, 0);

    printf("Enter a number to check whether or not its prime\n");
    scanf("%d", &num);

    if(func(num)){
        printf("Is a prime number\n");
    }
    else{
        printf("Isnt a prime number\n");
    }
    SieveofEratosthenes(num);


    return 0;
}

bool func(int isprime){

    if (isprime<2) return false;
    else{
        for(int i=2; i<= sqrt(isprime); i++){
         if(isprime%i==0) return false;
        }
        return true;
    }
}

void SieveofEratosthenes(int n){
  bool is_prime[n+1];

  for (int i=0; i<=n; i++){
      is_prime[i] = 1;
  }

  for(int i = 2; i<=n; i++){
      if(is_prime[i]==1){
          for(int j = i*i; j<=n; j += i){
              is_prime[j] = 0;
          }
      }
  }

  printf("Sieve of Eratosthenes: ");
  for(int i = 2; i<=n; i++){
      if(is_prime[i] == 1){
          printf("%d ",i);
      }
  }

}