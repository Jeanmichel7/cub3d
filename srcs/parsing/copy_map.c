/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 01:30:17 by jrasser           #+#    #+#             */
/*   Updated: 2022/07/13 23:51:24 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_fill_map(t_data *data, t_list *list)
{
	int		i;

	data->map.tab = malloc(sizeof(char *) * (data->map.height + 1));
	i = 0;
	while (list)
	{
		data->map.tab[i] = malloc(sizeof(char) * (ft_strlen(list->content) + 1));
		ft_strlcpy(data->map.tab[i], list->content, ft_strlen(list->content) + 1);
		//free(list->content);
		list = list->next;
		i++;
	}
	data->map.tab[i] = NULL;
}

int	ft_check_map_line(char *line, t_data *data)
{
	int		i;
	char	c;

	i = 0;
	if (line)
		c = line[i];
	while (line && c)
	{
		if (c != '0' && c != '1' && c != 'N' && c != 'S' && c != 'E' \
		&& c != 'W' && c != ' ')
		{
			printf("Invalid caracter '%c' on the map\n", c);
			return (1);
		}
		if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
			data->player_spawn_dir = c;
		i++;
		c = line[i];
	}
	return (0);
}

void	ft_copy_map(char *line, t_data *data)
{
	t_list	*list;
	char	*line_temp;

	data->map.width = ft_strlen(line);
	list = ft_lstnew(line);
	while (line && line[0] != '\0')
	{
		//printf("line cp map: %s\n", line);
		if (ft_check_map_line(line, data))
		{
			//free
			exit(0);
		}
		if ((int)ft_strlen(line) > data->map.width)
			data->map.width = (int)ft_strlen(line);
		if (data->map.height != 0)
		{
			line_temp = malloc(sizeof(char) * (ft_strlen(line) + 1));
			ft_strlcpy(line_temp, line, (ft_strlen(line) + 1));
			ft_lstadd_back(&list, ft_lstnew(line_temp));
		}
		//free(line);
		line = get_next_line(data->fd);
		data->map.height++;
	}
	ft_fill_map(data, list);
	if (ft_check_map(data))
	{
		printf("Map is open\n");
		//free
		exit (0);
	}
	//ft_lstclear(&list, ft_del_list);
}