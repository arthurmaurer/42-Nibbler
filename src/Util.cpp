/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Util.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/19 00:20:46 by amaurer           #+#    #+#             */
/*   Updated: 2015/07/19 00:21:33 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Util.hpp"
#include <sys/time.h>

double	Util::getTime()
{
	static time_t	beginning;
	struct timeval	tod;
	double			ret;

	gettimeofday(&tod, NULL);
	if (beginning == 0)
		beginning = tod.tv_sec;
	ret = (double)(tod.tv_sec - beginning);
	ret += (double)tod.tv_usec / 1000000;
	return (ret);
}