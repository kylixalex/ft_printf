NAME = libftprintf.a

SRC = src
DIST = dist

SOURCES = $(wildcard $(SRC)/*.c)
OBJECTS = $(patsubst $(SRC)/%.c, $(DIST)/%.o, $(SOURCES))

CC = gcc
CFLAGS = -Wall -Werror -Wextra -c -o

all: $(NAME)

$(DIST)/%.o: $(SRC)/%.c
	@mkdir -p $(DIST)
	@$(CC) $< $(CFLAGS) $@

$(NAME): $(OBJECTS)
	@ar rcs $@ $^

clean:
	@rm -rf dist

fclean: clean
	@rm -f $(NAME)

re:
	@make fclean
	@make
