/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbey <ahbey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:17:43 by ahbey             #+#    #+#             */
/*   Updated: 2024/06/06 11:57:19 by ahbey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	posplayer(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->playerx = j;
				game->playery = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	destroyimages(t_game *game, int error)
{
	int	i;

	i = -1;
	while (++i < 4)
		if (game->mohaimage[i])
			mlx_destroy_image(game->mlx, game->mohaimage[i]);
	i = -1;
	while (++i < 6)
		if (game->texture[i + 10])
			mlx_destroy_image(game->mlx, game->texture[i + 10]);
	i = 0;
	while (++i < 4)
		if (game->texture[i])
			mlx_destroy_image(game->mlx, game->texture[i]);
	if (error)
		ft_printf("Error\nInvalid image!\n");
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_map(game->map);
	exit(0);
}

int	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (free_map(game->map),
			ft_printf("Error\nInitialization mlx failed\n"));
	game->win = mlx_new_window(game->mlx, ft_so_strlen(game->map[0]) * 60,
			strlen_tab(game->map) * 60, "MOHA NARUTO AND CHILL");
	if (!game->win)
		return (free(game->mlx), free_map(game->map),
			ft_printf("Error\nWindow opening failed\n"));
	return (0);
}

int	main(int ac, char **av)
{
	static t_game	game = {0};

	game.direction = 3;
	if (ac == 2)
	{
		game.map = stock_map(&game, av[1]);
		if (!game.map)
			return (1);
		if (check_map_all(&game, av[1]) == 0)
			return (free_map(game.map), 0);
		if (init_game(&game))
			return (1);
		make_image(&game);
		start_game(&game);
		mlx_hook(game.win, KeyPress, KeyPressMask, &touch_key, &game);
		mlx_hook(game.win, 17, 0, close_window, game.mlx);
		mlx_loop(game.mlx);
		destroyimages(&game, 0);
	}
	else
		return (ft_printf("Error\nWrong number of arguments\n"));
	return (0);
}
