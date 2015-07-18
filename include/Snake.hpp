/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/15 17:56:26 by amaurer           #+#    #+#             */
/*   Updated: 2015/07/18 21:00:10 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SNAKE_HPP
# define SNAKE_HPP

# include <string>
# include "Level.hpp"
# include "Player.hpp"

typedef enum		e_action
{
	TURN_LEFT,
	TURN_RIGHT,
	PAUSE,
	QUIT
}					t_action;

class Snake
{
protected:

public:
	static Snake *	instance;
	Level *			level;
	Player			player;

	Snake();
	~Snake();

	void			loadLevel(const std::string);
	void			startLevel();
	void			launch();
	void			update();
	void			dump();
};

#endif
