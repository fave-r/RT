/*
** rtv1.h for rtv1 in /home/thibaud/rendu/MUL_2013_rtv1
** 
** Made by thibaud
** Login   <thibaud@epitech.net>
** 
** Started on  Tue Feb 11 19:30:33 2014 thibaud
** Last update Sun Mar 16 20:56:28 2014 thibaud
*/

#ifndef MY_RTV1_H_
#define MY_RTV1_H_

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "mlx.h"

#define WIN_SIZE 600
#define ZERO 0.000000001
#define BLEU 0x0000FF
#define CYAN 0x00FFFF
#define JAUNE 0xFFFF00
#define MAGENTA 0xFF00FF
#define ROUGE 0xFF0000
#define VERT 0x00FF00
#define NOIR 0x000000
#define BLANC 0xFFFFFF
#define ORANGE 0xFF3300

typedef struct  s_mlx
{
  void		*mlx_ptr;
  void		*win_ptr;
  void		*img_ptr;
  char		*data;
}               t_mlx;

typedef struct	s_vec3
{
  float		x;
  float		y;
  float		z;
}               t_vec3;

typedef struct	s_spot
{
  float		x;
  float		y;
  float		z;
  int		color;
  struct s_spot	*next;
}		t_spot;

typedef struct	s_obj
{
  t_vec3	*pos;
  t_vec3	*angle;
  char		*type;
  int		color;
  int		R;
  struct s_obj	*next;
}		t_obj;

typedef struct	s_flag
{
  char		*type;
  float		(* inter)(t_vec3 *, t_vec3 *, int);
  t_vec3	*(* norme)(t_vec3 *);
}		t_flag;

typedef struct	s_eye
{
  t_vec3	*pos;
  t_vec3	*dir;
  t_vec3	*rotation;
}		t_eye;

t_flag	tab[6];

t_spot	*creat_spot_list();
int	ad_spot(t_spot *, int, int, int, int);
t_obj	*creat_obj_list();
int	ad_obj(t_obj *, char *, int, int, t_vec3 *, t_vec3 *);
int	fill_image(t_mlx *, t_obj *, t_spot *);
float	inter_sphere(t_vec3 *, t_vec3 *, int);
float	inter_cylindre(t_vec3 *, t_vec3 *, int);
float	inter_plan(t_vec3 *, t_vec3 *, int);
float	inter_cone(t_vec3 *, t_vec3 *, int);
float	inter_carre(t_vec3 *, t_vec3 *, int);
float	calc_delta(t_vec3 *, t_vec3 *, int, float);
int	my_strcmp(char *, char *);
float	rad_conv(float);
int	gere_expose(t_mlx *);
int	gere_key(int);
int	mlx_put_pixel(char *, int, int, int);
t_mlx	get_data(t_mlx);
t_vec3	*norme_sphere(t_vec3 *);
t_vec3	*norme_plan(t_vec3 *);
t_vec3	*norme_cylindre(t_vec3 *);
t_vec3	*norme_cone(t_vec3 *);
void	init_eye_pos(t_vec3 *);
int	init_obj_pos(float, float, float, t_vec3 *);
int	init_obj_angle(float, float, float, t_vec3 *);
void	init_spot(t_spot *);
int	init_eye(t_eye *);
t_vec3	*inter_obj(t_eye *, float);
t_vec3	*to_light_(t_vec3 *, t_spot *);
int	put_ombre(int, int);
int	ombre(t_obj *, t_eye *, t_obj *, float, t_spot *);
int	place_obj(t_vec3 *, t_vec3 *, t_vec3 *, t_vec3 *);
int	place_obj_inv(t_vec3 *, t_vec3 *, t_vec3 *, t_vec3 *);
float	cut_obj(float, t_vec3 *, t_vec3 *, float, float);
void	rotX(t_vec3 *, float);
void	rotY(t_vec3 *, float);
void	rotZ(t_vec3 *, float);
void	rotate_all(t_vec3 *, t_vec3 *);
void	rotate_all_inv(t_vec3 *, t_vec3 *);
int	translate_pos(t_vec3 *, t_vec3 *);
int	translate_pos_inv(t_vec3 *, t_vec3 *);
int	moove_eye(t_eye *);
int	moove_eye_back(t_eye *);
int	find_type(t_obj *);
int	final_lum(t_spot *);
int	gere_light(t_eye *, float, t_obj *, t_obj *, t_spot *);
int	luminosite(t_eye *, float, t_obj *, t_spot *, int);
int	ad_color(int, int);
int	*color_limit(int *);
int	put_lum(int, float);
int	free_objs(t_obj *);
int	free_spots(t_spot *);
int	free_all(t_obj *, t_spot *);
int	free_eye(t_eye);

#endif