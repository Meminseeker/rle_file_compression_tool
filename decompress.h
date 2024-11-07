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

    // Loop through the file
    while ((currentChar = fgetc(in)) != EOF)
    {
        // If the current char is a digit, continue
        if (isdigit(currentChar))
        {
            continue;
        }

        // Else, read the following consecutive digits if any
        // Convert the digits to an integer
        count = 0;
        char digit = fgetc(in);
        while (isdigit(digit))
        {
            count = count * 10 + (digit - '0');
            digit = fgetc(in);
        }

        ungetc(digit, in);

        // Write the char to the output file count times
        if (count == 0) count = 1;
        for (int i = 0; i < count; i++)
        {
            fputc(currentChar, out);
        }
    }

    // Close the files
    fclose(in);
    fclose(out);

    printf("File decompressed successfully\n");
    
    return;
}
