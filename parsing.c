/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbey <ahbey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 20:33:03 by ahbey             #+#    #+#             */
/*   Updated: 2024/05/26 12:16:49 by ahbey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_rectangle(t_game *game)
{
	int	i;
	int	j;
	int	nb_char;

	i = 0;
	j = 0;
	nb_char = ft_so_strlen(game->map[i]);
	while (game->map[i])
	{
		if (ft_so_strlen(game->map[i]) != nb_char)
		{
			ft_printf("Error\nMap is not rectangle\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_line_content(char *line, int *count_exit, int *count_playeur,
		int *count_collect)
{
	int		i;
	char	c;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		c = line[i];
		if (c != '0' && c != '1' && c != 'C' && c != 'P' && c != 'E')
		{
			ft_printf("Error\nInvalid character in the map\n");
			return (0);
		}
		if (c == 'E')
			(*count_exit)++;
		if (c == 'P')
			(*count_playeur)++;
		if (c == 'C')
			(*count_collect)++;
		i++;
	}
	return (1);
}

int	validate_counts(int count_exit, int count_playeur, int count_collect)
{
	if (count_exit != 1)
	{
		ft_printf("Error\nThere must be exactly one 'E' int the map\n");
		return (0);
	}
	if (count_playeur != 1)
	{
		ft_printf("Error\nThere must be exactly one 'P' in the map\n");
		return (0);
	}
	if (count_collect < 1)
	{
		ft_printf("Error\nThere must be one or more 'C' in the map\n");
		return (0);
	}
	return (1);
}

int	check_interior(t_game *game)
{
	int	i;
	int	count_exit;
	int	count_playeur;
	int	count_collect;

	i = 1;
	count_exit = 0;
	count_playeur = 0;
	count_collect = 0;
	game->map_height = game->nb_line;
	while (i < game->map_height - 1)
	{
		if (!check_line_content(game->map[i], &count_exit, &count_playeur,
				&count_collect))
		{
			return (0);
		}
		i++;
	}
	game->item = count_collect;
	return (validate_counts(count_exit, count_playeur, count_collect));
}
