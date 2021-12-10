/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD01-
** File description:
** bitmap_header.c
*/

#include "bitmap.h"

void make_bmp_info_header(bmp_header_t *header, size_t size)
{
    *header = malloc(sizeof(*header));

    header->size = 40
    header->height = size;
    header->width = size;
    header->planes = 1;
    header->bpp = 32;
    header->compression = 0;
    header->raw_data_size = size * size * sizeof(uint32_t);
    header->h_resolution = 0;
    header->v_resolution = 0;
    header->palette_size = 0;
    header->important_colors = 0;
}

void make_bmp_header(bmp_info_header_t *header, size_t size)
{
    *header = malloc(sizeof(*header));

    header->magic = magic_number;
    header->size = size * size;
    header->offset = sizeof(bmp_info_header_t) + sizeof(bmp_header_t);
}