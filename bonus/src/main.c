/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** sokoban.c
*/

#include "sokoban.h"
#include "struct_play.h"

static mode_game_t init_mode(void)
{
    mode_game_t opt_game;

    opt_game.maps_mode = NULL;
    opt_game.mode_game = 0;
    opt_game.result_game = 0;
    return opt_game;
}

int main(int ac, char **av)
{
    mode_game_t opt_game = init_mode();

    if (ac != 1) {
        return 84;
    }
    if (choose_game(&opt_game) == 10) {
        return 0;
    }
    if (start_game(&opt_game) == 1) {
        return 1;
    }
    return 0;
}