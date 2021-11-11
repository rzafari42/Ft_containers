# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rzafari <rzafari@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/10 18:44:45 by rzafari           #+#    #+#              #
#    Updated: 2021/11/11 19:24:08 by rzafari          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_FT = ft_containers
NAME_STD = std_containers
SRC = main.cpp

OBJ = $(SRC:.cpp=.o)
CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
LEAK = -fsanitize=address -g3

all : $(NAME_FT)

$(NAME_FT) : $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME_FT) -DNAMESPACE=ft
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME_STD) -DNAMESPACE=std

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm $(NAME_FT) $(NAME_STD)

re: fclean all

.PHONY: clean