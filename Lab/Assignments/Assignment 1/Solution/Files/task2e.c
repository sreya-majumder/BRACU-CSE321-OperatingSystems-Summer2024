#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int main(){
    char string[1000];
    char *forwardPointer, *backwardPointer;

    printf("Please enter a string: ");
    scanf("%[^\n]s", string);

    int stringLength = strlen(string);
    bool palindrome = true;
    
    forwardPointer = string;
    backwardPointer = string + stringLength - 1;
    
    while(forwardPointer<backwardPointer){
        if (*forwardPointer != *backwardPointer){
            palindrome = false;
            break;
        }
        else{
            forwardPointer = forwardPointer + 1;
            backwardPointer = backwardPointer - 1;
        }
    }
    
    if(palindrome == true){
        printf("Palindrome \n");
    }
    else{
        printf("Not palindrome \n");
    }

    return 0;
}




