/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cs_list_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:44:24 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/01/29 13:16:19 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CS_LIST_BONUS_H
# define CS_LIST_BONUS_H
# include "../garbage_collector_bonus/garbage_collector_bonus.h"
# include <stdarg.h>
# include <unistd.h>

typedef struct s_cs_list
{
	void	*contate;
	int		size_of_type;
	int		count;
	int		capacity;
	int		free_contate;
}			t_cs_list;

void		cs_list_add(t_cs_list *list, long item);
void		cs_list_add_items(t_cs_list *list, int count, ...);
void		select_item_type(t_cs_list *list, void *item);
void		cs_list_add_range(t_cs_list *list, int count, void *arr);
void		cs_list_add_ranges_count_arr(t_cs_list *list, int count, ...);
t_cs_list	*cs_list_new(int size_of_type);
t_cs_list	*cs_list_new_free_contante(int size_of_type, int free_cont);
t_cs_list	*cs_list_new_capacity(int size_of_type, int capacity);
void		cs_list_resize(t_cs_list *list, int capacity);
void		*ft_memcpy(void *dst, const void *src, size_t n);

#endif