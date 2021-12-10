/*
** EPITECH PROJECT, 2020
** strace
** File description:
** types.c
*/

#include "strace.h"

const types_t types_d[] = {
    {"void", &sys_void},
    {"char", &sys_char},
    {"char *", &sys_str},
    {"char **", &sys_array},
    {"int", &sys_int},
    {"int[2]", &sys_ptr},
    {"int[]", &sys_ptr},
    {"int *", &sys_ptr},
    {"uint32_t", &sys_uint},
    {"unsigned int", &sys_uint},
    {"long", &sys_long},
    {"unsigned long", &sys_ulong},
    {"u64", &sys_ulong},
    {"size_t", &sys_ulong},
    {"ssize_t", &sys_long},
    {"caddr_t", &sys_str},
    {"ndfs_t", &sys_int},
    {"off_t", &sys_ulong},
    {"key_t", &sys_ulong},
    {"pid_t", &sys_int},
    {"socklen_t", &sys_ulong},
    {"uid_t", &sys_int},
    {"gid_t", &sys_int},
    {"gid_t[]", &sys_ptr},
    {"clock_t", &sys_ulong},
    {"cap_user_header_t", &sys_ptr},
    {"cap_huser_data_t", &sys_ptr},
    {"dev_t", &sys_ulong},
    {"off64_t", &sys_ulong},
    {"cpu_set_t", &sys_ulong},
    {"aio_context_t", &sys_ulong},
    {"mqd_t", &sys_int},
    {"idtype_t", &sys_ulong},
    {"key_serial_t", &sys_ulong},
    {"unimplemented", &sys_unknown},
    {"default", &sys_ptr},
    {NULL, NULL}
};
