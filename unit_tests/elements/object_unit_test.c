/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_unit_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:30:46 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/26 14:39:36 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

void	create_object_test(void)
{
	t_object	*o;
	t_matrix	identity;

	printf(GREY "create_object_test: " END);
	o = create_object(SPHERE, create_sphere());
	identity = identity_matrix(4);
	if (o->shape.sphere->center.x == 0
		&& o->shape.sphere->center.y == 0
		&& o->shape.sphere->center.z == 0
		&& o->shape.sphere->radius == 1
		&& check_equal_matrices(o->transform, identity)
		&& check_equal_matrices(o->inverse, identity)
		&& check_equal_matrices(o->transpose_inverse, identity)
		&& check_equal_vectors(o->material.ambient, set_vector(0.1, 0.1, 0.1))
		&& o->material.diffuse == 0.9
		&& o->material.shininess == 200
		&& o->material.specular == 0.9
		&& check_equal_vectors(o->material.color, set_vector(1, 1, 1)))
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	free_matrix(identity);
	free_objects(&o);
}

void	set_transform_test(void)
{
	t_sphere	*sphere;
	t_object	*object;
	t_matrix	transform;

	printf(GREY "sphere_transform_test: " END);
	sphere = create_sphere();
	object = create_object(SPHERE, sphere);
	transform = translation_matrix(2, 3, 4);
	set_transform(object, transform);
	if (check_equal_matrices(object->transform, transform))
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	free_objects(&object);
}

void	object_tests(void)
{
	printf(YELLOW "Object tests: " END "\n");
	create_object_test();
	set_transform_test();
}
