/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_tests.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:48:22 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/05 20:38:01 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNIT_TESTS_H
# define UNIT_TESTS_H

# include "../minirt.h"

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

void	points_tests();
void	vectors_tests();
void	operations_vectors_test_cases();
void	scalar_product_test_cases();
void	cross_product_test_cases();
void	points_and_vectors_tests();
void	projectile_test();
void	ray_tests(void);

#endif
