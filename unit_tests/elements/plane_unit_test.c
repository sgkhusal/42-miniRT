/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_unit_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 12:09:32 by elraira-          #+#    #+#             */
/*   Updated: 2022/11/26 14:40:10 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

void	create_plane_test(void)
{
	t_plane	*plane;

	printf(GREY "create plane test: " END);
	plane = create_plane();
	if (check_equal_points(plane->point, set_point(0, 0, 0))
		&& check_equal_vectors(plane->orientation, set_vector(0, 1, 0)))
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	free(plane);
}

void	plane_intersection_test(t_ray ray, t_object *p, int count, double t)
{
	t_xs		xs;
	static int	n = 1;

	printf(GREY "plane_intersection_test %d: " END, n);
	xs = plane_intersection(ray, p);
	if (xs.count == 0 && count == 0)
		printf(GREEN "OK" END "\n");
	else if (xs.count == 1 && check_double_values(xs.t1, t))
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	n++;
}

// first test is a ray parallel to the plane, it should not intersect
// second test is a ray coplanar with the plane, it should not intersect
// third test is a ray intersecting the plane from above, it should intersect
// fourth test is a ray intersecting the plane from below, it should intersect
void	plane_tests(void)
{
	t_object	*plane;
	t_ray		ray;

	printf(YELLOW "Plane Tests: " END "\n");
	create_plane_test();
	plane = create_object(PLANE, create_plane());
	ray = set_ray(set_point(0, 10, 0), set_vector(0, 0, 1));
	plane_intersection_test(ray, plane, 0, 0);
	ray = set_ray(set_point(0, 0, 0), set_vector(0, 0, 1));
	plane_intersection_test(ray, plane, 0, 0);
	ray = set_ray(set_point(0, 1, 0), set_vector(0, -1, 0));
	plane_intersection_test(ray, plane, 1, 1);
	ray = set_ray(set_point(0, -1, 0), set_vector(0, 1, 0));
	plane_intersection_test(ray, plane, 1, 1);
	free_objects(&plane);
}
