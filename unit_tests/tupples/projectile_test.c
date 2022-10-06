/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projectile_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:42:44 by sguilher          #+#    #+#             */
/*   Updated: 2022/10/05 19:21:00 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

t_projectile	*tick(t_environment *env, t_projectile *p)
{
	t_vector	*velocity;
	t_point		*position;

	velocity = add_vectors(p->velocity, env->gravity);
	velocity = add_vectors(*velocity, env->wind);
	position = add_point_and_vector(p->position, *velocity);
	p->velocity = *velocity;
	p->position = *position;
	free(velocity);
	free(position);
	return (p);
}

void projectile_test()
{
	t_environment	env;
	t_projectile	p;
	t_vector		*aux;
	int				i;

	printf(YELLOW "General test: \n" END);
	set_vector(&env.gravity, 0, -0.1, 0);
	set_vector(&env.wind, -0.01, 0, 0);
	set_point(&p.position, 0, 1, 0);
	set_vector(&p.velocity, 1, 1, 0);
	aux = normalize_vector(p.velocity);
	p.velocity = *aux;
	free(aux);
	printf(GREY "Velocity: [%f, %f, %f]\n" END, p.velocity.x, p.velocity.y,
			p.velocity.z);
	printf(GREY "Position: [%f, %f, %f]\n" END, p.position.x, p.position.y,
			p.position.z);
	i = 0;
	while (p.position.y > 0)
	{
		p = *tick(&env, &p);
		i++;
		printf(GREY "Position: [%f, %f, %f] - thick %d\n" END, p.position.x, p.position.y,
			p.position.z, i);
	}
	printf(GREY "Velocity: [%f, %f, %f]\n" END, p.velocity.x, p.velocity.y,
			p.velocity.z);
}
