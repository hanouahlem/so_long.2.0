/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bord_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbey <ahbey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:11:42 by ahbey             #+#    #+#             */
/*   Updated: 2024/06/03 20:03:01 by ahbey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_first_and_last_line(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[0][i] != '\0' && game->map[0][i] != '\n')
	{
		if (game->map[0][i] != '1')
		{
			ft_printf("Error\nInvalid first line\n");
			return (0);
		}
		i++;
	}
	while (game->map[game->nb_line - 1][j] != '\0' && game->map[game->nb_line
		- 1][j] != '\n')
	{
		if (game->map[game->nb_line - 1][j] != '1')
		{
			ft_printf("Error\nInvalid last line\n");
			return (0);
		}
		j++;
	}
	return (1);
}

int	check_border_map(t_game *game)
{
	int	i;

	i = 0;
	game->len_line = ft_so_strlen(game->map[i]);
	while (game->map[i] != NULL)
	{
		if (game->map[i][0] != '1' || game->map[i][game->len_line - 1] != '1')
		{
			ft_printf("Error\nInvalid border map\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_map_all(t_game *game, char *str)
{
	if (check_name_map(str) == 0)
		return (0);
	if (check_map_rectangle(game) == 0)
		return (0);
	if (check_first_and_last_line(game) == 0)
		return (0);
	if (check_border_map(game) == 0)
		return (0);
	if (check_interior(game) == 0)
		return (0);
	posplayer(game);
	if (map_dup(game) == 0)
		return (0);
	else
		return (1);
}
