/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 22:13:55 by hawadh            #+#    #+#             */
/*   Updated: 2022/06/22 18:21:11 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	get_size(char *str)
{
	char	*temp;
	size_t	count;
	int		fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		err_return(0);
	count = 0;
	temp = ft_memset((char *)ft_calloc(1, sizeof(char)), 0, 1);
	while (temp)
	{
		free(temp);
		temp = get_next_line(fd);
		count++;
	}
	if (temp)
		free(temp);
	close(fd);
	return (count);
}
