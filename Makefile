NAME = so_long

CC = gcc
CCFLAGS = -Wextra -Wall -Werror

# Detección del sistema operativo
UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
	MLX_DIR = minilibx
	LIBS = -L$(MLX_DIR) -lmlx -lX11 -lGL -lGLU -lXext
	MLX_FLAGS = -I$(MLX_DIR)
else ifeq ($(UNAME), Darwin)
	MLX_DIR = mlx-macos
	LIBS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
	MLX_FLAGS = -I$(MLX_DIR)
endif

# Directorios
SRC_DIR = src
INCLUDE_DIR = includes
BONUS_SRC_DIR = src_bonus
BONUS_INCLUDE_DIR = includes_bonus
GNL_DIR = gnl
PRINTF_DIR = ft_printf

# Archivos fuente y objetos para el proyecto normal
SRC = $(addprefix $(SRC_DIR)/, main.c init_game.c game_utils.c map_parser.c map_parser_utils.c free.c validate_map.c \
		path_checker.c utils.c sprites_utils.c draw.c draw_utils.c keys.c)
GNL_SRC = $(addprefix gnl/, get_next_line.c get_next_line_utils.c)
PRINTF_SRC = $(addprefix ft_printf/, ft_printf.c aux_functions.c manage_specifiers.c parse_format.c put_functions.c utils.c)

OBJ = $(SRC:.c=.o)
GNL_OBJ = $(GNL_SRC:.c=.o)
PRINTF_OBJ = $(PRINTF_SRC:.c=.o)

# Archivos fuente y objetos para el proyecto bonus
BONUS_SRC = $(addprefix $(BONUS_SRC_DIR)/, main_bonus.c init_game_bonus.c game_utils_bonus.c map_parser_bonus.c map_parser_utils_bonus.c free_bonus.c validate_map_bonus.c \
		path_checker_bonus.c utils_bonus.c sprites_load_bonus.c sprites_load_animated_bonus.c draw_bonus.c draw_animated_bonus.c draw_utils_bonus.c update_frames_bonus.c keys_bonus.c)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

# Reglas principales
all: $(NAME)

$(NAME): $(OBJ) $(GNL_OBJ) $(PRINTF_OBJ)
	$(CC) $(CCFLAGS) $(MLX_FLAGS) $^ $(LIBS) -o $(NAME)

# Compilación de los objetos del proyecto normal
$(OBJ): $(SRC_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CCFLAGS) $(MLX_FLAGS) -I$(INCLUDE_DIR) -I$(GNL_DIR) -I$(PRINTF_DIR) -c $< -o $@

# Compilación del proyecto bonus
bonus: $(BONUS_OBJ) $(GNL_OBJ) $(PRINTF_OBJ)
	$(CC) $(CCFLAGS) $(MLX_FLAGS) $^ $(LIBS) -o $(NAME)

# Compilación de los objetos del proyecto bonus
$(BONUS_OBJ): $(BONUS_SRC_DIR)/%.o : $(BONUS_SRC_DIR)/%.c
	$(CC) $(CCFLAGS) $(MLX_FLAGS) -I$(BONUS_INCLUDE_DIR) -I$(GNL_DIR) -I$(PRINTF_DIR) -c $< -o $@

debug: $(OBJ) $(GNL_OBJ) $(PRINTF_OBJ)
	$(CC) $(CCFLAGS) -fsanitize=address $(MLX_FLAGS) $^ $(LIBS) -o $(NAME)

clean:
	rm -f $(OBJ) $(BONUS_OBJ) $(GNL_OBJ) $(PRINTF_OBJ)

fclean: clean
	make clean -C $(MLX_DIR)
	rm -f $(NAME)

mlx:
	@$(MAKE) re -C $(MLX_DIR)

re: fclean all
