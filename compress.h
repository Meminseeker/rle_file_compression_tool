#include <stdio.h>
#include <stdlib.h>

void compressFile(const char *inputFile, const char *outputFile)
{
    FILE *in = fopen(inputFile, "r");
    FILE *out = fopen(outputFile, "w");

    if (in == NULL || out == NULL)
    {
        printf("Error opening files\n");
        exit(1);
    }

    char currentChar, nextChar;
    int count = 1;

    currentChar = fgetc(in);

    while ((nextChar = fgetc(in)) != EOF)
    {
        if (currentChar == nextChar)
        {
            count++;
        }
        else
        {
            if (count > 1)
            {
                fprintf(out, "$%c%d", currentChar, count);
            }
            else
            {
                fprintf(out, "$%c", currentChar);
            }

            currentChar = nextChar;
            count = 1;
        }
    }

    // Handle the last char
    if (count > 1)
    {
        fprintf(out, "$%c%d", currentChar, count);
    }
    else
    {
        fprintf(out, "$%c", currentChar);
    }

    fclose(in);
    fclose(out);

    printf("File compressed successfully\n");

    return;
}
