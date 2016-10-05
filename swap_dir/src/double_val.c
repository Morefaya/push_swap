/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_val.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 17:30:37 by jcazako           #+#    #+#             */
/*   Updated: 2016/08/17 17:30:40 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	double_val(int *tab, int i)
{
	int	val;
	int	j;

	j = 0;
	val = tab[i];
	i--;
	while (i >= 0)
	{
		if (tab[i] == val)
			return (1);
		i--;
	}
	return (0);
}
