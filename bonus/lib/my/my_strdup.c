/*
** EPITECH PROJECT, 2021
** my_strdup.c
** File description:
** infinadd
*/

#include <stdlib.h>

#include "my.h"

char *my_strdup(const char *src)
{
    char *str = malloc(sizeof(char) * (my_strlen(src) + 1));

    if (str == NULL) {
        return NULL;
    }
    return my_strcpy(str, src);
}