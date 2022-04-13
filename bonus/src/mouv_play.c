/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** sokoban.c
*/

#include "sokoban.h"

void mouv_up(game_t *game)
{
    if (game->new_maps[game->post_y_p - 1][game->post_x_p] == ' ' ||
    game->new_maps[game->post_y_p - 1][game->post_x_p] == 'O' ||
    game->new_maps[game->post_y_p - 1][game->post_x_p] == 'A') {
        game->new_maps[game->post_y_p - 1][game->post_x_p] = 'P';
        game->new_maps[game->post_y_p][game->post_x_p] = ' ';
        game->post_y_p = game->post_y_p - 1;
        game->compt_mov += 1;
    }
    else if (game->new_maps[game->post_y_p - 1][game->post_x_p] == 'X' &&
    game->new_maps[game->post_y_p - 2][game->post_x_p] != '#' &&
    (game->new_maps[game->post_y_p - 2][game->post_x_p] != 'X' &&
    game->new_maps[game->post_y_p - 2][game->post_x_p] != 'D')) {
        game->new_maps[game->post_y_p - 1][game->post_x_p] = 'P';
        game->new_maps[game->post_y_p - 2][game->post_x_p] = 'X';
        game->new_maps[game->post_y_p][game->post_x_p] = ' ';
        game->post_y_p = game->post_y_p - 1;
        game->compt_mov += 1;
    }
    else if (game->new_maps[game->post_y_p - 1][game->post_x_p] == 'D' &&
    game->new_maps[game->post_y_p - 2][game->post_x_p] != '#' &&
    (game->new_maps[game->post_y_p - 2][game->post_x_p] != 'X' &&
    game->new_maps[game->post_y_p - 2][game->post_x_p] != 'D')) {
        game->new_maps[game->post_y_p - 1][game->post_x_p] = 'P';
        game->new_maps[game->post_y_p - 2][game->post_x_p] = 'D';
        game->new_maps[game->post_y_p][game->post_x_p] = ' ';
        game->post_y_p = game->post_y_p - 1;
        game->compt_mov += 1;
    }
    else if (game->new_maps[game->post_y_p - 1][game->post_x_p] == 'T') {
        for (int i = 0; game->new_maps[i]; i++) {
            for (int j = 0; game->new_maps[i][j]; j++) {
                if (game->new_maps[i][j] == 'I') {
                    game->new_maps[game->post_y_p][game->post_x_p] = ' ';
                    game->new_maps[i][j] = 'P';
                    game->post_y_p = i;
                    game->post_x_p = j;
                }
            }
        }
    }
    else if (game->new_maps[game->post_y_p - 1][game->post_x_p] == 'I') {
        for (int i = 0; game->new_maps[i]; i++) {
            for (int j = 0; game->new_maps[i][j]; j++) {
                if (game->new_maps[i][j] == 'T') {
                    game->new_maps[i][j] = 'P';
                    game->new_maps[game->post_y_p][game->post_x_p] = ' ';
                    game->post_y_p = i;
                    game->post_x_p = j;
                }
            }
        }
    }
    else if (game->new_maps[game->post_y_p - 1][game->post_x_p] == 'C') {
        for (int i = 0; game->new_maps[i]; i++) {
            for (int j = 0; game->new_maps[i][j]; j++) {
                if (game->new_maps[i][j] == 'Z') {
                    game->new_maps[i][j] = ' ';
                }
            }
        }
        game->new_maps[game->post_y_p][game->post_x_p] = ' ';
        game->new_maps[game->post_y_p - 1][game->post_x_p] = 'P';
        game->post_y_p = game->post_y_p - 1;
    }
}

