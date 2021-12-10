/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD01-
** File description:
** bitmap.h
*/

#ifndef bitmap_h
#define bitmap_h

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define magic_number 0x424D

typedef struct __attribute__((packed)) bmp_info_header_s {
    uint32_t size;
    int32_t width;
    int32_t height;
    uint16_t planes;
    uint16_t bpp;
    uint32_t compression;
    int32_t raw_data_size;
    int32_t h_resolution;
    int32_t v_resolution;
    uint32_t palette_size;
    uint32_t important_colors;
} bmp_info_header_t;

typedef struct __attribute__((packed)) bmp_header_s {
    int16_t magic;
    uint32_t size;
    uint16_t app_1;
    uint16_t app_2;
    uint32_t offset;
} bmp_header_t;

#endif