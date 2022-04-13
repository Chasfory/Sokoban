/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** sokoban.c
*/

#include "sokoban.h"

int error_map(char const *map)
{
    int fd = open(map, O_RDONLY);

    if (fd == -1) {
        return -1;
    }
    close(fd);
    return 0;
}