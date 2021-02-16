/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_verify_cc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 14:55:52 by aait-ham          #+#    #+#             */
/*   Updated: 2021/02/14 15:54:41 by aait-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#ifdef BONUS

t_bool		check_map_char(char ch)
{
	char *arr;

	arr = "0123456789NWSEs";
	if (ft_strchr(arr, ch) != NULL)
		return (TRUE);
	return (FALSE);
}

t_bool		check_map_chars(char ch)
{
	char *arr;

	arr = "03456789NSEW";
	if (ft_strchr(arr, ch) != NULL)
		return (TRUE);
	return (FALSE);
}

#else

t_bool		check_map_chars(char ch)
{
	char *arr;

	arr = "02NSEW";
	if (ft_strchr(arr, ch) != NULL)
		return (TRUE);
	return (FALSE);
}

t_bool		check_map_char(char ch)
{
	char *arr;

	arr = "012NWSE";
	if (ft_strchr(arr, ch) != NULL)
		return (TRUE);
	return (FALSE);
}

#endif

t_bool		check_borders(t_array_list lines)
{
	return (check_border_e(lines)
			&& check_border_s(lines)
			&& check_border_i(lines, 0));
}
