/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumeric.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ***REMOVED*** <***REMOVED***@student.***REMOVED***.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:53:07 by ***REMOVED***             #+#    #+#             */
/*   Updated: 2023/11/27 13:14:07 by ***REMOVED***            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_isnumeric(char *string)
{
	if (*string == '-' || *string == '+')
		string++;
	if (*string == '\0')
		return (false);
	while (ft_isdigit(*string))
		string++;
	if (*string == '\0')
		return (true);
	else
		return (false);
}
