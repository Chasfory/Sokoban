/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** sokoban.c
*/

#include "sokoban.h"

void reset_game(game_t *game)
{
    for (int i = 0; game->new_maps[i] != NULL; i++) {
        my_strcpy(game->new_maps[i], game->init_map[i]);
    }
    game->post_x = game->post_x_init;
    game->post_y = game->post_y_init;
}