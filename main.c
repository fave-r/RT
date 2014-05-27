/*
** main.c for rtv1 in /home/thibaud/rendu/MUL_2013_rtv1
**
** Made by thibaud
** Login   <thibaud@epitech.net>
**
** Started on  Tue Feb 11 19:30:01 2014 thibaud
** Last update Tue May 27 15:55:13 2014 bourrel
*/

#include <float.h>
#include "rtv1.h"

t_flag		tab[] =
  {
    {"PLAN", &inter_plan, &norme_plan},
    {"CYLINDRE", &inter_cylindre, &norme_cylindre},
    {"CONE", &inter_cone, &norme_cone},
    {"SPHERE", &inter_sphere, &norme_sphere},
    {"CARRE", &inter_carre, &norme_plan},
    {"\0", NULL, NULL},
  };

int		inter_objs(t_eye *eye, t_obj *obj, t_spot *spot)
{
  t_light	l;
  t_obj		*cur_obj;
  float		k1;

  cur_obj = obj->next;
  l.clos_obj = NULL;
  l.k2 = FLT_MAX;
  while (cur_obj != NULL)
    {
      place_obj(eye->pos, eye->dir, cur_obj->pos, cur_obj->angle);
      k1 = tab[find_type(cur_obj)].inter(eye->pos, eye->dir, cur_obj->info->R);
      if (k1 <= l.k2 && k1 > ZERO)
	{
	  l.k2 = k1;
	  l.clos_obj = cur_obj;
	}
      place_obj_inv(eye->pos, eye->dir, cur_obj->pos, cur_obj->angle);
      cur_obj = cur_obj->next;
    }
  if (l.clos_obj != NULL)
    return (gere_light(eye, l, obj, spot));
  return (0x000000);
}

int		fill_image(t_mlx *mlx, t_obj *obj, t_spot *spot)
{
  int		x;
  int		y;
  int		color;
  t_eye		eye;

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
  t_info	info;

  init_obj_pos(ZERO - 2000, ZERO, ZERO + 2000, &obj_pos);
  ad_spot(spot, 0x000000, &obj_pos);
  init_obj_pos(ZERO - 2000, ZERO - 1000, ZERO + 2000, &obj_pos);
  ad_spot(spot, 0x000000, &obj_pos);
  init_obj_angle(ZERO, ZERO, ZERO, &obj_angle);
  init_obj_pos(ZERO, ZERO, ZERO - 200, &obj_pos);
  init_info("PLAN", 100, BLEU, &info);
  ad_obj(obj, &info, &obj_pos, &obj_angle);
  init_obj_angle(ZERO, ZERO, ZERO, &obj_angle);
  init_obj_pos(ZERO, ZERO - 200, ZERO + 200, &obj_pos);
  init_info("SPHERE", 100, ROUGE, &info);
  ad_obj(obj, &info, &obj_pos, &obj_angle);
  init_obj_angle(ZERO, ZERO, ZERO, &obj_angle);
  init_obj_pos(ZERO, ZERO + 50, ZERO + 200, &obj_pos);
  init_info("CONE", 3, VERT, &info);
  ad_obj(obj, &info, &obj_pos, &obj_angle);
  init_obj_angle(ZERO, ZERO, ZERO, &obj_angle);
  init_obj_pos(ZERO - 100, ZERO + 300, ZERO, &obj_pos);
  init_info("CYLINDRE", 100, ORANGE, &info);
  ad_obj(obj, &info, &obj_pos, &obj_angle);
  return (0);
}

int		main(int ac, char **av)
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
  if (ac == 2)
    {
      if ((parser(av[1], tab, obj, spot)) == -1)
        return (-1);
    }
  else
    map_1(obj, spot);
  fill_image(&mlx, obj, spot);
  mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img_ptr, 0, 0);
  free_all(obj, spot);
  mlx_expose_hook(mlx.win_ptr, &gere_expose, &mlx);
  mlx_loop(mlx.mlx_ptr);
  return (0);
}
