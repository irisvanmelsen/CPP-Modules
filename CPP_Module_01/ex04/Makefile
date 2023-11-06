
NAME 		= 	sed

#UTILS
FLAGS 		=	-Wall -Werror -Wextra -std=c++11
CC 			= 	c++
RM 			=	rm -rf
AR			=	ar -rc
SRC			=	main.cpp \
				
ifdef DEBUG
	FLAGS += -g
endif

# Headers
HEADER_DIR = include
HEADERS = sed.hpp

#OBJB_FILES	=	${SRCB:.c=.o}
OBJ_DIR		:=	./obj
SRC_DIR 	:= 	./src

# Reset
Color_Off	=	"\033[0m"			# Text Reset

# Regular Colors
Black		=	"\033[0;30m"		# Black
Red			=	"\033[0;31m"		# Red
Green		=	"\033[0;32m"		# Green
Yellow		=	"\033[0;33m"		# Yellow
Blue		=	"\033[0;34m"		# Blue
Purple		=	"\033[0;35m"		# Purple
Cyan		=	"\033[0;36m"		# Cyan
White		=	"\033[0;37m"		# White

# Avoid relinking in bonus
ifdef WITH_BONUS
	OBJ_RAW = $(OBJ_FILES) $(OBJB_FILES)
else
	OBJ_RAW = $(OBJ_FILES)
endif

# Add obj / src directory to obj / src path
OBJ		:= 	$(addprefix $(OBJ_DIR)/,$(SRC:.cpp=.o))
SRC		:=	$(addprefix $(SRC_DIR)/,$(SRC))
HEADERS :=	$(addprefix $(HEADER_DIR)/, $(HEADERS))

all:	${NAME}

${NAME}: ${OBJ}
	@echo ${Blue} Building ${NAME} ${Color_Off}
	@${CC} ${OBJ} ${FLAGS} -o ${NAME}
	@echo ${Green} Complete 😊 ${Color_Off}

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS) | $(OBJ_DIR)
# @mkdir -p ${OBJ_DIR}
	@echo ${Blue} Compiling: $< ${Color_Off}
	@${CC} ${FLAGS} -c $< -o $@ -I $(HEADER_DIR)

$(OBJ_DIR):
	@mkdir $@

# Set 'WITH_BONUS' option to make with bonus
#bonus:
#	@$(MAKE) WITH_BONUS=true all

clean:
	@echo ${Yellow} Deleting ${OBJ_DIR} ${Color_Off}
	@${RM} ${OBJ_DIR}
fclean: clean
	@echo ${Yellow} Deleting ${NAME} ${Color_off}
	@${RM} ${NAME}
	
re:	fclean all

.PHONY: all bonus clean fclean re