#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
	int random = 0; 
    // TODO: rewrite this function
	char array[9] = { '[', '(', '{', ' ' , 'a','x', '}', ']', ')' };
	return array[rand() % 9];
}

char *inputString()
{
	//keep extra e to  increase the probability that e is chosen since it's used twice
	char array[10] = { 'a','r','f', 'e','b', 's','g', 'e','c', 't' };
    
	char *stringInput, a; 
	int length =5; 
  stringInput=  malloc(sizeof(char) *length)+1;
  //Cite: https://codereview.stackexchange.com/questions/29198/random-string-generator-in-c
	stringInput[0] = array[rand()%10];
	stringInput[1] = array[rand()%10];
	stringInput[2] = array[rand()%10];
	stringInput[3] = array[rand()%10];
	stringInput[4] = array[rand()%10];
	
	// string length fixed to length 5
	stringInput[5] = '\0';

	return stringInput;

}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'&& s[2] == 's' && s[3] == 'e'&& s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
