/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projectile_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:42:44 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/06 11:56:06 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

void	tick(t_environment *env, t_projectile *p)
{
	t_vector	velocity;
	t_point		position;

	velocity = add_vectors(p->velocity, env->gravity);
	velocity = add_vectors(velocity, env->wind);
	position = add_point_and_vector(p->position, velocity);
	p->velocity = velocity;
	p->position = position;
}

void	projectile_test(void)
{
	t_environment	env;
	t_projectile	p;
	int				i;

	printf(YELLOW "Projectile test: \n" END);
	env.gravity = set_vector(0, -0.1, 0);
	env.wind = set_vector(-0.01, 0, 0);
	p.position = set_point(0, 1, 0);
	p.velocity = set_vector(1, 1, 0);
	p.velocity = normalize_vector(p.velocity);
	printf(GREY "Velocity: [%f, %f, %f]\n" END, p.velocity.x, p.velocity.y,
		p.velocity.z);
	printf(GREY "Position: [%f, %f, %f]\n" END, p.position.x, p.position.y,
		p.position.z);
	i = 0;
	while (p.position.y > 0)
	{
		tick(&env, &p);
		i++;
		printf(GREY "Position: [%f, %f, %f] - thick %d\n" END, p.position.x,
			p.position.y, p.position.z, i);
	}
	printf(GREY "Velocity: [%f, %f, %f]\n" END, p.velocity.x, p.velocity.y,
		p.velocity.z);
}
