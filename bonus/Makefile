##
## EPITECH PROJECT, 2021
##
## File description:
##

SRC			=	src/main.c\
				src/menu.c\
				src/error_map.c\
				src/error_handling.c\
				src/finish_game.c\
				src/free_game.c\
				src/initialization_game.c\
				src/initialization_struct.c\
				src/mouv_play.c\
				src/reset_game.c\
				src/start_game.c\
				src/utils.c\
				src/inverted_mode_game.c\

OBJ			=	$(SRC:.c=.o)

NAME		=	my_sokoban

CFLAGS		=	-Wall -Wextra

CPPFLAGS	=	-iquote ./include

LDFLAGS		=	-L ./lib -lmy -lncurses -lcsfml-audio

CC			=	gcc

all: $(NAME)
$(NAME): $(OBJ)
	$(MAKE) -C ./lib/my
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

debug: CFLAGS += -g3
debug: re

clean:
	$(RM) $(OBJ)
	$(MAKE) -C ./lib/my clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C ./lib/my fclean

re: fclean all

./PHONY: all clean fclean