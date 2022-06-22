/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:14:48 by hawadh            #+#    #+#             */
/*   Updated: 2022/06/22 18:20:55 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
**	Returns TRUE if ascii white space 
**/
int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (TRUE);
	return (FALSE);
}
