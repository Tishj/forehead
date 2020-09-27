# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tbruinem <tbruinem@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/09/21 20:31:07 by tbruinem      #+#    #+#                  #
#    Updated: 2020/09/26 23:35:27 by tbruinem      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME =		forehead
SRCDIR =	src
OBJDIR =	obj
INCLDIR =	incl
CXX =		g++
SRC :=		main \
			Function
OS = $(shell uname)

OBJ :=		$(SRC:%=$(OBJDIR)/%.o)
SRC	:=		$(SRC:%=$(SRCDIR)/%.cpp)
FLAGS =		-Wall -Wextra -Werror -std=c++11

ifeq ($(DEBUG),1)
	FLAGS += -g -fsanitize=address
endif
ifeq ($(RELEASE), 1)
	ifeq ($(OS), Linux)
		FLAGS += -finline-functions -Ofast -m64 -funroll-loops -ftree-vectorize
	else
		FLAGS += -finline-functions -Ofast -m64 -funroll-loops -fvectorize
	endif
endif

all: $(NAME)

obj/%.o: src/%.cpp
	@echo $(SRC)
	@echo $(OBJ)
	@mkdir -p $(@D)
	$(CXX) -c $(FLAGS) -I $(INCLDIR) $< -o $@

$(NAME): $(OBJ)
	$(CXX) $(FLAGS) -I $(INCLDIR) $(OBJ) -o $@

release: $(OBJ)
	make re RELEASE=1

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
