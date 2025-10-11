/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gen <gen@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 16:17:22 by gen               #+#    #+#             */
/*   Updated: 2025/10/11 17:04:40 by gen              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "./minilibx-linux/mlx.h"
#include "./minilibx-linux/mlx_int.h"

int main(int argc, char **argv)
{
    t_game  game;

    if (start_validation(argc, argv, &game) == 1)
    {
        // 検証成功！
        ft_printf("Success! Map is valid.\n");

        // --- ここからグラフィック処理が始まる ---
        // init_mlx(&game);
        // render_game(&game);
        // mlx_loop(game.mlx);
        // ------------------------------------
    }
    else
    {
        // 検証失敗...
        ft_printf("Error\n");
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
