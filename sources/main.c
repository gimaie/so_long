/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gen <gen@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 16:17:22 by gen               #+#    #+#             */
/*   Updated: 2025/10/17 11:53:32 by gen              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int main(int argc, char **argv)
{
    t_game  game;

    if (start_validation(argc, argv, &game) == 1)
    {
        // 検証成功！
        printf("Success! Map is valid.\n");

        // --- ここからグラフィック処理が始まる ---
        if (init_mlx(&game) == 1)
        {
            if (load_textures(&game) == 0)
			{
				printf("Error: Failed to load textures.\n");
				// エラー時はcleanup_gameを呼んで終了
				cleanup_game(&game);
				return (1);
			}

            mlx_key_hook(game.win, handle_keypress, &game);
            mlx_hook(game.win, 17, 0, handle_close_window, &game);
            render_map(&game);
            mlx_loop(game.mlx);
         }

    }
    else
    {
        // 検証失敗...
        printf("Error\n");
    }

    // プログラム終了前に、確保したメモリを全てお片付け
    cleanup_game(&game);
    return (0);
}

//int	main(void)
//{
//	void	*mlx_ptr;
//	void	*win_ptr;


//	mlx_ptr = mlx_init();
//	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
//	mlx_loop(mlx_ptr);
//}
