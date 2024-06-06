/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbey <ahbey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:56:55 by ahbey             #+#    #+#             */
/*   Updated: 2024/06/03 15:35:29 by ahbey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	displaynumber(t_game *game)
{
	char	*numero;

	numero = ft_itoa(game->nb_steps);
	mlx_string_put(game->mlx, game->win, (game->len_line / 2) * 60 + 30,
		(game->map_height - 1) * 60 + 30, 0, numero);
	free(numero);
}

void	give_rols(t_game *game, int i, int j)
{
	if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->texture[1], j * 60,
			i * 60);
	if (game->map[i][j] == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->texture[3], j * 60,
			i * 60);
	if (game->map[i][j] == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->mohaimage[game->direction], j * 60, i * 60);
	if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->texture[(game->image
				% 6) + 10], j * 60, i * 60);
	if (game->map[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->texture[2], j * 60,
			i * 60);
	if (game->map[i][j] == 'M')
		mlx_put_image_to_window(game->mlx, game->win, game->texture[4], j * 60,
			i * 60);
}

void	loadmap(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			give_rols(game, i, j);
			j++;
		}
		i++;
	}
	displaynumber(game);
}

int	start_game(t_game *game)
{
	(void)game;
	loadmap(game);
	return (0);
}
