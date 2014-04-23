/*
** main.c for rtv1 in /home/thibaud/rendu/MUL_2013_rtv1
** 
** Made by thibaud
** Login   <thibaud@epitech.net>
** 
** Started on  Tue Feb 11 19:30:01 2014 thibaud
** Last update Sun Mar 16 21:00:22 2014 thibaud
*/

#include "rtv1.h"
#include <float.h>

t_flag	tab[] =
  {
    {"PLAN", &inter_plan, &norme_plan},
    {"CYLINDRE", &inter_cylindre, &norme_cylindre},
    {"CONE", &inter_cone, &norme_cone},
    {"SPHERE", &inter_sphere, &norme_sphere},
    {"CARRE", &inter_carre, &norme_plan},
    {"\0", NULL, NULL},
  };

int	inter_objs(t_eye *eye, t_obj *obj, t_spot *spot)
{
  t_obj	*cur_obj;
  t_obj	*clos_obj;
  float	k1;
  float	k2;

  cur_obj = obj->next;
  clos_obj = NULL;
  k2 = FLT_MAX;
  while (cur_obj != NULL)
    {
      place_obj(eye->pos, eye->dir, cur_obj->pos, cur_obj->angle);
      k1 = tab[find_type(cur_obj)].inter(eye->pos, eye->dir, cur_obj->R);
      if (k1 <= k2 && k1 > ZERO)
	{
	  k2 = k1;
	  clos_obj = cur_obj;
	}
      place_obj_inv(eye->pos, eye->dir, cur_obj->pos, cur_obj->angle);
      cur_obj = cur_obj->next;
    }
  if (clos_obj != NULL)
    return (gere_light(eye, k2, clos_obj, obj, spot));
  return (0x000000);
}

int	fill_image(t_mlx *mlx, t_obj *obj, t_spot *spot)
{
  int	x;
  int	y;
  int	color;
  t_eye	eye;

  init_eye(&eye);
  y = 0;
  eye.dir->x = 500;
  while (y <= WIN_SIZE)
    {
      x = 0;
      while (x <= WIN_SIZE)
	{
	  eye.dir->y = WIN_SIZE / 2 - x;
	  eye.dir->z = WIN_SIZE / 2 - y;
	  moove_eye(&eye);
	  color = inter_objs(&eye, obj, spot);
	  moove_eye_back(&eye);
	  mlx_put_pixel(mlx->data, x, y, color);
	  x++;
	}
      y++;
    }
  free_eye(eye);
  return (0);
}

int		map_1(t_obj *obj, t_spot *spot)
{
  t_vec3	obj_pos;
  t_vec3	obj_angle;

  ad_spot(spot, ZERO - 2000, ZERO, ZERO + 2000, 0x000000);
  ad_spot(spot, ZERO - 2000, ZERO - 1000, ZERO + 2000, 0x000000);
  init_obj_angle(ZERO, ZERO, ZERO, &obj_angle);
  init_obj_pos(ZERO, ZERO, ZERO - 200, &obj_pos);
  ad_obj(obj, "PLAN", 100, BLEU, &obj_pos, &obj_angle);
  init_obj_angle(ZERO, ZERO, ZERO, &obj_angle);
  init_obj_pos(ZERO, ZERO - 200, ZERO + 200, &obj_pos);
  ad_obj(obj, "SPHERE", 100, ROUGE, &obj_pos, &obj_angle);
  init_obj_angle(ZERO, ZERO, ZERO, &obj_angle);
  init_obj_pos(ZERO - 300, ZERO + 100, ZERO + 20, &obj_pos);
  ad_obj(obj, "SPHERE", 100, JAUNE, &obj_pos, &obj_angle);
  init_obj_angle(ZERO, ZERO, ZERO, &obj_angle);
  init_obj_pos(ZERO, ZERO + 50, ZERO + 200, &obj_pos);
  ad_obj(obj, "CONE", 3, VERT, &obj_pos, &obj_angle);
  init_obj_angle(ZERO, ZERO, ZERO, &obj_angle);
  init_obj_pos(ZERO - 100, ZERO + 300, ZERO, &obj_pos);
  ad_obj(obj, "CYLINDRE", 100, ORANGE, &obj_pos, &obj_angle);
  return (0);
}

int		main()
{
  t_mlx		mlx;
  t_obj		*obj;
  t_spot	*spot;

  if ((mlx.mlx_ptr = mlx_init()) == NULL)
    exit(-1);
  mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, WIN_SIZE, WIN_SIZE, "rtv1");
  mlx_key_hook(mlx.win_ptr, &gere_key, &mlx);
  mlx.img_ptr = mlx_new_image(mlx.mlx_ptr, 600, 600);
  mlx = get_data(mlx);
  obj = creat_obj_list();
  spot = creat_spot_list();
  map_1(obj, spot);
  fill_image(&mlx, obj, spot);
  mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img_ptr, 0, 0);
  free_all(obj, spot);
  mlx_expose_hook(mlx.win_ptr, &gere_expose, &mlx);
  mlx_loop(mlx.mlx_ptr);
  return (0);
}
