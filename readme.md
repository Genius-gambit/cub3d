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

***Each type of element can be set in any order in the file.***

To Generate Suppression messages:
--gen-suppressions=yes

Valgrind:
valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes --suppressions=valgrind_filter.supp ./cub3d
***Remember to add filename.cub at end***

42Docs guide on raycasting:
https://lodev.org/cgtutor/raycasting.html

```

`#BUGS: #NULL`

1.	~~***HA:***	Segfaul in `get_next_line();` due to `ft_strchr();` in `libft`~~
2.	~~***HA:***	Function parses whole file, should stop at first line of map~~
3.	~~***HA:***	Leak in `extract_file();` line `#26`~~
4.	***HA:***	segfault when moving mouse in window in function `mlx_mouse_get_pos();` in function `draw_cursor();`

`#TODO:`

1.	~~***HA:***	Incorprate `get_next_line();` in `ft_reading();`~~
2.	~~***HA:***	Refactor `isdir();` and double check project for forbidden functions~~
3.	~~***MA:***	Parse and store map in separate 2D array~~
4.	~~***HA:***	Figure out how to separate map from configurations~~
5.	~~***HA:***	Add `make vg` rule in Makefile for debugging~~
6.	~~***HA:***	Debug segfault in `get_size();` due to~~
7.	~~***HA:***	Double check space stripping in squash~~
8.	***HA:***	Study Raycasting
9.	***HA:***	Discuss images to be used with **`MA`**
10.	***HA:***	Figure out correct drawing and following of mouse cursor

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
22.	Added new function to libft: `ft_strrmc();` removes `char c` from array
23.	Uncomment of MLX related lines in Makefile, MLX now functional in Program
24.	`mlx_loop();` now called in function `init();`
25.	Window now initialised and opening, by adding function calls `mlx_new_window();` in `main.c` function `init();`
26.	Two new files, `window.c` for window functions and `utils_hooks.c` for key hook utilities
27.	Calling `mlx_key_hook();` int `init();` that calls new function `key_hook_manage();` which currently only handles **ESC**
28. New function `esc_win();` which calls `free_data();` and `exit(0);`, this function handles both `(x) and esc`
29.	Calling `mlx_hook();` in `init();` to handle above `(x)`
30.	Two new functions in `window.c` to initialise and store window + image address, `init_window();` and `get_img_addr();`
31.	New file `draw.c` contains 2 new functions `draw_cursor();` and `my_pixel_put();`
32.	Function draw cursor calls `MLX` function `mlx_mouse_get_pos();` to get mouse position for cursor drawing ***WIP***
33.	Updated `memory_mngmnt.c` with 3 new `free_struct_???();` functions one for each struct and struct members
34.	Added error message `ERROR: Minilibx Failure` for any failure from minilibx functions
35.	Added print loop in `check_map();` to print file contents after cleaning and parsing
36.	Refactored `draw_cursor();` and new function `init_mouse();` in new file `mouse.c`
37.	New file `hooks.c` to contain new function `hook_management();` to hold all `mlx_hook();` calls
38.	Refactored `draw_cursor();` and new function `mouse_data();` calls draw_cursor();` from within `hook_management();`
39.	`Moved mlx_loop();` to `window.c` called in function `init_window();`

`MA:`

1. Parsing for different types of layout is finished. Memory leaks, and norms are done.
2. For better reference please read the comments to know what is the structure for parser.
3. Changed char to const char in ft_strcmp.

`TODO:`
1. Take xpm files and read it to check if the file reading is working perfectly or not.
2. Declare a new structure to fetch the info and place it in the main root of the structure which will work on every aspect of the program.
3. Time for raycasting math to solve.