void mouv_down(game_t *game)
{
    if (game->new_maps[game->post_y_p + 1][game->post_x_p] == ' ' ||
    game->new_maps[game->post_y_p + 1][game->post_x_p] == 'O' ||
    game->new_maps[game->post_y_p + 1][game->post_x_p] == 'A') {
        game->new_maps[game->post_y_p + 1][game->post_x_p] = 'P';
        game->new_maps[game->post_y_p][game->post_x_p] = ' ';
        game->post_y_p = game->post_y_p + 1;
        game->compt_mov += 1;
    }
    else if (game->new_maps[game->post_y_p + 1][game->post_x_p] == 'X' &&
    game->new_maps[game->post_y_p + 2][game->post_x_p] != '#' &&
    (game->new_maps[game->post_y_p + 2][game->post_x_p] != 'X' &&
    game->new_maps[game->post_y_p + 2][game->post_x_p] != 'D')) {
        game->new_maps[game->post_y_p + 1][game->post_x_p] = 'P';
        game->new_maps[game->post_y_p + 2][game->post_x_p] = 'X';
        game->new_maps[game->post_y_p][game->post_x_p] = ' ';
        game->post_y_p = game->post_y_p + 1;
        game->compt_mov += 1;
    }
    else if (game->new_maps[game->post_y_p + 1][game->post_x_p] == 'D' &&
    game->new_maps[game->post_y_p + 2][game->post_x_p] != '#' &&
    (game->new_maps[game->post_y_p + 2][game->post_x_p] != 'X' &&
    game->new_maps[game->post_y_p + 2][game->post_x_p] != 'D')) {
        game->new_maps[game->post_y_p + 1][game->post_x_p] = 'P';
        game->new_maps[game->post_y_p + 2][game->post_x_p] = 'D';
        game->new_maps[game->post_y_p][game->post_x_p] = ' ';
        game->post_y_p = game->post_y_p + 1;
        game->compt_mov += 1;
    }
    else if (game->new_maps[game->post_y_p + 1][game->post_x_p] == 'T') {
        for (int i = 0; game->new_maps[i]; i++) {
            for (int j = 0; game->new_maps[i][j]; j++) {
                if (game->new_maps[i][j] == 'I') {
                    game->new_maps[i][j] = 'P';
                    game->new_maps[game->post_y_p][game->post_x_p] = ' ';
                    game->post_y_p = i;
                    game->post_x_p = j;
                }
            }
        }
    }
    else if (game->new_maps[game->post_y_p + 1][game->post_x_p] == 'I') {
        for (int i = 0; game->new_maps[i]; i++) {
            for (int j = 0; game->new_maps[i][j]; j++) {
                if (game->new_maps[i][j] == 'T') {
                    game->new_maps[i][j] = 'P';
                    game->new_maps[game->post_y_p][game->post_x_p] = ' ';
                    game->post_y_p = i;
                    game->post_x_p = j;
                }
            }
        }
    }
    else if (game->new_maps[game->post_y_p + 1][game->post_x_p] == 'C') {
        for (int i = 0; game->new_maps[i]; i++) {
            for (int j = 0; game->new_maps[i][j]; j++) {
                if (game->new_maps[i][j] == 'Z') {
                    game->new_maps[i][j] = ' ';
                }
            }
        }
        game->new_maps[game->post_y_p][game->post_x_p] = ' ';
        game->new_maps[game->post_y_p + 1][game->post_x_p] = 'P';
        game->post_y_p = game->post_y_p + 1;
    }
}

void mouv_left(game_t *game)
{
    if (game->new_maps[game->post_y_p][game->post_x_p - 1] == ' ' ||
    game->new_maps[game->post_y_p][game->post_x_p - 1] == 'O' ||
    game->new_maps[game->post_y_p][game->post_x_p - 1] == 'A') {
        game->new_maps[game->post_y_p][game->post_x_p - 1] = 'P';
        game->new_maps[game->post_y_p][game->post_x_p] = ' ';
        game->post_x_p = game->post_x_p - 1;
        game->compt_mov += 1;
    }
    else if (game->new_maps[game->post_y_p][game->post_x_p - 1] == 'X' &&
    game->new_maps[game->post_y_p][game->post_x_p - 2] != '#' &&
    (game->new_maps[game->post_y_p][game->post_x_p - 2] != 'X' &&
    game->new_maps[game->post_y_p][game->post_x_p - 2] != 'D')) {
        game->new_maps[game->post_y_p][game->post_x_p - 1] = 'P';
        game->new_maps[game->post_y_p][game->post_x_p - 2] = 'X';
        game->new_maps[game->post_y_p][game->post_x_p] = ' ';
        game->post_x_p = game->post_x_p - 1;
        game->compt_mov += 1;
    }
    else if (game->new_maps[game->post_y_p][game->post_x_p - 1] == 'D' &&
    game->new_maps[game->post_y_p][game->post_x_p - 2] != '#' &&
    (game->new_maps[game->post_y_p][game->post_x_p -2] != 'X' &&
    game->new_maps[game->post_y_p][game->post_x_p -2] != 'D')) {
        game->new_maps[game->post_y_p][game->post_x_p - 1] = 'P';
        game->new_maps[game->post_y_p][game->post_x_p - 2] = 'D';
        game->new_maps[game->post_y_p][game->post_x_p] = ' ';
        game->post_x_p = game->post_x_p - 1;
        game->compt_mov += 1;
    }
    else if (game->new_maps[game->post_y_p][game->post_x_p - 1] == 'T') {
        for (int i = 0; game->new_maps[i]; i++) {
            for (int j = 0; game->new_maps[i][j]; j++) {
                if (game->new_maps[i][j] == 'I') {
                    game->new_maps[i][j] = 'P';
                    game->new_maps[game->post_y_p][game->post_x_p] = ' ';
                    game->post_y_p = i;
                    game->post_x_p = j;
                }
            }
        }
    }
    else if (game->new_maps[game->post_y_p][game->post_x_p - 1] == 'I') {
        for (int i = 0; game->new_maps[i]; i++) {
            for (int j = 0; game->new_maps[i][j]; j++) {
                if (game->new_maps[i][j] == 'T') {
                    game->new_maps[i][j] = 'P';
                    game->new_maps[game->post_y_p][game->post_x_p] = ' ';
                    game->post_y_p = i;
                    game->post_x_p = j;
                }
            }
        }
    }
    else if (game->new_maps[game->post_y_p][game->post_x_p - 1] == 'C') {
        for (int i = 0; game->new_maps[i]; i++) {
            for (int j = 0; game->new_maps[i][j]; j++) {
                if (game->new_maps[i][j] == 'Z') {
                    game->new_maps[i][j] = ' ';
                }
            }
        }
        game->new_maps[game->post_y_p][game->post_x_p] = ' ';
        game->new_maps[game->post_y_p][game->post_x_p - 1] = 'P';
        game->post_x_p = game->post_x_p - 1;
    }
}

