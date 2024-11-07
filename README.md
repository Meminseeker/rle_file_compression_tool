# RLE File Compression Tool

## Overview

The RLE File Compression Tool is a utility for compressing and decompressing files using Run-Length Encoding (RLE) algorithm. This tool is designed to reduce the size of files by encoding consecutive repeated characters.

## Features

- Compress files using RLE algorithm
- Decompress RLE encoded files
- Simple command-line interface

## Installation

To install the RLE File Compression Tool, clone the repository and navigate to the project directory:

```bash
git clone https://github.com/Meminseeker/rle_file_compression_tool.git
cd rle_file_compression_tool
```

## Build

To build and compile the code, run the following command before first usage:

```bash
make
```

## Usage

### Compress a File

To compress a file, use the following command:

```bash
./main compress <input_file> <output_file>
```

Example Usage:

```bash
./main compress input.txt compressed.txt
```

### Decompress a File

To decompress a file, use the following command:

```bash
./main decompress <input_file> <output_file>
```

Example Usage:

```bash
./main decompress compressed.txt output.txt
```

<!-- ## Contributing

Contributions are welcome! Please fork the repository and create a pull request with your changes.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Contact

For any questions or suggestions, please open an issue or contact the repository owner. -->
