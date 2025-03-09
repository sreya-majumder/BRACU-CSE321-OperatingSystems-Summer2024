#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int main(){
    printf("Please enter your password: ");
    char password[1000];
    scanf("%s", password);

    bool hasLowerCase = false;
    bool hasUpperCase = false;
    bool hasDigit = false;
    bool hasSpecialChar = false;
    bool hasMissingCase= false;

    for(int i=0; i<strlen(password); i++){
        if(password[i]>='a' && password[i]<='z'){
            hasLowerCase = true;
        }
        else if(password[i]>='A' && password[i]<='Z'){
            hasUpperCase = true;
        }
        else if(password[i]>='0' && password[i]<='9'){
            hasDigit = true;
        }
        else if (password[i]=='_' || password[i]=='$' || password[i]=='#'|| password[i]=='@'){
            hasSpecialChar = true;
        }
    }

    if (hasLowerCase && hasUpperCase && hasDigit && hasSpecialChar){
        printf("OK\n");
    }
    else{
	if (!hasLowerCase){
		printf("Lowercse character missing");
		hasMissingCase = true;
		}
	if (!hasUpperCase){
		if (hasMissingCase){
		    printf(", ");
		}
	printf("Uppercase character missing");
	hasMissingCase = true;
	}
	if (!hasDigit){
		if (hasMissingCase){
		    printf(", ");
		}
	printf("Digit missing");
	hasMissingCase=true;
	}
	if (!hasSpecialChar){
		if (hasMissingCase){
		    printf(", ");
		}
	printf("Special character missing");
	}
    return 0;
    }
}
