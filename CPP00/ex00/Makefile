# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/14 16:23:58 by spunyapr          #+#    #+#              #
#    Updated: 2025/08/18 12:43:08 by spunyapr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

# Directories
SRC_DIR = src
BUILD_DIR = build
PROGRAM = megaphone

SRCS := $(shell find $(SRC_DIR) -name "*.cpp")

OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

all: $(PROGRAM) 

$(PROGRAM): $(OBJS) Makefile
	$(CPP) $(CPPFLAGS) -o $@ $(OBJS)


$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CPP) $(CPPFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f $(PROGRAM)

re: fclean all

.PHONY: all clean fclean re
