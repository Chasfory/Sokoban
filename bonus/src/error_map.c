/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** sokoban.c
*/

#include "sokoban.h"

int funct_error_map(char const *map, game_t *game)
{
    int nbr_P = 0;
    int nbr_B = 0;

    for (int tmp = 0; map[tmp + 1]; tmp++) {
        if (map[tmp] == 'P')
            nbr_P += 1;
        if (map[tmp] == 'B')
            nbr_B += 1;
        if (map[tmp] == 'X')
            game->compt_x = game->compt_x + 1;
        if (map[tmp] == 'O')
            game->compt_o = game->compt_o + 1;
        if (map[tmp] == 'D')
            game->compt_d += 1;
        if (map[tmp] == 'A')
            game->compt_a += 1;
        else if (map[tmp] == 'P' || map[tmp] == ' ' || map[tmp] == 'C' ||
        map[tmp] == 'A' || map[tmp] == '#' || map[tmp] == '\n' ||
        map[tmp] == 'B' || map[tmp] == 'Z' || map[tmp] == 'X' ||
        map[tmp] == 'O' || map[tmp] == 'T' || map[tmp] == 'D' || map[tmp] == 'I') {
        } else {
            return -1;
        }
    }
    if (game->compt_x != game->compt_o || nbr_P != 1)
        return -1;
    if (game->compt_d != game->compt_a || nbr_B > 1)
        return -1;
    return 0;
}