#include <stdio.h>
#include <stdbool.h>

int main (int argc, char *argv[]) 
{
  FILE* fp;
  fp = fopen(argv[1], "r");

  if (fp == NULL)
  {
    printf("Error");
  }
  else{
    printf("GoodRead\n");
  }

  char instrs[1024];
  char* instrPtr = instrs;

  int c;
  while ((c = fgetc(fp)) != EOF)
    {
      if (c == '>' || c == '<' || c == '+' || c == '-' || c == '.' || c == ',' || c == '[' || c == ']')
        {
          *instrPtr = c;
          instrPtr++;
        }
    }
  instrPtr = instrs;

  char tape[1024];
  char *tapePtr = tape;

  bool exitCondition = 0;

  while (!exitCondition)
    {
      switch (*instrPtr)
        {
          case '>':
            tapePtr++;
            instrPtr++;
            break;
          case '<':
            tapePtr--;
            instrPtr++;
            break;
          case '+':
            (*tapePtr)++;
            instrPtr++;
            break;
          case '-':
            (*tapePtr)--;
            instrPtr++;
            break;
          case '.':
            printf("%c", *tapePtr);
            instrPtr++;
            break;
          case ',':
            *tapePtr = getc(stdin);
            instrPtr++;
            break;
          case '[':
            if (*tapePtr == 0)
            {
              unsigned int nesteds = 0;
              while (instrPtr++)
              {
                  if (*instrPtr == ']')
                  {
                    if (nesteds == 0)
                    {
                      instrPtr++;
                      break;
                    }
                    else
                    {
                      nesteds--;
                    }
                  }
                  else if (*instrPtr == '[')
                  {
                    nesteds++;
                  }
              }
            }
            break;
          case ']':
            if (*tapePtr != 0)
            {
              unsigned int nesteds = 0;
              while (instrPtr--)
              {
                  if (*instrPtr == '[')
                  {
                    if (nesteds == 0)
                    {
                      instrPtr++;
                      break;
                    }
                    else
                    {
                      nesteds--;
                    }
                  }
                  else if (*instrPtr == ']')
                  {
                    nesteds++;
                  }
              }
            }
            break;
          default:
          exitCondition = 1;
            
    }

  

  
  }
  printf("END!");

}
