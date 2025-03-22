/* bmp.h - Header file for BMP generation */
#ifndef BMP_H
#define BMP_H

#include <stdio.h>
#include <stdint.h>

#define SQUARE_SIZE 256

#pragma pack(push, 1)
typedef struct {
    uint8_t signature[2];
    uint32_t file_size;
    uint32_t reserved;
    uint32_t data_offset;
} BMPFileHeader;

typedef struct {
    uint32_t dib_size;
    int32_t width;
    int32_t height;
    uint16_t num_planes;
    uint16_t bpp;
    uint32_t compression;
    uint32_t image_size;
    int32_t x_ppm;
    int32_t y_ppm;
    uint32_t num_colors;
    uint32_t important_colors;
} DIBHeader;

typedef struct {
    BMPFileHeader header;
    DIBHeader dib_header;
} BMPHeader;

typedef struct {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} pixel;

typedef struct {
    BMPHeader file_header;
    pixel pixel_data[SQUARE_SIZE][SQUARE_SIZE];
} image;

void generate_bmp(const char *filename, uint8_t red, uint8_t green, uint8_t blue);

#endif // BMP_H
