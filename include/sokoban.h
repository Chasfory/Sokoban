/*
** EPITECH PROJECT, 2021
** sokoban.h
** File description:
** sokoban
*/

#ifndef SOKOBAN_H
#define SOKOBAN_H

#include <ncurses.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stddef.h>

#include "my.h"
#include "struct_play.h"

// error_handling.c
int error_map(char const *map);

// error_map.c
int funct_error_map(char const *map, game_t *game);

// initialization_game.c
int game_initialization(game_t *game, char const *av);
char *open_maps(char const *av);

// start_game.c
int start_game(char *av);

// utils.c
int my_strlen_compt(char **new_maps);
int recup_longest_line(game_t *game);

// mouv_play.c
void mouv_up(game_t *game);
void mouv_down(game_t *game);
void mouv_left(game_t *game);
void mouv_right(game_t *game);

// initialization_struct.c
game_t init_struct(void);

// finish_game.c
int check_lose(game_t *game);
int check_win(game_t *game);

// free_map.c
void free_game(game_t game);

// reset_game.c
void reset_game(game_t *game);

#endif /* !SOKOBAN_H_ */