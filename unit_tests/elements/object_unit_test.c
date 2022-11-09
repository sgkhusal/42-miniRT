/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_unit_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:30:46 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/09 17:01:07 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

void	create_object_test(void)
{
	t_object	*object;
	t_sphere	*sphere;
	t_matrix	identity;
	t_color		color;

	printf(GREY "create_object_test: " END);
	color = set_color(255, 0, 0);
	sphere = create_sphere();
	object = create_object(SPHERE, sphere);
	identity = identity_matrix(4);
	if (object->shape.sphere->center.x == 0
		&& object->shape.sphere->center.y == 0
		&& object->shape.sphere->center.z == 0
		&& object->shape.sphere->radius == 1
		&& check_equal_matrices(object->transform, identity)
		&& check_equal_matrices(object->inverse, identity)
		&& check_equal_matrices(object->transpose_inverse, identity)
		&& object->material.ambient == 0.1 && object->material.diffuse == 0.9
		&& object->material.shininess == 200
		&& object->material.specular == 0.9)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	free_matrix(identity);
	free_objects(&object);
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
