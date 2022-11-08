/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_unit_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:17:50 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/08 17:45:04 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

void	create_cylinder_test(void)
{
	t_cylinder	*cylinder;
	t_matrix	identity;
	t_color		color;

	printf(GREY "create cylinder test: " END);
	color = set_color(255, 0, 0);
	cylinder = create_cylinder();
	identity = identity_matrix(4);
	if (cylinder->center.x == 0 && cylinder->center.y == 0
		&& cylinder->center.z == 0
		&& cylinder->radius == 1 && cylinder->height == 1
		&& check_equal_vectors(cylinder->orientation, set_vector(0, 1, 0))
		&& check_equal_matrices(cylinder->transform, identity)
		&& check_equal_matrices(cylinder->inverse, identity)
		&& check_equal_matrices(cylinder->transpose_inverse, identity)
		&& cylinder->material.ambient == 0.1
		&& cylinder->material.diffuse == 0.9
		&& cylinder->material.shininess == 200
		&& cylinder->material.specular == 0.9)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	free_matrix(identity);
	free_cylinder(cylinder);
}

void	cylinder_no_intersection_test(t_cylinder *cylinder, t_ray ray)
{
	t_xs		xs;
	static int	n = 1;

	printf(GREY "cylinder_no_intersection_test %d: " END, n);
	xs = cylinder_intersection(ray, *cylinder);
	if (xs.count == 0)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
}

void	cylinder_intersection_test(t_cylinder *c, t_ray ray, double t1,
			double t2)
{
	t_xs				xs;
	static int			n = 1;

	printf(GREY "cylinder_intersection_test %d: " END, n);
	xs = cylinder_intersection(ray, *c);
	if (xs.count == 2 && check_double_values(xs.t1, t1)
		&& check_double_values(xs.t2, t2))
		printf(GREEN "OK" END "\n");
	else
	{
		printf(RED "KO" END "\n");
		printf("xs.count = %d, xs.t1 = %f, xs.t2 = %f\n", xs.count, xs.t1,
			xs.t2);
	}
	n++;
}

void	cylinder_transform_test(void)
{
	t_cylinder	*cylinder;
	t_matrix	transform;

	printf(GREY "cylinder_transform_test: " END);
	cylinder = create_cylinder();
	transform = translation_matrix(2, 3, 4);
	set_transform_cylinder(cylinder, transform);
	if (check_equal_matrices(cylinder->transform, transform))
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	free_cylinder(cylinder);
}

void	cylinder_normal_test(t_cylinder *c, t_point p, t_vector expected)
{
	static int	n = 1;
	t_vector	result;

	printf(GREY "cylinder_normal_test %d: " END, n);
	result = cylinder_normal_at(c, p);
	if (check_equal_vectors(result, expected))
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	n++;
}

void	cylinder_tests(void)
{
	t_cylinder *cylinder;

	printf(YELLOW "Cylinder tests: " END "\n");
	create_cylinder_test();
	cylinder_transform_test();
	cylinder = create_cylinder();
	cylinder_no_intersection_test(cylinder,
		set_ray(set_point(1, 0, 0), set_vector(0, 1, 0)));
	cylinder_no_intersection_test(cylinder,
		set_ray(set_point(0, 0, 0), set_vector(0, 1, 0)));
	cylinder_no_intersection_test(cylinder,
		set_ray(set_point(0, 0, -5), normalize_vector((set_vector(1, 1, 1)))));
	cylinder_intersection_test(cylinder,
		set_ray(set_point(1, 0, -5), set_vector(0, 0, 1)), 5, 5);
	cylinder_intersection_test(cylinder,
		set_ray(set_point(0, 0, -5), set_vector(0, 0, 1)), 4, 6);
	cylinder_intersection_test(cylinder, set_ray(set_point(0.5, 0, -5),
		normalize_vector(set_vector(0.1, 1, 1))), 6.80798, 7.08872);
	cylinder_normal_test(cylinder, set_point(1, 0, 0), set_vector(1, 0, 0));
	cylinder_normal_test(cylinder, set_point(0, 5, -1), set_vector(0, 0, -1));
	cylinder_normal_test(cylinder, set_point(0, -2, 1), set_vector(0, 0, 1));
	cylinder_normal_test(cylinder, set_point(-1, 1, 0), set_vector(-1, 0, 0));
	free_cylinder(cylinder);
}
