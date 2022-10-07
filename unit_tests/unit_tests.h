/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_tests.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:48:22 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/07 17:47:45 by sguilher         ###   ########.fr       */
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

void	points_tests(void);
void	vectors_tests(void);
void	operations_vectors_test_cases(void);
void	scalar_product_test_cases(void);
void	cross_product_test_cases(void);
void	points_and_vectors_tests(void);
void	projectile_test(void);

void	multiply_matrix_test(void);
void	multiply_by_vector_test(void);
void	multiply_by_point_test(void);
void	multiply_matrix_by_identity_test(void);

void	ray_tests(void);
void	set_sphere_test(void);
void	sphere_intersection_test(t_sphere *sphere, t_ray ray, int count,
					double t1, double t2);
void	sphere_tests(void);

bool	check_double_values(double a, double b);

#endif
