/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Level.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/18 18:05:12 by amaurer           #+#    #+#             */
/*   Updated: 2015/07/26 20:29:50 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEVEL_HPP
# define LEVEL_HPP

# include <string>
# include <exception>

# define BLOCK_OUT		0
# define BLOCK_NONE		1
# define BLOCK_WALL		2
# define BLOCK_SPAWN	3
# define BLOCK_NOM		4
# define BLOCK_HEAD		10

typedef std::pair<unsigned, unsigned>	t_block;

class Level
{
protected:
	unsigned			_width;
	unsigned			_height;
	t_block				_spawn;

	void				_load(const std::string);

public:
	class BadMapException : std::exception
	{
	public:
		virtual const char *	what() const throw();
	};

	const unsigned &	width;
	const unsigned &	height;
	const t_block &		spawn;
	unsigned **			map;

	Level(unsigned, unsigned);
	Level(const std::string);
	~Level(void);

	void				setWidth(unsigned);
	void				setHeight(unsigned);
	void				setBlock(t_block, unsigned);

	unsigned			getBlock(t_block) const;
};

#endif
