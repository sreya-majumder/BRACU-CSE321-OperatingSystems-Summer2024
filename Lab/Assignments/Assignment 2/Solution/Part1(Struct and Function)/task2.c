#include <stdio.h>

// Declaring a function for checking perfect number
int isPerfectNumber(int number){
    int summation = 0;

    //Calculating the summation of the number's positve divisors
    for(int num2 = 1; num2<number; num2++){
        if(number%num2 == 0){
            summation += num2;
        }
    }

    //Checking whether the number and the summation is equal or not 
    if (number == summation){
        return number;
    }
    else{
        return -1;
    }
}

int main(){
    int startingNumber, endingNumber;

    //Taking the inputs
    scanf("%d", &startingNumber);
    scanf("%d", &endingNumber);

    //Checking all the numbers between the interval is perfect or not
    for (int num1 = startingNumber; num1<=endingNumber; num1++){
        if (num1==isPerfectNumber(num1)){
            printf("%d\n",num1);
        }
    }
    return 0;
}
