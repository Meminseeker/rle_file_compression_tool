#include <stdio.h>
#include "compress.h"
#include "decompress.h"

int main()
{
    compressFile("input.txt", "compressed.rle");
    decompressFile("compressed.rle", "output.txt");

    return 0;
}
