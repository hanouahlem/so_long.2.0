/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbey <ahbey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:52:55 by ahbey             #+#    #+#             */
/*   Updated: 2024/06/06 12:55:22 by ahbey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_line(char *str, t_game *game)
{
	int		fd;
	int		count;
	char	*line;
	int		i;

	count = 0;
	i = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (0);
	line = "d";
	while (line)
	{
		line = get_next_line(fd);
		if (line)
			count++;
		if (i == 0)
			game->map_width = ft_so_strlen(line);
		i++;
		free(line);
	}
	close(fd);
	return (count);
}

char	**stock_map(t_game *game, char *str)
{
	int		fd;
	char	**tab;
	int		i;

	i = 0;
	game->nb_line = count_line(str, game);
	if (game->nb_line == 0)
		return (ft_printf("Error\nFile invalide\n"), exit(1), NULL);
	tab = malloc(sizeof(char *) * (game->nb_line + 1));
	if (!tab)
		return (NULL);
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error\nFile invalide\n"), exit(1), NULL);
	while (i < game->nb_line)
	{
		tab[i] = get_next_line(fd);
		i++;
	}
	tab[i] = 0;
	free(get_next_line(fd));
	close(fd);
	return (tab);
}
