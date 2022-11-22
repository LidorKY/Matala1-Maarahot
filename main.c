#include "stdio.h"
#include "NumClass.h"

int main(){

int x,y;

printf("pls enter your first number: \n");
scanf("%d",&x);
while(x <= 0){
printf("pls enter a number that is bigger than 0: \n");
scanf("%d",&x);  
}

printf("pls enter your second number: \n");
scanf("%d",&y);
while(y < x){
printf("pls enter a number that is bigger than the first number: \n");
scanf("%d",&y); 
}


// printing prime numbers
printf("\nthe Prime numbers between %d and %d are: ",x,y);
for(int i = x; i <= y; i++){
    if(isPrime(i)){
        printf("%d , ",i);
    }
}
printf("\n");

// printing armstrong nubers
printf("\nthe Armstrong numbers between %d and %d are: ",x,y);
for(int i = x; i <= y; i++){
    if(isArmstrong(i)){
        printf("%d , ",i);
    }
}
printf("\n");

//printing strong numbers
printf("t\n he Strong numbers between %d and %d are: ",x,y);
for(int i = x; i <= y; i++){
    if(isStrong(i)){
        printf("%d , ",i);
    }
}
printf("\n");

 //printing palindrome numbers
printf("\nthe Palindrome numbers between %d and %d are: ",x,y);
for(int i = x; i <= y; i++){
    if(isPalindrome(i)){
        printf("%d , ",i);
    }
}

}