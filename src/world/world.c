/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:24:39 by elraira-          #+#    #+#             */
/*   Updated: 2022/10/29 10:443:09 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_world	default_world(void)
{
	t_world		world;
	t_object	*o1;
	t_object	*o2;

	world.light.position = set_point(-10, 10, -10);
	world.objects = NULL;
	o1 = NULL;
	o2 = NULL;
	world.light.intensity = set_vector(1, 1, 1);
	o1 = create_object(SPHERE, create_sphere());
	o1->material.color = set_vector(0.8, 1.0, 0.6);
	o1->material.diffuse = 0.7;
	o1->material.specular = 0.2;
	append_object(&(world.objects), o1);
	o2 = create_object(SPHERE, create_sphere());
	set_transform(o2, scaling_matrix(0.5, 0.5, 0.5));
	append_object(&(world.objects), o2);
	return (world);
}

void	add_intersections(t_xs xs, t_object *object, t_intersection_list *list)
{
	add_intersection_node(create_intersection(xs.t1, object), list);
	add_intersection_node(create_intersection(xs.t2, object), list);
}

t_intersection_list	intersect_world(t_world world, t_ray ray)
{
	t_intersection_list	list;
	t_xs				xs;
	t_object			*object;
	t_ray				local_ray;

	init_intersection_list(&list);
	object = world.objects;
	while (object)
	{
		local_ray = transform_ray(ray, object->inverse);
		if (object->type == SPHERE)
			xs = sphere_intersection(local_ray, object);
		/* else if (object->type == PLANE)
			xs = plane_intersection(local_ray, object); */
		else if (object->type == CYLINDER)
			xs = cylinder_intersection(local_ray, object);
		if (xs.count == 2)
			add_intersections(xs, object, &list);
		object = object->next;
	}
	intersect_sort(&(list.head));
	return (list);
}

void	render(t_camera camera, t_world w, t_vector **canvas, t_mlx *mlx)
{
	int		x;
	int		y;
	t_ray	ray;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ray = ray_for_pixel(camera, x, y);
			canvas[y][x] = color_at(w, ray);
			x++;
		}
		y++;
	}
	plot_image(&mlx->img, mlx, canvas);
}
