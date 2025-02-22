/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_func2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:42:48 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/01/28 19:14:02 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	add_pipe(t_pipe *p)
{
	all_pipes(add, p);
}

t_pipe	*next_pipe(void)
{
	return (all_pipes(next, 0));
}

t_pipe	*current_pipe(void)
{
	return (all_pipes(current, 0));
}
