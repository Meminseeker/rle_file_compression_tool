#include <stdio.h>
#include <string.h>
#include "compress.h"
#include "decompress.h"

int main(int argc, char *argv[])
{
    if (argc < 4)
    {
        printf("Usage: %s <compress|decompress> <input file> <output file>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "compress") == 0)
    {
        compressFile(argv[2], argv[3]);
    }
    else if (strcmp(argv[1], "decompress") == 0)
    {
        decompressFile(argv[2], argv[3]);
    }
    else
    {
        printf("Invalid command. Use 'compress' or 'decompress'.\n");
        return 1;
    }

    return 0;
}
