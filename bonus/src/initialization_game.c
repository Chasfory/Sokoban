/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** sokoban.c
*/

#include "sokoban.h"

static void post_p_and_post_map(game_t *game, int len, int col)
{
    if (game->new_maps[len][col] == 'X' || game->new_maps[len][col] == 'P' ||
    game->new_maps[len][col] == 'D' || game->new_maps[len][col] == 'B') {
        game->post_table_o[len][col] = ' ';
    } else {
        game->post_table_o[len][col] = game->new_maps[len][col];
    }
    if (game->new_maps[len][col] == 'P') {
            game->post_y_p = len;
            game->post_y_init_p = len;
            game->post_x_p = col;
            game->post_x_init_p = col;
    }
    if (game->new_maps[len][col] == 'B') {
        game->post_y_b = len;
        game->post_y_init_b = len;
        game->post_x_b = col;
        game->post_x_init_b = col;
    }
}

static int position_table_o(game_t *game)
{
    int compt_len = my_strlen_compt(game->new_maps);
    int col = 0;
    game->post_table_o = malloc(sizeof(char *) * (compt_len + 1));

    if (game->post_table_o == NULL)
        return -1;
    for (int len = 0; len < compt_len; len++) {
        game->post_table_o[len] = malloc(sizeof(char) *
        (my_strlen(game->new_maps[len]) + 1));
        if (game->post_table_o[len] == NULL)
            return -1;
        for (col = 0; game->new_maps[len][col] != '\0'; col++) {
            post_p_and_post_map(game, len, col);
        }
        game->post_table_o[len][col] = '\0';
    }
    game->post_table_o[compt_len] = NULL;
    return 0;
}

static int recovery_of_map(char *map, game_t *game)
{
    game->new_maps = str_to_word_array(map, '\n');
    game->init_map = str_to_word_array(map, '\n');
    if (position_table_o(game) == -1) {
        return -1;
    }
    return 0;
}

int game_initialization(game_t *game, mode_game_t *opt_mode)
{
    char *map = open_maps(opt_mode);

    if (map == NULL) {
        return -1;
    }
    if (funct_error_map(map, game) == -1) {
        return -1;
    }
    if (recovery_of_map(map, game) == -1) {
        return -1;
    }
    free(map);
    return 0;
}

char *open_maps(mode_game_t *opt_mode)
{
    int fd = open(opt_mode->maps_mode, O_RDONLY);
    char *map = NULL;
    ssize_t stl;
    struct stat stats;

    if (fd == -1 || (stat(opt_mode->maps_mode, &stats) == -1)) {
        return NULL;
    }
    map = malloc(sizeof(char) * (stats.st_size + 1));
    if (map == NULL || stats.st_size == 0) {
        return NULL;
    }
    stl = read(fd, map, stats.st_size);
    if (stl == -1) {
        return NULL;
    }
    map[stats.st_size] = '\0';
    close(fd);
    return map;
}