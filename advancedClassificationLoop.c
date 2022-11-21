#include "stdio.h"
#include "NumClass.h"

#define true 1;
#define false 0;

int Power(int base, int pow){
if(pow == 0){
    return true;
}
int n = base;
for(int i = 1; i < pow; i++){
    base *= n;
}
return base;
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

int isPalindrome (int a){
int tmp=0;
int tmp2=a;

while(tmp2!=0){
    tmp2=tmp2/10;
    tmp++;
    }
    tmp2=tmp;
for(int i=0;i<tmp2/2;i++){
   if(a/Power(tmp-1,10)!=a%10){
        return 0;
   }
    a-=(a/Power(tmp-1,10))*Power(tmp-1,10);
    a=a/10;
    tmp-=2;
    }
    return 1;
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

