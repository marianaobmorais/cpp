# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/20 14:14:23 by mariaoli          #+#    #+#              #
#    Updated: 2025/06/21 13:03:55 by mariaoli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = animal

SCRS = main.cpp \
		Animal.cpp \
		Dog.cpp \
		Cat.cpp \
		WrongAnimal.cpp \
		WrongCat.cpp

OBJS = $(SCRS:.cpp=.o)

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 #-Wvirtual

RM = rm -f

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re