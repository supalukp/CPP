# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/19 16:27:13 by spunyapr          #+#    #+#              #
#    Updated: 2025/09/08 16:11:29 by spunyapr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -I$(INC_DIR)

# Directories
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build
PROGRAM = sed

SRCS := $(shell find $(SRC_DIR) -name "*.cpp")
HEADERS := $(shell find $(INC_DIR) -name "*.hpp")

OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

all: $(PROGRAM) 

$(PROGRAM): $(OBJS) $(HEADERS) Makefile
	$(CPP) $(CPPFLAGS) -o $@ $(OBJS)


$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS)| $(BUILD_DIR)
	$(CPP) $(CPPFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f $(PROGRAM)

re: fclean all

.PHONY: all clean fclean re
 