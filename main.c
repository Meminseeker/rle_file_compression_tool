#include <stdio.h>
#include "compress.h"
#include "decompress.h"

int main()
{
    compressFile("input.txt", "compressed.txt");
    decompressFile("compressed.txt", "output.txt");

    return 0;
}
