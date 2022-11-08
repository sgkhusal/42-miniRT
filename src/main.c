/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:58:57 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/06 15:170 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	get_color(t_ray ray, t_sphere *s, t_light light,
					t_intersection *hit)
{
	t_vector			color;
	t_vector			normal;
	t_vector			eye;
	t_point				point;

	point = ray_position(ray, hit->t);
	normal = sphere_normal_at(s, point);
	eye = negative_vector((ray.direction));
	color = lighting(s->material, light, point, normal, eye);
	if (color.x > 1)
		color.x = 1;
	if (color.y > 1)
		color.y = 1;
	if (color.z > 1)
		color.z = 1;
	return (color);
}

// 1m = 200px
void	rendering_rays(t_vector **pixel_color, t_rt *rt)
{
	t_ray				ray;
	int					x_mlx; // 0 - 500
	int					y_mlx; // 0 - 500
	t_point				ray_origin;
	t_vector			ray_direction;
	t_sphere			*s;
	t_intersection_list	list;
	t_intersection		*hit;
	t_xs				xs;
	t_object			*o;

	x_mlx = 0;
	y_mlx = 0;
	ray_origin = set_point(0, 0, -5);
	s = create_sphere();
	s->material.normalized_color = set_vector(1, 0.2, 1);
	o = create_object(SPHERE, s);
	rt->world.light.position = set_point(-10, 10, -10);
	rt->world.light.intensity = set_vector(1, 1, 1);
	/* t_matrix translation;
	translation = translation_matrix(0.5, 0.75, 0);
	set_transform(s, translation);
	t_matrix scaling;
	scaling = scaling_matrix(0.25, 0.25, 0.25); */
	//set_transform(s, (scaling));
	//set_transform(s, multiply_matrix(translation, scaling));
	//free_matrix(translation);
	//free_matrix(scaling);
	init_intersection_list(&list);
	hit = NULL;
	while (y_mlx < HEIGHT)
	{
		while (x_mlx < WIDTH)
		{
			ray_direction = set_vector((double)(x_mlx - WIDTH / 2) / PPU,
					(double)(-y_mlx + HEIGHT / 2) / PPU, 15); //z = posição da tela ou "parede" em relação a camera
			//printf("ray direction: %f %f %f\n", ray_direction.x, ray_direction.y, ray_direction.z);
			ray = set_ray(ray_origin, normalize_vector(ray_direction));
			xs = sphere_intersection(ray, *s);
			if (xs.count == 2)
			{
				add_intersection_node(create_intersection(xs.t1, o), &list);
				add_intersection_node(create_intersection(xs.t2, o), &list);
			}
			if (list.head)
				hit = get_hit_intersection(list);
			if (hit)
			{
				//printf("intersection in x = %d, y = %d - t = %f\n", x_mlx, y_mlx, hit->t);
				pixel_color[y_mlx][x_mlx] = get_color(ray, s, rt->world.light, hit);
			}
			free_intersection_list(&list);
			hit = NULL;
			x_mlx++;
		}
		x_mlx = 0;
		y_mlx++;
	}
	free_objects(&o);
}

int	main(int argc, char *argv[])
{
	t_mlx		mlx;
	t_rt		rt;
	t_vector	**canvas;

	if (handle_input(argc, argv[1], &rt) == ERROR)
		exit (EXIT_FAILURE);
	free_objects(&rt.world.objects); // /* remove */
	create_mlx_window(&mlx);
	create_mlx_image(&mlx.img, &mlx);
	canvas = create_canvas();
	rt.world = default_world();
	rendering_rays(canvas, &rt);
	plot_image(&mlx.img, &mlx, canvas);
	free_objects(&rt.world.objects);
	free_canvas(canvas);
	set_mlx_hooks(&mlx);
	mlx_loop(mlx.ptr);
	return (0);
}
