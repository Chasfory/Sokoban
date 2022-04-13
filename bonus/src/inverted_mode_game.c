/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** sokoban.c
*/

#include "sokoban.h"

int check_mouv_player_inverted(game_t *game, int action, int mode_game)
{
    (action == KEY_DOWN) ? mouv_up(game) : 0;
    (action == KEY_UP) ? mouv_down(game) : 0;
    (action == KEY_LEFT) ? mouv_right(game) : 0;
    (action == KEY_RIGHT) ? mouv_left(game) : 0;
    if (check_win(game) == 1) {
        if (display_win(game) == 0) {
            return 0;
        }
        return 1;
    }
    if (check_lose(game) == 2) {
        if (display_loose(game) == 0) {
            return 0;
        }
        return 2;
    }
    return 0;
}
