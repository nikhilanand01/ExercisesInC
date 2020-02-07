/* worked with Gab Douglas on some of this file */


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
  if(number == 0){
    printf("ERROR: Plese enter a valid number \n");
  } else {
    return number;
  }
}


int addArray(int *integers, int length){
  int sum = 0;
  for (int i = 0; i < (length); i++){
    sum += integers[i];
  }
  return sum;
}

int main(){
  int total=0;
  printf("You can only enter 10 numbers and each number must be less than three digits and positive (1-99).\n");
  int maxLength = 10;
  int integers[maxLength];
  int counter = 0;
  int numb;
  //int flag = 0;

  numb = getInput();
  while (numb != EOF){
    if (counter > maxLength - 1){ /* Stop asking for user input when integer array is full*/
      printf("You've entered more than the max of 10 numbers.\n");
      break;
    }
    else{
    integers[counter] = numb;
    counter++;
    numb = getInput();
    }
  }
  total= addArray(integers, counter);
  printf("The sum of every number you have entered is %i! \n", total);

}
