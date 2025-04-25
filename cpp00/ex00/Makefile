# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/18 16:23:56 by mariaoli          #+#    #+#              #
#    Updated: 2025/04/25 18:41:19 by mariaoli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

SCRS = megaphone.cpp
OBJS = $(SCRS:.cpp=.o)

CCPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -f

$(NAME): $(OBJS)
	$(CCPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

%.o: %.cpp
	$(CCPP) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re