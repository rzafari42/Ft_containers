# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rzafari <rzafari@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/10 18:44:45 by rzafari           #+#    #+#              #
#    Updated: 2021/11/10 19:49:00 by rzafari          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_containers
SRC = main.cpp

OBJ = $(SRC:.cpp=.o)
CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm $(NAME)

re: fclean all

.PHONY: clean


