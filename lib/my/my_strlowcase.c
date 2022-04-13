/*
** EPITECH PROJECT, 2021
** my_strlowcase.c
** File description:
** Task09
*/

#include <unistd.h>

char *my_strlowcase(char *str)
{
    int n = 0;

    while (str[n] != '\0') {
        if (str[n] >= 'A' && str[n] <= 'Z') {
            str[n] = str[n] + 32;
        }
        n++;
    }
    return (str);
}