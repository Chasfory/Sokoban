/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** sokoban.c
*/

#include "sokoban.h"

static sfMusic *music(void)
{
    sfMusic *son = sfMusic_createFromFile("music/game.ogg");
    sfMusic_setVolume(son, 5);
    sfMusic_play(son);
    return son;
}

game_t init_struct(void)
{
    game_t game;

    game.compt_o = 0;
    game.compt_x = 0;
    game.compt_a = 0;
    game.compt_d = 0;
    game.compt_mov = 0;
    game.post_x_p = 0;
    game.post_x_init_p = 0;
    game.post_y_p = 0;
    game.post_y_init_p = 0;
    game.post_x_b = 0;
    game.post_x_init_b = 0;
    game.post_y_b = 0;
    game.post_y_init_b = 0;
    game.win = 0;
    game.lose = 0;
    game.new_maps = NULL;
    game.post_table_o = NULL;
    game.init_map = NULL;
    game.son = music();
    return game;
}