/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** sokoban.c
*/

#include "sokoban.h"

int check_win(game_t *game)
{
    game->win = 0;
    for (int i = 0; game->new_maps[i]; i++) {
        for (int j = 0; game->new_maps[i][j] != '\0'; j++) {
            if (game->post_table_o[i][j] == 'O' &&
            game->new_maps[i][j] == ' ') {
                game->new_maps[i][j] = 'O';
            }
            if (game->post_table_o[i][j] == 'T' &&
            game->new_maps[i][j] == ' ') {
                game->new_maps[i][j] = 'T';
            }
            if (game->post_table_o[i][j] == 'I' &&
            game->new_maps[i][j] == ' ') {
                game->new_maps[i][j] = 'I';
            }
            if (game->post_table_o[i][j] == 'A' &&
            game->new_maps[i][j] == ' ') {
                game->new_maps[i][j] = 'A';
            }
            else if (game->post_table_o[i][j] == 'O' &&
            game->new_maps[i][j] == 'X') {
                game->win = game->win + 1;
            }
            else if (game->post_table_o[i][j] == 'A' &&
            game->new_maps[i][j] == 'D') {
                game->win = game->win + 1;
            }
        }
    }
    if (game->win == (game->compt_o + game->compt_a)) {
        return 1;
    }
    return 0;
}

static void check_post_square_tetris(game_t *game, int i, int j)
{
    if (game->new_maps[i][j] == 'X' &&
    (((game->new_maps[i + 1][j] == '#' ||
    game->new_maps[i + 1][j] == 'X') &&
    (game->new_maps[i][j - 1] == '#' ||
    game->new_maps[i][j - 1] == 'X')) ||
    ((game->new_maps[i][j + 1] == '#' ||
    game->new_maps[i][j + 1] == 'X') &&
    (game->new_maps[i + 1][j] == '#' ||
    game->new_maps[i + 1][j] == 'X')) ||
    ((game->new_maps[i - 1][j] == '#' ||
    game->new_maps[i - 1][j] == 'X') &&
    (game->new_maps[i][j - 1] == '#' ||
    game->new_maps[i][j - 1] == 'X')) ||
    ((game->new_maps[i - 1][j] == '#' ||
    game->new_maps[i - 1][j] == 'X') &&
    (game->new_maps[i][j + 1] == '#' ||
    game->new_maps[i][j + 1] == 'X'))))
        game->lose = game->lose + 1;
}

int check_lose_tetris(game_t *game)
{
    game->lose = 0;
    for (int i = 0; game->new_maps[i]; i++) {
        for (int j = 0; game->new_maps[i][j] != '\0'; j++) {
            check_post_square_tetris(game, i, j);
        }
    }
    if (game->lose == game->compt_x)
        return 2;
    return 0;
}

static void check_post_square(game_t *game, int i, int j)
{
    if (game->new_maps[i][j] == 'X' &&
    (((game->new_maps[i + 1][j] == '#' ||
    game->new_maps[i + 1][j] == 'X') &&
    (game->new_maps[i][j - 1] == '#' ||
    game->new_maps[i][j - 1] == 'X')) ||
    ((game->new_maps[i][j + 1] == '#' ||
    game->new_maps[i][j + 1] == 'X') &&
    (game->new_maps[i + 1][j] == '#' ||
    game->new_maps[i + 1][j] == 'X')) ||
    ((game->new_maps[i - 1][j] == '#' ||
    game->new_maps[i - 1][j] == 'X') &&
    (game->new_maps[i][j - 1] == '#' ||
    game->new_maps[i][j - 1] == 'X')) ||
    ((game->new_maps[i - 1][j] == '#' ||
    game->new_maps[i - 1][j] == 'X') &&
    (game->new_maps[i][j + 1] == '#' ||
    game->new_maps[i][j + 1] == 'X'))))
        game->lose = game->lose + 1;
}

int check_lose(game_t *game)
{
    game->lose = 0;
    for (int i = 0; game->new_maps[i]; i++) {
        for (int j = 0; game->new_maps[i][j] != '\0'; j++) {
            check_post_square(game, i, j);
        }
    }
    if (game->lose == game->compt_x)
        return 2;
    return 0;
}