/*
** EPITECH PROJECT, 2021
** my_strstr.c
** File description:
** Task05
*/

#include <unistd.h>
#include <stdio.h>

char *my_strstr(char *str, char const *to_find)
{
    int n = 0;
    int i = 0;
    int c = 0;

    while (str[i] != '\0' ) {
        n = 0;
        c = i;
        while (to_find[n] == str[c]) {
            if (to_find[n + 1] == '\0') {
                str += i;
                return (str);
            }
            n++;
            c++;
        }
        i++;
    }
    return (NULL);
}