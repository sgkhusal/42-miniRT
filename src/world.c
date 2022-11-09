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
	t_sphere	*s1;
	t_sphere	*s2;

	world.light.position = set_point(-10, 10, -10);
	world.light.intensity = set_vector(1, 1, 1);
	s1 = create_sphere();
	s1->material.normalized_color = set_vector(0.8, 1.0, 0.6);
	s1->material.diffuse = 0.7;
	s1->material.specular = 0.2;
	world.objects = NULL;
	append_object(&(world.objects), create_object(SPHERE, s1));
	s2 = create_sphere();
	set_transform_sphere(s2, scaling_matrix(0.5, 0.5, 0.5));
	append_object(&(world.objects), create_object(SPHERE, s2));
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

	init_intersection_list(&list);
	object = world.objects;
	while (object)
	{
		if (object->type == SPHERE)
			xs = sphere_intersection(ray, *(object->shape.sphere));
		/* else if (object->type == PLANE)
			xs = plane_intersection(ray, *(object->shape.plane));
		else if (object->type == CYLINDER)
			xs = cylinder_intersection(ray, *(object->shape.cylinder)); */
		if (xs.count == 2)
			add_intersections(xs, object, &list);
		object = object->next;
	}
	intersect_sort(&(list.head));
	return (list);
}
