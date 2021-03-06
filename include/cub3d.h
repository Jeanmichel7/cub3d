/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:29:54 by ydumaine          #+#    #+#             */
/*   Updated: 2022/07/19 16:31:28 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "../mlx_mac/mlx.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include <math.h>

#define PI 3.1415926535
#define	BLOCK_SIZE 48
#define	SPEED 6

typedef struct s_map
{
	char	**tab;
	int		width;
	int		height;
}	t_map;

typedef struct ray_data
{
	double	dist_cam_ecran; // dist plan camera
	double	orientation;
	double	angle_between_radius;
	double	pos_x;			// position du joueur 
	double	pos_y;
	double	plan_x;			// ecran de projection
	double	plan_y;
	double	center_plan_x;
	double	center_plan_y;



	double	resolution_x; 
	double	resolution_y; 
	
	int		map_x; // position du carre dans lequel est le joueur sur la carte
	int		map_y; 
	double	side_x; //distance a parcourir avant la premiere intersection de la position du joueur 
	double	side_y;
	double	delta_x;// distance a parcourir avant une intersection 
	double	delta_y;
	int		step_x; // sens du rayon ( positif ou negatif ) x
	int		step_y; // sens du rayon ( positif ou negatif ) y
	int		hit;	// indique si un mur a ete touche 
	int		side;
	int		walldistance; // distance du rayon jusqu au mur
	int		lineheight; // hauteur de la ligne de pixel 
	int		drawstart; // debut de la ligne de pixel 
	int		drawend;  // fin de la ligne de pixel 
	int		color; 
	char	 **map;
}	t_ray;

typedef struct s_data
{
	void	*mlx_win;
	void	*mlx;
	void	*mlx_img;
	char	*img_data;
	char	*texture_N;
	char	*texture_S;
	char	*texture_W;
	char	*texture_E;
	int		color_floor; 			//color
	int		color_ceiling;			//color
	int		bpp;					// mlx_get_data_addr
	int		size_line;				// mlx_get_data_addr
	int		endian;					// mlx_get_data_addr

	int		fd;
	//void	*display;			// ray casting
	//char	*display_add;		// ray casting

	int		forward;
	int		backward;
	int		right;
	int		left;
	int		rotate_right;
	int		rotate_left;
	int		key;

	int		angle;
	char	player_spawn_dir;
	int		player_spawn_x;
	int		player_spawn_y;
	int		fov;
	int		resolution_x;
	int		resolution_y;
	t_map	map;
	int		is_map_started;
	t_ray	ray_data; 
}	t_data;

typedef	struct s_map_data
{
	char	**map;
	int		x_start;
	int		y_start;
	int		posX;
	int		posY;
	int		width;
	int		height;
	char	dir;
	int		nb_pass;
	int		no_move_possible;
	int		is_againt_wall;
}	t_map_data;


/* MAIN */
void	ft_init_data(t_data *data);
void	ft_init_display(t_data *data);
int		ft_exit_game(t_data *data);


/* CHECKER */
int		ft_checker(int argc, char **argv, t_data *data);
int		ft_nb_section_split(char **line_splited);

/* PARSING */
int 	ft_parsing(t_data *data);
void	ft_sub_fill_caract(char **caract, char *str);
int		ft_nb_section_split(char **line_splited);
void	ft_parse_color(int *color, char **tab);
int		ft_check_comma(char	*str);
int		ft_check_miss_caract(t_data *data);

/* CHECKER MAP */
void	ft_replace_space(t_data *data);
int		ft_check_out(t_map_data *d);
int		ft_move_is_valid(t_map_data *map_data, char *c);
void	ft_move(t_map_data *d);
int		ft_is_againt_wall(t_map_data *d);

/* PARSING MAP */
void	ft_copy_map(char *line, t_data *data);
int		ft_map_begin(char *line);
int		ft_is_map_border(char *line);
int		ft_check_map(t_data *data);
int		ft_follow_wall(t_map_data *d);
void	ft_sub_fill_color(t_data *data, char *str1, char *str2, char *line);
void	ft_sub_fill_texture(t_data *data, char *str1, char *str2, char *line);



/* MANAGE KEY */
int		ft_press_key(int key, t_data *data);
int		ft_release_key(int key, t_data *data);

/* RAYCASTING */
int		manage_keys(int key, t_data *data);

int		ft_raycaster(t_data *d);
double	ft_conv_in_rad(double degre);

/* CALC DIST RAY */
double	ft_dist_sur_x(t_data *d, double angle);
double	ft_dist_sur_y(t_data *d, double angle);



/* TEST */
void	ft_fill_line(t_data *d);


/* FREE */
int		ft_free_texture(t_data *data);
void	ft_free_tab(char **tab);
void	ft_close_and_free(t_data *data);
void	ft_free_list(t_list *list);

/* DEBUG */
void	ft_printdata(t_data *data);
void	ft_print_map(t_map_data *data);

#endif