void mouv_right(game_t *game)
{
    if (game->new_maps[game->post_y_p][game->post_x_p + 1] == ' ' ||
    game->new_maps[game->post_y_p][game->post_x_p + 1] == 'O' ||
    game->new_maps[game->post_y_p][game->post_x_p + 1] == 'A') {
        game->new_maps[game->post_y_p][game->post_x_p + 1] = 'P';
        game->new_maps[game->post_y_p][game->post_x_p] = ' ';
        game->post_x_p = game->post_x_p + 1;
        game->compt_mov += 1;
    }
    else if (game->new_maps[game->post_y_p][game->post_x_p + 1] == 'X' &&
    game->new_maps[game->post_y_p][game->post_x_p + 2] != '#' &&
    (game->new_maps[game->post_y_p][game->post_x_p + 2] != 'X' &&
    game->new_maps[game->post_y_p][game->post_x_p + 2] != 'D')) {
        game->new_maps[game->post_y_p][game->post_x_p + 1] = 'P';
        game->new_maps[game->post_y_p][game->post_x_p + 2] = 'X';
        game->new_maps[game->post_y_p][game->post_x_p] = ' ';
        game->post_x_p = game->post_x_p + 1;
        game->compt_mov += 1;
    }
    else if (game->new_maps[game->post_y_p][game->post_x_p + 1] == 'D' &&
    game->new_maps[game->post_y_p][game->post_x_p + 2] != '#' &&
    (game->new_maps[game->post_y_p][game->post_x_p + 2] != 'X' &&
    game->new_maps[game->post_y_p][game->post_x_p + 2] != 'D')) {
        game->new_maps[game->post_y_p][game->post_x_p + 1] = 'P';
        game->new_maps[game->post_y_p][game->post_x_p + 2] = 'D';
        game->new_maps[game->post_y_p][game->post_x_p] = ' ';
        game->post_x_p = game->post_x_p + 1;
        game->compt_mov += 1;
    }
    else if (game->new_maps[game->post_y_p][game->post_x_p + 1] == 'T') {
        for (int i = 0; game->new_maps[i]; i++) {
            for (int j = 0; game->new_maps[i][j]; j++) {
                if (game->new_maps[i][j] == 'I') {
                    game->new_maps[i][j] = 'P';
                    game->new_maps[game->post_y_p][game->post_x_p] = ' ';
                    game->post_y_p = i;
                    game->post_x_p = j;
                }
            }
        }
    }
    else if (game->new_maps[game->post_y_p][game->post_x_p + 1] == 'I') {
        for (int i = 0; game->new_maps[i]; i++) {
            for (int j = 0; game->new_maps[i][j]; j++) {
                if (game->new_maps[i][j] == 'T') {
                    game->new_maps[i][j] = 'P';
                    game->new_maps[game->post_y_p][game->post_x_p] = ' ';
                    game->post_y_p = i;
                    game->post_x_p = j;
                }
            }
        }
    }
    else if (game->new_maps[game->post_y_p][game->post_x_p + 1] == 'C') {
        for (int i = 0; game->new_maps[i]; i++) {
            for (int j = 0; game->new_maps[i][j]; j++) {
                if (game->new_maps[i][j] == 'Z') {
                    game->new_maps[i][j] = ' ';
                }
            }
        }
        game->new_maps[game->post_y_p][game->post_x_p] = ' ';
        game->new_maps[game->post_y_p][game->post_x_p + 1] = 'P';
        game->post_x_p += 1;
    }
}

