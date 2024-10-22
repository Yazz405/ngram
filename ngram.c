#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
  Acknowledgement:
  - https://www.geeksforgeeks.org/printf-in-c/
  - class mentors
*/

//moving every element in the arr 1 to the left and adding newElement to the end
void ressetingArray(char arr[], char newElement, int length) {

  for (int i = 0; i < length-1; i++ ) {
    arr[i] = arr[i+1];
  }

  arr[length - 1] = newElement;
}//resetingArray


// Prints a single ngram with the first N-1 characters coming from arr and the last
//character coming from newElement
void printValues(char arr[], char newElement, int length) {

  for (int i = 0; i < length; i++ ) {
    printf("%c", arr[i]);
  }
  printf("%c\n", newElement);

}//printValues


int main(int argc, char** argv) {

  char ch;

  // Make sure the user provided an N parameter on the command line
  if (argc != 2) {
    fprintf(stderr, "Usage: %s N (N must be >= 1)\n", argv[0]);
    exit(1);
  }

  // Convert the N parameter to an integer
  int N = atoi(argv[1]);

  // Make sure N is >= 1
  if (N < 1) {
    fprintf(stderr, "Invalid N value %d\n", N);
    exit(1);
  }

  //read from standard input and print out ngrams until you reach the end of the input

  ch = getchar();
  int count = 0;
  char temp[N-1];

  //printing the first ngram

  //Initializing the first N-1 elements into temp
  temp[0] = ch;
  for (int i = 1; i < N-1; i++) {
    temp [i] = getchar();
    count++;
  }

  //case for when N == 1
  if (N == 1 && ch != EOF) {
    printf("%c\n", ch);
  }

  ch = getchar();

  //check for when the length of string is < N
  if (ch == EOF){
    return 0;
  }

  printValues(temp, ch, N-1);


  //reading the rest of the input
  while (ch != EOF) {

    //reset array
    ressetingArray(temp, ch, N-1);
    ch = getchar();

    //reset count
    if (count >= N) {
      count = 0;
    }

    //when there are not enough characters to create a full ngram
    if (ch == EOF) {
      break;
    }

    printValues(temp, ch, N-1);
    count++;

  }// while

  return 0;
}//main
