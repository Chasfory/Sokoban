/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** sokoban.c
*/

#include "sokoban.h"

game_t init_struct(void)
{
    game_t game;

    game.compt_o = 0;
    game.compt_x = 0;
    game.post_x = 0;
    game.post_x_init = 0;
    game.post_y = 0;
    game.post_y_init = 0;
    game.win = 0;
    game.lose = 0;
    game.new_maps = NULL;
    game.post_table_o = NULL;
    game.init_map = NULL;
    return game;
}