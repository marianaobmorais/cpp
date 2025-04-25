# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/24 16:24:01 by mariaoli          #+#    #+#              #
#    Updated: 2025/04/24 16:58:09 by mariaoli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = program

SRCS = tests.cpp \
		Account.cpp

OBJS = $(SRCS:.cpp=.o)

CCPP = c++;
CPPFLAGS = -Wall -Werror -Wextra -std=c++98

RM = rm -f

$(NAME): $(OBJS)
	$(CCPP) $(CCPPFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

%.o: %.cpp
	$(CCPP) $(CCPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(OBJS)

re: fclean all

.PHONY: all clean fclean re