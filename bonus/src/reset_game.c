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
    game->post_x_p = game->post_x_init_p;
    game->post_y_p = game->post_y_init_p;
    game->post_x_b = game->post_x_init_b;
    game->post_y_b = game->post_y_init_b;
    game->compt_mov = 0;
}