void mouv_up_b(game_t *game)
{
    if (game->new_maps[game->post_y_b - 1][game->post_x_b] == ' ' ||
    game->new_maps[game->post_y_b - 1][game->post_x_b] == 'O') {
        game->new_maps[game->post_y_b - 1][game->post_x_b] = 'B';
        game->new_maps[game->post_y_b][game->post_x_b] = ' ';
        game->post_y_b = game->post_y_b - 1;
        game->compt_mov += 1;
    }
    else if (game->new_maps[game->post_y_b - 1][game->post_x_b] == 'X' &&
    game->new_maps[game->post_y_b - 2][game->post_x_b] != '#' &&
    game->new_maps[game->post_y_b - 2][game->post_x_b] != 'X') {
        game->new_maps[game->post_y_b - 1][game->post_x_b] = 'B';
        game->new_maps[game->post_y_b - 2][game->post_x_b] = 'X';
        game->new_maps[game->post_y_b][game->post_x_b] = ' ';
        game->post_y_b = game->post_y_b - 1;
        game->compt_mov += 1;
    }
}

void mouv_down_b(game_t *game)
{
    if (game->new_maps[game->post_y_b + 1][game->post_x_b] == ' ' ||
    game->new_maps[game->post_y_b + 1][game->post_x_b] == 'O') {
        game->new_maps[game->post_y_b + 1][game->post_x_b] = 'B';
        game->new_maps[game->post_y_b][game->post_x_b] = ' ';
        game->post_y_b = game->post_y_b + 1;
        game->compt_mov += 1;
    }
    else if (game->new_maps[game->post_y_b + 1][game->post_x_b] == 'X' &&
    game->new_maps[game->post_y_b + 2][game->post_x_b] != '#' &&
    game->new_maps[game->post_y_b + 2][game->post_x_b] != 'X') {
        game->new_maps[game->post_y_b + 1][game->post_x_b] = 'B';
        game->new_maps[game->post_y_b + 2][game->post_x_b] = 'X';
        game->new_maps[game->post_y_b][game->post_x_b] = ' ';
        game->post_y_b = game->post_y_b + 1;
        game->compt_mov += 1;
    }
}

void mouv_left_b(game_t *game)
{
    if (game->new_maps[game->post_y_b][game->post_x_b - 1] == ' ' ||
    game->new_maps[game->post_y_b][game->post_x_b - 1] == 'O') {
        game->new_maps[game->post_y_b][game->post_x_b - 1] = 'B';
        game->new_maps[game->post_y_b][game->post_x_b] = ' ';
        game->post_x_b = game->post_x_b - 1;
        game->compt_mov += 1;
    }
    else if (game->new_maps[game->post_y_b][game->post_x_b - 1] == 'X' &&
    game->new_maps[game->post_y_b][game->post_x_b - 2] != '#' &&
    game->new_maps[game->post_y_b][game->post_x_b - 2] != 'X') {
        game->new_maps[game->post_y_b][game->post_x_b - 1] = 'B';
        game->new_maps[game->post_y_b][game->post_x_b - 2] = 'X';
        game->new_maps[game->post_y_b][game->post_x_b] = ' ';
        game->post_x_b = game->post_x_b - 1;
        game->compt_mov += 1;
    }
}

void mouv_right_b(game_t *game)
{
    if (game->new_maps[game->post_y_b][game->post_x_b + 1] == ' ' ||
    game->new_maps[game->post_y_b][game->post_x_b + 1] == 'O') {
        game->new_maps[game->post_y_b][game->post_x_b + 1] = 'B';
        game->new_maps[game->post_y_b][game->post_x_b] = ' ';
        game->post_x_b = game->post_x_b + 1;
        game->compt_mov += 1;
    }
    else if (game->new_maps[game->post_y_b][game->post_x_b + 1] == 'X' &&
    game->new_maps[game->post_y_b][game->post_x_b + 2] != '#' &&
    game->new_maps[game->post_y_b][game->post_x_b + 2] != 'X') {
        game->new_maps[game->post_y_b][game->post_x_b + 1] = 'B';
        game->new_maps[game->post_y_b][game->post_x_b + 2] = 'X';
        game->new_maps[game->post_y_b][game->post_x_b] = ' ';
        game->post_x_b = game->post_x_b + 1;
        game->compt_mov += 1;
    }
}