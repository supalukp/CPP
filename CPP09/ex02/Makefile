# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/19 16:27:13 by spunyapr          #+#    #+#              #
#    Updated: 2026/01/06 16:15:27 by spunyapr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Compiler
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -I$(INC_DIR)

# Directories
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build
NAME = PmergeMe
SRCS = 	$(SRC_DIR)/main.cpp \
		$(SRC_DIR)/PmergeMe.cpp 
HEADERS = $(INC_DIR)/PmergeMe.hpp
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

