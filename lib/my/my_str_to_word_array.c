/*
** EPITECH PROJECT, 2021
** my_str_to_word_array.c
** File description:
** Lib
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static int nb_ligne(char *str, char sep)
{
    int compt = 0;
    int j = 0;

    for (; str[j] == sep; j++);
    for (; str[j] != '\0'; j++) {
        if (str[j] == sep) {
            compt++;
        }
    }
    compt++;
    return compt;
}

static int my_strlen_to_word_array(char *str, char sep)
{
    int i = 0;

    for (; str[i] != sep && str[i] != '\0'; i++);
    return i;
}

char **str_to_word_array(char *str, char sep)
{
    int compt_line = nb_ligne(str, sep);
    int l = 0;
    int i = 0;
    int stock = 0;
    char **tmp = malloc(sizeof(char *) * (compt_line + 1));

    for (int j = 0; j < compt_line; j++, i++) {
        stock = my_strlen_to_word_array(&str[i], sep);
        tmp[j] = malloc(sizeof(char) * (stock + 1));
        for (l = 0; l < stock; l++, i++) {
            if (str[i] != sep)
                tmp[j][l] = str[i];
        }
        tmp[j][stock] = '\0';
    }
    tmp[compt_line] = NULL;
    return tmp;
}