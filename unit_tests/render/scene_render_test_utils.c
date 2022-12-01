/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_render_test_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 23:56:11 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/01 00:05:02 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

static void	put_right_sphere(t_world *w)
{
	t_object	*right;
	t_matrix	translation;
	t_matrix	scaling;

	right = create_object(SPHERE, create_sphere());
	right->material.color = set_vector(0.5, 1, 0.1);
	right->material.diffuse = 0.7;
	right->material.specular = 0.3;
	translation = translation_matrix(1.5, 0.5, -0.5);
	scaling = scaling_matrix(0.5, 0.5, 0.5);
	set_transform(right, multiply_matrix(translation, scaling));
	append_object(&(w->objects), right);
	free_matrix(translation);
	free_matrix(scaling);
}

static void	put_left_sphere(t_world *w)
{
	t_object	*left;
	t_matrix	translation;
	t_matrix	scaling;

	left = create_object(SPHERE, create_sphere());
	left->material.color = set_vector(1, 0.8, 0.1);
	left->material.diffuse = 0.7;
	left->material.specular = 0.3;
	translation = translation_matrix(-1.5, 0.33, -0.75);
	scaling = scaling_matrix(0.33, 0.33, 0.33);
	set_transform(left, multiply_matrix(translation, scaling));
	append_object(&(w->objects), left);
	free_matrix(translation);
	free_matrix(scaling);
}

void	put_elements(t_world *w)
{
	t_object	*middle;
	t_object	*left;

	middle = create_object(SPHERE, create_sphere());
	middle->material.color = set_vector(0.1, 1, 0.5);
	middle->material.diffuse = 0.7;
	middle->material.specular = 0.3;
	set_transform(middle, translation_matrix(-0.5, 1, 0.5));
	append_object(&(w->objects), middle);
	put_left_sphere(w);
	put_right_sphere(w);
}
