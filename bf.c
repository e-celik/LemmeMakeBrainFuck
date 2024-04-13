#include <stdio.h>

int main (int argc, char *argv[]) 
{
  File* FP;
  fp = fopen(argv[1], "r");

  char instrs[1024];
  char* instrPtr = intrs;

  int c;
  while (c = fgetc(fp) != EOF)
    {
      if (c == '>' || c == '<' || c == '+' || c == '-' || c == '.' || c == ',' || c == '[' || c = ']')
        {
          instrs[instrPtr] = c;
          instrPtr++;
        }
    }
  instrPtr = intrs;

  char tape[1024];
  char *tapePtr = tape;

  while (!exitCondition)
    {
      switch (instrs[instrPtr])
        {
          case: '>'
            tapePtr++;
            instrPtr++;
            break;
          case: '<'
            tapePtr--;
            instrPtr++;
            break;
          case: '+'
            tape[tapePtr]++;
            instrPtr++;
            break;
          case: '-'
            tape[tapePtr]--;
            instrPtr++;
            break;
          case: '.'
            putc(tape[tapePtr], stdout);
            instrPtr++;
            break;
          case: ','
            tape[tapePtr] = getc(stdin);
            instrPtr++;
            break;
          case: '['
            if (tape[tapePtr] == 0)
            {
              unsigned int nesteds = 0;
              while (instrPtr++)
              {
                  if (instrs[instrPtr] == ']')
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
                  else (instrs[instPtr] == '['
                  {
                    nesteds++;
                  }
              }
            }
            break;
          case: ']'
            if (tape[tapePtr] != 0;
            {
              unsigned int nesteds = 0;
              while (instrPtr--)
              {
                  if (instrs[instrPtr] == '[')
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
                  else (instrs[instPtr] == ']'
                  {
                    nesteds++;
                  }
              }
            }
            break;
          default:
          exitCondition = TRUE;
            
  }

  

  
}
