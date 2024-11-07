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

    // Get the first char
    currentChar = fgetc(in);

    // Loop through the file
    while ((nextChar = fgetc(in)) != EOF)
    {
        // If the current char is the same as the next char, increment count
        if (currentChar == nextChar)
        {
            count++;
        }
        else
        {
            // Else, write the char and the count to the output file
            if (count > 1)
            {
                fprintf(out, "$%c%d", currentChar, count);
            }
            else
            {
                fprintf(out, "$%c", currentChar);
            }

            // set current char to next char and count to 1
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

    // Close the files
    fclose(in);
    fclose(out);

    printf("File compressed successfully\n");

    return;
}
