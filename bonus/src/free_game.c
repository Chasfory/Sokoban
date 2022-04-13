/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** sokoban.c
*/

#include "sokoban.h"

void free_game(game_t game)
{
    for (int i = 0; game.new_maps[i] != NULL; i++) {
        free(game.new_maps[i]);
    }
    free(game.new_maps);
    for (int i = 0; game.init_map[i] != NULL; i++) {
        free(game.init_map[i]);
    }
    free(game.init_map);
    for (int j = 0; game.post_table_o[j] != NULL; j++) {
        free(game.post_table_o[j]);
    }
    free(game.post_table_o);
}