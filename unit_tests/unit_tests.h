/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_tests.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:48:22 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/13 15:33:27 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNIT_TESTS_H
# define UNIT_TESTS_H

# include "../minirt.h"
# include <stdbool.h>

# define OK 0
# define KO 1

# define YELLOW "\033[0;33m"
# define GREY "\033[38;5;244m"
# define PURPLE "\033[1;35m"
# define BLUE "\033[1;34m"
# define LIGHT_BLUE "\033[0;36m"
# define GREEN "\033[38;5;83m"
# define GREEN2 "\033[38;2;34;183;235m"
# define RED "\033[38;2;222;56;43m"
# define PINK "\033[38;5;212m"
# define END "\033[0m"

typedef struct s_projectile
{
	t_point		position;
	t_vector	velocity;
}	t_projectile;

typedef struct s_environment
{
	t_vector	gravity;
	t_vector	wind;
}	t_environment;

void	ft_atod_tests(void);
void	input_tests(void);
void	validate_input_tests(void);
void	transform_input_tests(void);

void	points_tests(void);
void	vectors_tests(void);
void	operations_vectors_test_cases(void);
void	scalar_product_test_cases(void);
void	cross_product_test_cases(void);
void	points_and_vectors_tests(void);
void	projectile_test(void);

void	matrix_tests(void);
void	equality_tests(void);
void	all_matrix_multiply_tests(void);
void	multiply_by_vector_test(void);
void	multiply_by_point_test(void);
void	multiply_matrix_by_identity_test(void);
void	identity_tests(void);
void	transpose_tests(void);
void	minor_tests(void);
void	determinant_tests(void);
void	determinant_test(t_matrix matrix, double expected);
void	determinant_test_part2(void);
void	submatrix_tests(void);
void	cofactor_tests(void);
void	inverse_matrix_tests(void);
void	inverse_matrix_test(t_matrix m, t_matrix expected);
void	inverse_matrix_test_part2(void);
void	inverse_matrix_ultimate_test(void);
void	translation_tests(void);
void	scaling_tests(void);
void	rotation_tests(void);
void	shearing_tests(void);
void	chaining_tests(void);

void	ray_tests(void);
void	transform_ray_test_cases(void);

void	object_tests(void);

void	sphere_tests(void);
void	transformed_sphere_test(void);

void	intersection_tests(void);

void	normal_tests(void);
void	reflection_tests(void);
void	material_tests(void);
void	light_tests(void);

void	cylinder_tests(void);
void	truncate_cylinder_test_cases(void);

void	world_tests(void);
void	computations_tests(void);
void	shade_hit_tests(void);

void	sphere_render_test(void);
void	cylinder_render_test(void);

// utils
bool	check_equal_points(t_point a, t_point b);
bool	check_equal_vectors(t_vector a, t_vector b);
void	check_int_values(int result, int expected);

// minirt functions
int		check_argc(int argc);

// view transformation
void	transformation_tests(void);


#endif

