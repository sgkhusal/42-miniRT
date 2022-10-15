/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 20:07:02 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/14 21:01:50 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

void	sphere_normal_test(t_sphere *s, t_point p, t_vector expected)
{
	static int	n = 1;
	t_vector	result;

	printf(GREY "sphere_normal_test %d: " END, n);
	result = sphere_normal_at(s, p);
	if (check_equal_vectors(result, expected))
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	n++;
}

void	normal_tests(void)
{
	t_sphere	*s;

	s = create_sphere(set_color(255, 0, 0));
	sphere_normal_test(s, set_point(1, 0, 0), set_vector(1, 0, 0));
	sphere_normal_test(s, set_point(0, 1, 0), set_vector(0, 1, 0));
	sphere_normal_test(s, set_point(0, 0, 1), set_vector(0, 0, 1));
	sphere_normal_test(s, set_point(sqrt(3) / 3, sqrt(3) / 3, sqrt(3) / 3),
		set_vector(sqrt(3) / 3, sqrt(3) / 3, sqrt(3) / 3));
	set_transform(s, translation_matrix(0, 1, 0));
	sphere_normal_test(s, set_point(0, 1.70711, -0.70711),
		set_vector(0, 0.70711, -0.70711));
	set_transform(s, scaling_matrix(1, 0.5, 1));
	sphere_normal_test(s, set_point(0, sqrt(2) / 2, -sqrt(2) / 2),
		set_vector(0, 0.97014, -0.24254));
	free_sphere(s);
}
