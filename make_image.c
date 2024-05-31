/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbey <ahbey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 14:54:03 by ahbey             #+#    #+#             */
/*   Updated: 2024/05/31 18:35:04 by ahbey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_moha_image(t_game *game)
{
	int	r;

	game->mohaimage[0] = mlx_xpm_file_to_image(game->mlx, "xpm/moha_back.xpm",
			&r, &r);
	game->mohaimage[1] = mlx_xpm_file_to_image(game->mlx, "xpm/moha_front.xpm",
			&r, &r);
	game->mohaimage[2] = mlx_xpm_file_to_image(game->mlx, "xpm/moha_right.xpm",
			&r, &r);
	game->mohaimage[3] = mlx_xpm_file_to_image(game->mlx, "xpm/moha_left.xpm",
			&r, &r);
	game->texture[1] = mlx_xpm_file_to_image(game->mlx, "xpm/mur_boit.xpm", &r,
			&r);
	game->texture[3] = mlx_xpm_file_to_image(game->mlx, "xpm/sol_gris.xpm", &r,
			&r);
	game->texture[2] = mlx_xpm_file_to_image(game->mlx, "xpm/naruto_exit.xpm",
			&r, &r);
	game->texture[4] = mlx_xpm_file_to_image(game->mlx,
			"xpm/sushis/monster1.xpm", &r, &r);
}

void	load_texture(t_game *game)
{
	int	r;

	game->texture[10] = mlx_xpm_file_to_image(game->mlx,
			"xpm/sushis/sushi1.xpm", &r, &r);
	game->texture[11] = mlx_xpm_file_to_image(game->mlx,
			"xpm/sushis/sushi2.xpm", &r, &r);
	game->texture[12] = mlx_xpm_file_to_image(game->mlx,
			"xpm/sushis/sushi3.xpm", &r, &r);
	game->texture[13] = mlx_xpm_file_to_image(game->mlx,
			"xpm/sushis/sushi4.xpm", &r, &r);
	game->texture[14] = mlx_xpm_file_to_image(game->mlx,
			"xpm/sushis/sushi5.xpm", &r, &r);
	game->texture[15] = mlx_xpm_file_to_image(game->mlx, "xpm/sushis/sushi.xpm",
			&r, &r);
}

void	make_image(t_game *game)
{
	load_moha_image(game);
	load_texture(game);
	if (!game->mohaimage[0] || !game->mohaimage[1] || !game->mohaimage[2]
		|| !game->mohaimage[3] || !game->texture[1] || !game->texture[3]
		|| !game->texture[2] || !game->texture[10] || !game->texture[11]
		|| !game->texture[12] || !game->texture[13] || !game->texture[14]
		|| !game->texture[15] || !game->texture[4])
		destroyimages(game, 1);
}
