#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void decompressFile(const char *inputFile, const char *outputFile)
{
    FILE *in = fopen(inputFile, "r");
    FILE *out = fopen(outputFile, "w");

    if (in == NULL || out == NULL)
    {
        printf("Error opening files\n");
        exit(1);
    }

    char currentChar;
    int count;

    while ((currentChar = fgetc(in)) != EOF)
    {
        currentChar = fgetc(in);

        char digit = fgetc(in);

        // If the char is a '$', then it is a single char
        if (digit == '$' || digit == EOF)
        {
            fputc(currentChar, out);
            ungetc(digit, in);
            continue;
        }

        count = 0;
        while (isdigit(digit))
        {
            count = count * 10 + (digit - '0');
            digit = fgetc(in);
        }

        ungetc(digit, in);

        // Write the char to the output file for count times
        for (int i = 0; i < count; i++)
        {
            fputc(currentChar, out);
        }
    }

    fclose(in);
    fclose(out);

    printf("File decompressed successfully\n");
    
    return;
}
