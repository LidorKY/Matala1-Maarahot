#include <stdio.h>
#include "NumClass.h"

#define true 1;
#define false 0;

int numLength(int num){
if(num == 0){
    return 0;
}
return numLength(num/10) + 1;
}

int Power(int base, int pow){
    if(pow == 0){
        return 1;
    }
    return base*Power(base,pow-1);
}
/*
int isPalindrome (int num){
if ((num >= 0)&&(num <= 9)){
    return true;
}

int counter = numLength(num);
int temp = Power(10,counter-1);
int start  = (num - (num % temp))/temp;
int end = num % 10;

if(start != end){
    return false;
}

num = num - (start*temp);
num = num / 10;

return ((1)&&(isPalindrome(num)));
}
*/

int isPalindrome (int num){
if(numLength(num) == 1){
    return true;
}
if(num == reverse(num)){
    return true;
}
return false;
}

int reverse (int num){
if(numLength(num) == 1){
    return num;
}

int counter = numLength(num);
int index = num % 10;
int temp = Power(10,counter-1);

return index*temp + reverse(num/10);
}

int isArmstrong (int num){

int counter = numLength(num);

if(isArmstrongRec(num,counter) == num){
    return true;
}
return false;
}

int isArmstrongRec(int num, int counter){
if ((num >= 0)&&(num <= 9)){
    return Power(num,counter);
}
int temp = num % 10;
num = num / 10;

return Power(temp,counter) + isArmstrongRec(num,counter);
}






