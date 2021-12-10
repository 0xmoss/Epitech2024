/*
** EPITECH PROJECT, 2020
** B-PSU-400-LYN-4-1-nmobjdump-
** File description:
** content.c
*/

#include "phaseout.h"

#include "content.h"
#include "open.h"
#include "address.h"
#include "dump.h"
#include "truncated.h"

#include "includes.h"

size_t x32_destroyer(size_t size, char *buffer)
{
    int dellocate = 0;

    dellocate = munmap(buffer, size);
    if (dellocate == -1) 
        return (False);
    return (True);
}

size_t x32_content_get(struct stat stats, int fd, char *path)
{
    long int size = stats.st_size;
    void *buffer = mmap(NULL, size, PROT_READ, MAP_SHARED, fd, 0);
    Elf32_Ehdr *ehdr = NULL;
    Elf32_Shdr *shdr = NULL;
    char *tab = NULL;
    size_t data = 0;

    if (buffer != (void *)(-1) && size != -1) {
        ehdr = (Elf32_Ehdr *)buffer;
        shdr = (Elf32_Shdr *)((char *)buffer + ehdr->e_shoff);
        if (ehdr->e_shstrndx <= 40) {
            tab = buffer + shdr[ehdr->e_shstrndx].sh_offset;
            data = x32_is_trucated(ehdr, shdr, size, path);
            if (data != True)
                return (data);
            x32_dump_header(ehdr, shdr, path, x32_address(shdr, ehdr, tab));
            x32_dump_dump(ehdr, shdr, tab, buffer);
            close(fd);
            return (x32_destroyer(size, buffer));
        }
        return (False);
    }
    return (False);
}
