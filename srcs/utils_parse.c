/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 22:13:55 by hawadh            #+#    #+#             */
/*   Updated: 2022/06/21 22:52:10 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	get_size(int fd)
{
	char	*str;
	size_t	count;

	count = 0;
	str = ft_memset((char *)ft_calloc(1, sizeof(char)), 0, 1);
	while (str)
	{
		free(str);
		str = get_next_line(fd);
		count++;
	}
	if (str)
		free(str);
	close(fd);
	return (count);
}
