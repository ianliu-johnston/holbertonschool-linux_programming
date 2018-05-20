# Basic Makefile for hls
# debug usage: make DEBUG=1

CC=gcc
SRC=files.c init.c main.c parse_args.c
INC=hls.h
OBJ=$(SRC:.c=.o)
NAME=ls.0.1
CFLAGS=-Wall -Werror -Wextra -pedantic

DEBUG=0
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
