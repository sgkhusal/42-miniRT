/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_render_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:06:05 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/11 23:55:41 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

static void	transform_sphere(t_object *s, int type)
{
	t_matrix	translation;
	t_matrix	scaling;

	if (type == 0)
		return ;
	if (type == 1 || type == 3)
		translation = translation_matrix(5, -3, 2);
	if (type == 2 || type == 3)
		scaling = scaling_matrix(2, 2, 2);
	if (type == 1)
		set_transform(s, translation);
	else if (type == 2)
		set_transform(s, scaling);
	else if (type == 3)
	{
		set_transform(s, multiply_matrix(translation, scaling));
		free_matrix(translation);
		free_matrix(scaling);
	}
}

static t_vector	set_pixel_color(t_point ray_origin, int x, int y, t_rt *rt)
{
	t_ray				ray;
	t_ray				transformed_ray;
	t_vector			ray_direction;
	t_intersection_list	list;
	t_intersection		*hit;
	t_xs				xs;
	t_vector			color;

	hit = NULL;
	color = set_vector(0, 0, 0);
	init_intersection_list(&list);
	ray_direction = set_vector((double)(x - WIDTH / 2) / PPU,
					(double)(-y + HEIGHT / 2) / PPU, 15); //z = posição da tela ou "parede" em relação a camera
	ray = set_ray(ray_origin, normalize_vector(ray_direction));
	transformed_ray = transform_ray(ray, rt->world.objects->inverse);
	xs = sphere_intersection(transformed_ray, rt->world.objects);
	if (xs.count == 2)
		add_intersections(xs, rt->world.objects, &list);
	if (list.head)
		hit = get_hit_intersection(list);
	if (hit)
		color = get_color(ray, rt->world.objects, rt->world.light, hit);
	free_intersection_list(&list);
	return (color);
}

// 1m = 100px
static void	rendering_rays(t_vector **pixel_color, t_rt *rt)
{
	t_point	ray_origin;
	int		x_mlx;
	int		y_mlx;

	x_mlx = 0;
	y_mlx = 0;
	ray_origin = set_point(0, 0, -5);
	while (y_mlx < HEIGHT)
	{
		while (x_mlx < WIDTH)
		{
			pixel_color[y_mlx][x_mlx] = set_pixel_color(
				ray_origin, x_mlx, y_mlx, rt);
			x_mlx++;
		}
		x_mlx = 0;
		y_mlx++;
	}
}

void	sphere_render_test(void)
{
	t_mlx		mlx;
	t_rt		rt;
	t_object	*s;
	t_vector	**canvas;

	create_mlx_window(&mlx);
	create_mlx_image(&mlx.img, &mlx);
	canvas = create_canvas();
	s = create_object(SPHERE, create_sphere());
	transform_sphere(s, 3);
	s->material.normalized_color = set_vector(1, 0.2, 1);
	rt.world.objects = NULL;
	append_object(&rt.world.objects, s);
	rt.world.light.position = set_point(-10, 10, -10);
	rt.world.light.intensity = set_vector(1, 1, 1);
	rendering_rays(canvas, &rt);
	plot_image(&mlx.img, &mlx, canvas);
	free_canvas(canvas);
	free_objects(&(rt.world.objects));
	set_mlx_hooks(&mlx);
	mlx_loop(mlx.ptr);
}
