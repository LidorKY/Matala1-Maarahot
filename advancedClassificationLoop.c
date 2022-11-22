#include "stdio.h"
#include "NumClass.h"

#define true 1;
#define false 0;

int Power(int base, int pow){
int temp = 1;
while(pow != 0){
temp = temp * base;
pow--;
}
return temp;
}
int numLength(int num){
    int counter = 0;
    if(num == 0){
        return 1;
    }
    while(num != 0){
        num = num / 10;
        counter++;
    }
    return counter;
}

int isPalindrome(int num){
int copyNum = num;
int reversedNum = 0;
int counter = numLength(num);
int index = 0;
while(counter != 0){
index = copyNum % 10;
reversedNum = reversedNum + (index)*(Power(10,counter-1));
copyNum = copyNum / 10;
counter--;
}
if(reversedNum == num){
    return true;
}
return false;
}

int isArmstrong(int num){
int counter = 0;
int copyNum = num;
 while(copyNum != 0){
    copyNum = copyNum/10;
    counter++;
}
int sum = 0;
copyNum = num;
int temp;
for(int i = 0; i < counter; i++){
    temp = copyNum%10;
    sum = sum + Power(temp,counter);
    copyNum = copyNum/10;
}
if(sum == num){
    return true;
}
else{
    return false;
}




}

