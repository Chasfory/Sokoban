/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** sokoban.c
*/

#include "sokoban.h"

void mouv_up(game_t *game)
{
    if (game->new_maps[game->post_y - 1][game->post_x] == ' ' ||
    game->new_maps[game->post_y - 1][game->post_x] == 'O') {
        game->new_maps[game->post_y - 1][game->post_x] = 'P';
        game->new_maps[game->post_y][game->post_x] = ' ';
        game->post_y = game->post_y - 1;
    }
    else if (game->new_maps[game->post_y - 1][game->post_x] == 'X' &&
    game->new_maps[game->post_y - 2][game->post_x] != '#' &&
    game->new_maps[game->post_y - 2][game->post_x] != 'X') {
        game->new_maps[game->post_y - 1][game->post_x] = 'P';
        game->new_maps[game->post_y - 2][game->post_x] = 'X';
        game->new_maps[game->post_y][game->post_x] = ' ';
        game->post_y = game->post_y - 1;
    }
}

void mouv_down(game_t *game)
{
    if (game->new_maps[game->post_y + 1][game->post_x] == ' ' ||
    game->new_maps[game->post_y + 1][game->post_x] == 'O') {
        game->new_maps[game->post_y + 1][game->post_x] = 'P';
        game->new_maps[game->post_y][game->post_x] = ' ';
        game->post_y = game->post_y + 1;
    }
    else if (game->new_maps[game->post_y + 1][game->post_x] == 'X' &&
    game->new_maps[game->post_y + 2][game->post_x] != '#' &&
    game->new_maps[game->post_y + 2][game->post_x] != 'X') {
        game->new_maps[game->post_y + 1][game->post_x] = 'P';
        game->new_maps[game->post_y + 2][game->post_x] = 'X';
        game->new_maps[game->post_y][game->post_x] = ' ';
        game->post_y = game->post_y + 1;
    }
}

void mouv_left(game_t *game)
{
    if (game->new_maps[game->post_y][game->post_x - 1] == ' ' ||
    game->new_maps[game->post_y][game->post_x - 1] == 'O') {
        game->new_maps[game->post_y][game->post_x - 1] = 'P';
        game->new_maps[game->post_y][game->post_x] = ' ';
        game->post_x = game->post_x - 1;
    }
    else if (game->new_maps[game->post_y][game->post_x - 1] == 'X' &&
    game->new_maps[game->post_y][game->post_x - 2] != '#' &&
    game->new_maps[game->post_y][game->post_x -2] != 'X') {
        game->new_maps[game->post_y][game->post_x - 1] = 'P';
        game->new_maps[game->post_y][game->post_x - 2] = 'X';
        game->new_maps[game->post_y][game->post_x] = ' ';
        game->post_x = game->post_x - 1;
    }
}

void mouv_right(game_t *game)
{
    if (game->new_maps[game->post_y][game->post_x + 1] == ' ' ||
    game->new_maps[game->post_y][game->post_x + 1] == 'O') {
        game->new_maps[game->post_y][game->post_x + 1] = 'P';
        game->new_maps[game->post_y][game->post_x] = ' ';
        game->post_x = game->post_x + 1;
    }
    else if (game->new_maps[game->post_y][game->post_x + 1] == 'X' &&
    game->new_maps[game->post_y][game->post_x + 2] != '#' &&
    game->new_maps[game->post_y][game->post_x + 2] != 'X') {
        game->new_maps[game->post_y][game->post_x + 1] = 'P';
        game->new_maps[game->post_y][game->post_x + 2] = 'X';
        game->new_maps[game->post_y][game->post_x] = ' ';
        game->post_x = game->post_x + 1;
    }
}