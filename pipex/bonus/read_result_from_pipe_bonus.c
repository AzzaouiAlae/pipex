/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_result_from_pipe_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:43:37 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/01/27 16:43:41 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*read_result_from_pipe(void)
{
	t_cs_list	*str;
	t_pipe		*p;
	char		ch;
	int			n;

	p = current_pipe();
	str = cs_list_new(sizeof(char));
	n = 1;
	close(1);
	while (n)
	{
		n = ft_read(p->fd_read, &ch, 1);
		if (n)
			cs_list_add(str, (long)ch);
	}
	return (str->contate);
}
