# Image Manipulation Project

## Overview

This personal project involves working with and modifying pictures on a computer. The focus is on how computers deal with imagery and modifying an image in specific ways using a straightforward image format, specifically PPM (Portable Pixmap).

## Detailed Description

The project uses concepts such as Color, Color Image, and Row/Column Location, but focuses on dynamic allocation of arrays and file input/output. The image format used is PPM, which is an ASCII text file format for images.

### Features

1. **Rectangle Annotation:** Support drawing filled or unfilled rectangles on an image.
2. **Pattern Annotation:** Annotate an image with a pattern defined in a text file containing zeros and ones.
3. **Image Insertion:** Insert another PPM image at a specified location within the main image, with support for a transparency color.

## Implementation and Design

- Global constants are declared in `constants.h`.
- Dynamic allocation is used for image pixels.
- The project is separated into multiple files with each class contained in a .h and a .cpp file.

## File Structure

- `ColorClass.cpp`, `ColorClass.h`, `ColorClass.o`
- `ColorImageClass.cpp`, `ColorImageClass.h`, `ColorImageClass.o`
- `RectangleClass.cpp`, `RectangleClass.h`, `RectangleClass.o`
- `RowColumnClass.cpp`, `RowColumnClass.h`, `RowColumnClass.o`
- `askForColor.cpp`, `askForColor.h`, `askForColor.o`
- `askForFile.cpp`, `askForFile.h`, `askForFile.o`
- `askForInsertIdx.cpp`, `askForInsertIdx.h`, `askForInsertIdx.o`
- `doClip.cpp`, `doClip.h`, `doClip.o`
- `doClipColor.cpp`, `doClipColor.h`, `doClipColor.o`
- `Makefile`
- Pattern files: `ohdeerPattern.txt`, `ohdeerPattern_extra_col_row.txt`, `ohdeerPattern_invalid_col_row.txt`, `ohdeerPattern_missing_col_row.txt`, `ohdeerPattern_more_val.txt`
- `project3.cpp`, `project3.o`
- `proj3.exe`
- Sample image: `topHat.ppm`

## How to Build and Run

1. Ensure all .h, .cpp files, and the Makefile are in the same directory.
2. Open a terminal in that directory.
3. Run `make` to compile the project.
4. Execute the program with `./proj3.exe`.

## Notes

- This project was originally part of EECS402 Fall 2023 at the University of Michigan but is now a personal project.
- The implementation is based on the specifications provided in the original project description.
