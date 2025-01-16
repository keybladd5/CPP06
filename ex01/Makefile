# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: polmarti <polmarti@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/23 17:50:05 by polmarti          #+#    #+#              #
#    Updated: 2024/12/23 17:50:07 by polmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bin01

#########
RM = rm -rf
CC = c++
CFLAGS = -g -Wall -Wextra -Werror -std=c++98 -fsanitize=address -pedantic 

#########

#COLORS
GREEN		=	\033[38;5;154m
RED			=	\033[38;5;197m
PURPLE		=	\033[38;5;171m
BLUE		=	\033[38;5;14m
NC			=	\033[0m
YELLOW		=	\033[38;5;190m

#########
FILES = Bureaucrat main

SRC = $(addsuffix .cpp, $(FILES))

vpath %.cpp
#########

#########
OBJ_DIR = build
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))
DEP = $(addsuffix .d, $(basename $(OBJ)))
#########

#########
$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	@${CC} -MMD $(CFLAGS) -c -I. $< -o $@

all: $(NAME)

$(NAME): $(OBJ) Makefile
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "${GREEN}CPP06 ex01 binary Compiled${NC}"

clean:
	@$(RM) $(OBJ) $(DEP)
	@$(RM) -r $(OBJ_DIR)
	@echo "${RED}CPP06 ex01 objects removeds${NC}"

fclean: clean
	@$(RM) $(NAME)
	@echo "${RED}CPP06 ex01 binary removed${NC}"

re:	fclean all

.PHONY: all clean fclean re release

-include $(DEP)
