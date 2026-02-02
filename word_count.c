#include <stdio.h>



int isWhitespace(int ch)
{
    return ch == ' '  || ch == '\t' || ch == '\n';
}

int main(int argc, char *argv[])
{
    int chars = 0;
    int words = 0;
    int lines = 0;
    FILE *fptr;
    if (argc > 2)
        {
        printf("Error: too many arguments\n");

        }
    else if (argc < 2 )
        {
                printf("Using stdin.\n");
                fptr = stdin;
        }
    else
        {
                fptr = fopen(argv[1], "r");
        }




    int ch;
    int in_white = 1;
    while((ch = fgetc(fptr))!=EOF)
        {
                if (ch == '\n')
                {
                        lines++;
                }
                if (isWhitespace(ch))
                {
                        in_white = 1;
                }
                else if(in_white)
                {
                        words++;
                        in_white = 0;
                }
                chars++;
        }


    fclose(fptr);
        printf("chars: %d, words: %d, lines: %d\n", chars, words, lines);
    return 0;
    }


                                 
~

