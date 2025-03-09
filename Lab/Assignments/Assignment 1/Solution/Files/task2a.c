#include <stdio.h>

int main(){
  int num1,num2;
  
  printf("Enter the first number:");
  scanf("%d", &num1);
  
  printf("Enter the second number:");
  scanf("%d", &num2);
  
  if(num1>num2){
    int sub = num1 - num2;
    printf("Subtraction : %d\n" , sub);
  }
  else if(num1<num2){
    int sum = num1 + num2;
    printf("Addition : %d\n" , sum);  
  }
  else{
    int mul = num1 * num2;
    printf("Multiplication : %d\n" , mul);
  }
  return 0;
}
