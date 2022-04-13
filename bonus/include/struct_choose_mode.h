/*
** EPITECH PROJECT, 2021
** sokoban.h
** File description:
** sokoban
*/

#ifndef STRUCT_CHOOSE_MODE_H
#define STRUCT_CHOOSE_MODE_H

//revoir les loses
//Faire limit limit

static const char *choose_mode[] = {
    "Multiplayer",
    "Inverted",
    "The least movement",
    "Tetris box",
    "Back to the future"
};

static const char *map_multiplayer[] = {
    "map_multiplayer_1",
    "map_multiplayer_2",
    "return"
};

static const char *map_inverted[] = {
    "map_inverted_1",
    "map_inverted_2",
    "return"
};

static const char *map_least_mov[] = {
    "map_move_1",
    "map_move_2",
    "return"
};

static const char *map_tetris[] = {
    "map_tetris_1",
    "map_tetris_2",
    "return"
};

static const char *map_futur[] = {
    "map_futur_1",
    "map_futur_2",
    "return"
};

#endif /* !STRUCT_CHOOSE_MODE_H_ */