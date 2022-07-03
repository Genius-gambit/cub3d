/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@Student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 23:05:19 by hawadh            #+#    #+#             */
/*   Updated: 2022/07/03 23:13:10 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	init_mouse(t_info *info)
{
	if (!info->mouse)
	{
		info->mouse = (t_mouse *)ft_calloc(1, sizeof(t_mouse));
		info->mouse->m_x = (int *)ft_calloc(1, sizeof(int));
		info->mouse->m_y = (int *)ft_calloc(1, sizeof(int));
	}
	if (!info->mouse || !info->mouse->m_y || !info->mouse->m_y)
	{
		free_data(info);
		err_return(4);
	}
}
