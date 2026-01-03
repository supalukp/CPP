# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/19 16:27:13 by spunyapr          #+#    #+#              #
#    Updated: 2026/01/02 21:39:21 by spunyapr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Compiler
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -I$(INC_DIR)

# Directories
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build
NAME = btc
SRCS = 	$(SRC_DIR)/main.cpp \
		$(SRC_DIR)/BitcoinExchange.cpp
HEADERS = $(INC_DIR)/BitcoinExchange.hpp
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS) Makefile
	$(CPP) $(CPPFLAGS) -o $@ $(OBJS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS)| $(BUILD_DIR)
	$(CPP) $(CPPFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

