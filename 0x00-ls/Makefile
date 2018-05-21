# Basic Makefile for hls

CC=gcc
SRC=files.c main.c parse_args.c utils.c
INC=hls.h error_codes.h
OBJ=$(SRC:.c=.o)
NAME=hls
CFLAGS=-Wall -Werror -Wextra -pedantic

DEBUG=0
# To turn on automatic debug mode uncomment line below
# DEBUG=1
ifeq ($(DEBUG),1)
	SRC += debugging_fxns.c
	CFLAGS += -g
else
	CFLAGS += -DNO_DEBUG
endif

.PHONY: clean oclean fclean re all betty $(NAME)
all: $(SRC) $(NAME)

betty:
	/home/concati/tools/Betty/betty.sh $(SRC) $(INC)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $@

fclean: oclean clean

oclean:
	$(RM) debugging_fxns.o $(OBJ)

clean:
	$(RM) .*.swp  $(NAME)


re: oclean betty all
