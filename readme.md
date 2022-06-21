```
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42Abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 17:31:03 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/21 17:31:03 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:38:18 by hawadh            #+#    #+#             */
/*   Updated: 2022/06/21 17:31:31 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
```

```
***NOTES:***

Writing Valgrind suppression file

To Generate Suppression messages:
--gen-suppressions=yes

Valgrind:
valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes --suppressions=valgrind_filter.supp ./cub3d

42Docs guide on raycasting:
https://lodev.org/cgtutor/raycasting.html

```

`#BUGS: #1`

1.	Segfaul in `isdir();` due `stat();` call

`#TODO:`

1.	~***HA:***	Incorprate `get_next_line();` in `ft_reading();`~
2.	***HA:***	Refactor `isdir();` and double check project for forbidden functions
3.	***HA:***	Parse and store map in separate 2D array in `t_info **map`
4.	***HA:***	Add `make vg` rule in Makefile for debugging

`#CURRENT STATUS`

`HA:`
21 Jun 2022

1. New files to split functions `parse_file.c`, `errors.c`, `parse_file.c`
2. Added .gitignore
3. Created new Function `err_return();` to exit status 1 with correct error message
4. Added get_next_line(); and minilibx_opengl
5. Added debugger files to run debugger
6. Refactored function `ft_reading();` and, now static `init();`
7. New functions `get_size();` to get number of lines in file in `utils_parse.c`
8. New struct pointer in `t_info` called `t_data`
9. New function static `extract_data();` to extract data from file and store in a 2D array


`MA:`
