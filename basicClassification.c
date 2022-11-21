#include <stdio.h>
#include "NumClass.h"

#define true 1;
#define false 0;

int factorial (int num){
    if(num == 1){
        return 1;
    }
    return num*factorial(num-1);
}
int isStrong (int num){
int sum = 0;
int temp = 0;
int copyNum = num;
while(copyNum != 0){
    temp = copyNum % 10;
    sum = sum + factorial(temp);
    copyNum = copyNum / 10;
}
if(sum == num ){
    return true;
}
return false;

}

int isPrime(int num){
    for(int i = 2; i < num; i++){
        if(num % i == 0){
            return false;
        }
    }
    return true;
}













