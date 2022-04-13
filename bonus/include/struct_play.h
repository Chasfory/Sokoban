/*
** EPITECH PROJECT, 2021
** sokoban.h
** File description:
** sokoban
*/

#ifndef STRUCT_PLAY_H
#define STRUCT_PLAY_H

#include <SFML/Audio/Music.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>

typedef struct game_s {
    char **new_maps;
    char **init_map;
    char **post_table_o;
    int post_x_p;
    int post_x_init_p;
    int post_y_p;
    int post_y_init_p;
    int post_x_b;
    int post_x_init_b;
    int post_y_b;
    int post_y_init_b;
    int compt_o;
    int compt_x;
    int compt_d;
    int compt_a;
    int compt_mov;
    int win;
    int lose;
    sfMusic *son;
} game_t;

typedef struct mode_game_s {
    char *maps_mode;
    int mode_game;
    int result_game;
} mode_game_t;

#endif /* !STRUCT_PLAY_H_ */