NAME = so_long


CC = cc
CFLAGS = -Wall -Wextra -Werror


SRC = sources/main.c \
      sources/error.c \
      sources/utils.c \
      sources/validate_map.c \
      sources/validate_map2.c \
      sources/validate_map3.c


OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a
GNL = get_next_line/get_next_line.a

MLX_FLAGS = -Lminilibx-linux -lXext -lX11 -lm


# --- ルール定義 ---

# デフォルトルール (makeとだけ打った時に実行される)
all: $(NAME)

# 実行ファイルを作成するルール
# $(OBJ)と各ライブラリをリンクし、MiniLibXのフラグも追加する
$(NAME): $(OBJ) $(LIBFT) $(GNL)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(GNL) $(MLX_FLAGS)

# libft.a を作成するルール
$(LIBFT):
	make -C libft

# get_next_line.a を作成するルール
$(GNL):
	make -C get_next_line

# オブジェクトファイルを削除するルール
clean:
	rm -f $(OBJ)
	make -C libft clean
	make -C get_next_line clean

# オブジェクトファイルと実行ファイルを削除するルール
fclean: clean
	rm -f $(NAME)
	make -C libft fclean
	make -C get_next_line fclean

# 全てクリーンにしてから再コンパイルするルール
re: fclean all

# 偽のターゲットを指定
.PHONY: all clean fclean re
