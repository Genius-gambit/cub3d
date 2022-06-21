/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:27:11 by hawadh            #+#    #+#             */
/*   Updated: 2022/06/21 17:20:34 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	error_print(char *str)
{
	write(2, "\033[1;91m", strlen("\033[1;91m"));
	write(2, str, strlen(str));
	write(2, "\n\033[0m", strlen("\n\033[0m"));
}

/**
**	Print error message
*	status == 0		File Descriptor 
*	status == 1		Empty File
**/
void	err_return(int status)
{
	if (status == 0)
		error_print("ERROR: File Descriptor");
	else if (status == 1)
		error_print("ERROR: Empty File");
	else if (status == 2)
		error_print("ERROR: Arguments");
	else if (status == 3)
		error_print("ERROR: Map not valid");
	exit (1);
}
