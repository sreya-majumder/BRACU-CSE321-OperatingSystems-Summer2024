#include<stdio.h>
#include<string.h>

int main(){

  char inpLine[1000],outLine[1000];

  printf("Enter a sentence containing space: ");
  scanf("%[^\n]s", inpLine);

  int j=0;

  for (int i=0; i<strlen(inpLine); i=i+1){
      if (inpLine[i] != ' '){
          outLine[j]=inpLine[i];
          j = j+1;
      }
      else if (inpLine[i] ==' ' && inpLine[i+1]!=' '){
          outLine[j]=inpLine[i];
          j = j+1;
      }
      else{
          continue;
      }
  }

  outLine[j]='\0';
  printf("%s\n", outLine);
  return 0;

}
