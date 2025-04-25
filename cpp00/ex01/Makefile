# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/18 19:58:07 by mariaoli          #+#    #+#              #
#    Updated: 2025/04/24 16:51:44 by mariaoli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

SRCS = main.cpp \
		PhoneBook.cpp \
		Contact.cpp \
		utils.cpp

OBJS = $(SRCS:.cpp=.o)

CCPP = c++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98

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