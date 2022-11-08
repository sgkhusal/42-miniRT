/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_render_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:06:05 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/08 18:53:22 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

// set_transform_sphere(s, translation);
// set_transform_sphere(s, (scaling));
void	transform_sphere(t_sphere *s)
{
	t_matrix	translation;
	t_matrix	scaling;

	translation = translation_matrix(0.5, 0.75, 0);
	scaling = scaling_matrix(0.25, 0.25, 0.25);
	set_transform_sphere(s, multiply_matrix(translation, scaling));
	free_matrix(translation);
	free_matrix(scaling);
}

static t_vector	set_pixel_color(t_point ray_origin, int x, int y, t_rt *rt)
{
	t_ray				ray;
	t_vector			ray_direction;
	t_intersection_list	list;
	t_intersection		*hit;
	t_xs				xs;

	hit = NULL;
	init_intersection_list(&list);
	ray_direction = set_vector((double)(x - WIDTH / 2) / PPU,
					(double)(-y + HEIGHT / 2) / PPU, 15); //z = posição da tela ou "parede" em relação a camera
	ray = set_ray(ray_origin, normalize_vector(ray_direction));
	xs = sphere_intersection(ray, *(t_sphere *)(rt->world.objects->obj));
	if (xs.count == 2)
		add_intersections(xs, rt->world.objects, &list);
	if (list.head)
		hit = get_hit_intersection(list);
	if (hit)
		return (get_sphere_color(ray,
			(t_sphere *)(rt->world.objects->obj), rt->world.light, hit));
	free_intersection_list(&list);
	return (set_vector(0, 0, 0));
}

// 1m = 100px
void	rendering_rays(t_vector **pixel_color, t_rt *rt)
{
	t_point	ray_origin;
	int		x_mlx; // 0 - 500
	int		y_mlx; // 0 - 500

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
	t_sphere	*s;
	t_vector	**canvas;

	create_mlx_window(&mlx);
	create_mlx_image(&mlx.img, &mlx);
	canvas = create_canvas();
	s = create_sphere();
	s->material.normalized_color = set_vector(1, 0.2, 1);
	rt.world.objects = create_object(SPHERE, s);
	rt.world.light.position = set_point(-10, 10, -10);
	rt.world.light.intensity = set_vector(1, 1, 1);
	rendering_rays(canvas, &rt);
	plot_image(&mlx.img, &mlx, canvas);
	free_canvas(canvas);
	free_objects(&(rt.world.objects));
	set_mlx_hooks(&mlx);
	mlx_loop(mlx.ptr);
}
