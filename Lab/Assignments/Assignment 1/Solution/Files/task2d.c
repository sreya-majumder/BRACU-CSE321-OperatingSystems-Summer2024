#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int main(){
    char email[1000];
    char validEmail[]= "sheba.xyz";
    char checkValidEmail[100];
    bool atStart=false;

    printf("Please Enter your email: ");
    scanf("%s", email);

    int j=0;
    
    for (int i=0; i<strlen(email); i = i+1){
        if (email[i]=='@'){
            atStart = true;
            i = i+1;
        }
        if (atStart==true){
            checkValidEmail[j] = email[i];
            j = j+1;
        }
    }

    checkValidEmail[j]='\0';

    if (strcmp(checkValidEmail, validEmail)==0){
        printf("Email address is okay \n");
    }
    else{
        printf("Email address is outdated \n");
    }
    return 0;
}
