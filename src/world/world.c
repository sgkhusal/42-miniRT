/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:24:39 by elraira-          #+#    #+#             */
/*   Updated: 2022/11/27 14:41:220 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief An auxiliary function to add intersections to the list of
 * intersections.
 *
 * @param xs intersection
 * @param object object
 * @param list list of intersections
 */
void	add_intersections(t_xs xs, t_object *object, t_intersection_list *list)
{
	add_intersection_node(create_intersection(xs.t1, object), list);
	add_intersection_node(create_intersection(xs.t2, object), list);
}

/**
 * @brief This function will return an intersection list with all the
 * intersections between the ray and the objects in the world by calling
 * each object's local_intersect function. It will also sort the list
 * by the t value.
 *
 * @param world is the world.
 * @param ray is the ray struct.
 * @return t_intersection_list the intersection list.
 */
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
		else if (object->type == PLANE)
			xs = plane_intersection(local_ray, object);
		else if (object->type == CYLINDER)
			xs = cylinder_intersection(local_ray, object);
		if (xs.count == 2)
			add_intersections(xs, object, &list);
		if (xs.count == 1)
			add_intersection_node(create_intersection(xs.t1, object), &list);
		object = object->next;
	}
	intersect_sort(&(list.head));
	return (list);
}

/**
 * @brief This is the main rendering function. It will cast a ray from the
 * camera to each pixel of the canvas and return a canvas with the color of
 * each pixel. It will also plot the image using the mlx library. The
 * ray_for_pixel function will do the job of calculating the ray from the
 * camera to the location of the pixel.
 *
 * @param camera is the camera struct.
 * @param w is the world struct.
 * @param canvas is the canvas struct.
 * @param mlx is the mlx struct.
 */
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
