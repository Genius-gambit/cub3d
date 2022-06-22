/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 22:13:55 by hawadh            #+#    #+#             */
/*   Updated: 2022/06/22 15:02:52 by makhtar          ###   ########.fr       */
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
		count++;
		free(str);
		str = get_next_line(fd);
	}
	if (str)
		free(str);
	close(fd);
	return (count);
}
