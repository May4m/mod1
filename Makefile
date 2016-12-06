# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smamba <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/27 08:51:47 by smamba            #+#    #+#              #
#    Updated: 2016/10/27 08:51:48 by smamba           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = g++

NAME = mod1

PLATFORM := $(shell uname)

ifeq "$(PLATFORM)" "Darwin"	#Mac
	GL = -framework GLUT -framework OpenGL -framework Cocoa
endif
ifeq "$(PLATFORM)" "Linux"	#Linux
	GL = -lGL -lGLU -lglut
endif

CFLAGS = -Wall -Werror -Wextra -w -pedantic

HEAD = 	main.hpp \
		MapOps.hpp \
		Parser.hpp \
		Map.hpp \
		Event.hpp \
		UniformWaterScene.hpp \
		WaterBufferScene.hpp \
		WaterEvapScene.hpp \
		DoubleBufferScene.hpp \
		RainingScene.hpp

SRC = 	main.cpp \
		keyhandler.cpp \
		MapOps.cpp \
		Display.cpp \
		Parser.cpp \
		Map.cpp \
		Event.cpp \
		UniformWaterScene.cpp \
		WaterBufferScene.cpp \
		WaterEvapScene.cpp \
		DoubleBufferScene.cpp \
		RainingScene.cpp

OBJ = $(SRC:.cpp=.cpp.o)

%.cpp.o: %.cpp $(HEAD)
	@$(CXX) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CFLAGS) $(OBJ) -o $(NAME) $(GL)
	@echo "with great power comes great responsibility"

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
