/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** sokoban.c
*/

#include "sokoban.h"

int my_strlen_compt(char **new_maps)
{
    int tmp;

    for (tmp = 0; new_maps[tmp]; tmp++);
    return tmp;
}

int recup_longest_line(game_t *game)
{
    int longest_line = 0;
    int tmp = 0;

    for (int i = 0; game->new_maps[i]; i++) {
        tmp = my_strlen(game->new_maps[i]);
        if (longest_line < tmp) {
            longest_line = tmp;
        }
    }
    return longest_line;
}