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

int isPalindrome(int num){
    int counter = 0;
    int copyNum = num;
    while(copyNum != 0){
        copyNum = copyNum/10;
        counter++;
    }
    int start = 0;
    int end = 0;
    copyNum = num;
    int counter2 = 1;
    for(int i = 0; counter2 < counter; i++){
        start = copyNum%Power(10,counter2);
        end = copyNum%Power(10,counter-1);
        if(start != end){
            return false;
        }
        copyNum = (copyNum - start*(counter2))/10;
        copyNum = copyNum - end*(counter-2);
        counter--;
        counter2++;
        
    }
    return true;
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

