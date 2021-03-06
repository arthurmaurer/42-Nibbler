/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graphics.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/22 00:21:02 by amaurer           #+#    #+#             */
/*   Updated: 2015/07/29 06:20:45 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_HPP
# define GRAPHICS_HPP

# include "IGraphics.hpp"

class Graphics : public IGraphics
{
public:
	Graphics(const Snake &);
	~Graphics(void);

	void	update(void);
private:
	const Snake &		_snake;
};

extern "C" IGraphics *	glib_instantiate(const Snake &);
extern "C" void			glib_uninstantiate(IGraphics * g);


#endif
