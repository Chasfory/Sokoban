/*
** EPITECH PROJECT, 2021
** sokoban.h
** File description:
** sokoban
*/

#ifndef STRUCT_PLAY_H
#define STRUCT_PLAY_H

typedef struct game_s {
    char **new_maps;
    char **init_map;
    char **post_table_o;
    int post_x;
    int post_x_init;
    int post_y;
    int post_y_init;
    int compt_o;
    int compt_x;
    int win;
    int lose;
} game_t;

#endif /* !STRUCT_PLAY_H_ */