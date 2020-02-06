#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int getInput(){
  char str[3];
  int number;
  puts("Enter a number: ");
  scanf("%2s", str);
  number = atoi(str);
  return number;
}

int addArray(int *integers){
  int sum = 0;
  for (int i = 0; i < (10); i++){
    sum += integers[i];
  }
  return sum;
}

int main(){
  int total=0;
  printf("You can only enter 10 numbers and each number must be less than three digits and positive (0-99).\n");
  int maxLength = 10;
  int integers[maxLength];
  int counter = 0;
  int numb;
  //int flag = 0;

  numb = getInput();
  while (numb != EOF){
    if (counter > maxLength - 2){ /* Stop asking for user input when integer array is full*/
      printf("You've entered more than the max of 10 numbers.\n");
      break;
    }
    else{
    integers[counter] = numb;
    counter++;
    numb = getInput();
    }
  }
  total= addArray(integers);
  printf("The sum of every number you have entered is %i", total);

}
