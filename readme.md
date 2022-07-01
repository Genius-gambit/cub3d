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

****** COMMENTED OUT MLX FROM Makefile && main.c FOR LEAKCHECKS *******

***Each type of element can be set in any order in the file.***

To Generate Suppression messages:
--gen-suppressions=yes

Valgrind:
valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes --suppressions=valgrind_filter.supp ./cub3d
***Remember to add filename.cub at end***

42Docs guide on raycasting:
https://lodev.org/cgtutor/raycasting.html

```

`#BUGS: #2`

1.	~~***HA:***	Segfaul in `get_next_line();` due to `ft_strchr();` in `libft`~~
2.	~~***HA:***	Function parses whole file, should stop at first line of map~~
3.	~~***HA:***	Leak in `extract_file();` line `#26`~~

`#TODO:`

1.	~~***HA:***	Incorprate `get_next_line();` in `ft_reading();`~~
2.	~~***HA:***	Refactor `isdir();` and double check project for forbidden functions~~
3.	***MA:***	Parse and store map in separate 2D array
4.	~~***HA:***	Figure out how to separate map from configurations~~
5.	~~***HA:***	Add `make vg` rule in Makefile for debugging~~
6.	~~***HA:***	Debug segfault in `get_size();` due to~~
7.	~~***HA:***	Double check space stripping in squash~~
8.	***HA:***	Study Raycasting
9.	***HA:***	Discuss images to be used with **`MA`**

`#CURRENT STATUS`

`HA:	1 Jul 2022`

1.	New files to split functions `parse_file.c`, `errors.c`, `parse_file.c`
2.	Added .gitignore
3.	Created new Function `err_return();` to exit status 1 with correct error message
4.	Added get_next_line(); and minilibx_opengl
5.	Added debugger files to run debugger
6.	Refactored function `ft_reading();` and, now static `init();`
7.	New functions `get_size();` to get number of lines in file in `utils_parse.c`
8.	New struct pointer in `t_info` called `t_data`
9.	New function static `extract_data();` to extract data from file and store in a 2D array
10.	Added my `libft` function `ft_strchr();` to cub3d libft
11.	Added new function `ft_ptrptrlen();` to our libft returns 2D array size
12.	Added new function `ft_isspace();` to our libft, if ascii whitespace return `TRUE`
13.	New function `clean_file();` in new file `utils_file.c` to clean file input
14.	Helper functions for above `squash();` and `count_str_size();`. Squash removes all excess whitespaces in line and `count_str_size();` returns correct str size without excess white spaces
15.	New function called `free_split();` to free 2D arrays in new file `memory_mngmnt.c`
16.	Parsing Configurations almost complete, see `TODO #4`
17.	Moved function `get_act_size();` to file `utils_parse.c`
18.	New file `utils_file_ext.c` with functions `**squash_lines();` and, new function, `check_line(); to only clean file up to last line not including map to be left for parsing.
19.	Cleaning file complete.
20.	`make vg` rule added, see Makefile
21.	Leak found and fixed in `clean_whitespaces();` was missing a pointer

`MA:`
