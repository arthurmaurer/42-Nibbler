//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Graphics.cpp
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-07-23 23:54:14
// :ddddddddddhyyddddddddddd: Modified: 2015-07-26 23:03:35
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#include <iostream>
#include "Graphics.hpp"

extern "C" {
	#include <mlx.h>
}

Graphics::Graphics(const Snake & s) : _snake(s)
{
	_winWidth = 800;
	_winHeight = 600;
	// _window = new sf::RenderWindow(sf::VideoMode(_winWidth, _winHeight), "Da SFML Snake");
	_mlx = mlx_init();
	_window = mlx_new_window(_mlx, _winWidth, _winHeight, (char *)"Da MLX Snake");
}

Graphics::~Graphics(void)
{}

void		Graphics::update(void)
{
	// sf::Event event;

	// while (_window->pollEvent(event))
	// {
	// 	if (event.type == sf::Event::Closed)
	// 		_window->close();
	// 	else if (event.type == sf::Event::KeyPressed)
	// 	{
	// 		if (event.key.code == sf::Keyboard::Escape)
	// 			glib_action = PAUSE;
	// 		if (event.key.code == sf::Keyboard::Up)
	// 			glib_action = UP;
	// 		if (event.key.code == sf::Keyboard::Down)
	// 			glib_action = DOWN;
	// 		if (event.key.code == sf::Keyboard::Left)
	// 			glib_action = LEFT;
	// 		if (event.key.code == sf::Keyboard::Right)
	// 			glib_action = RIGHT;
	// 	}
	// }
	draw();
}

void		Graphics::getLevelInfo()
{
	_width = _snake.level->width;
	_height = _snake.level->height;
	_scaleWidth = _winWidth / _width;
	_scaleHeight = _winHeight / _height;

	if (_scaleWidth < _scaleHeight)
		_drawScale = _scaleWidth / 2;
	else
		_drawScale = _scaleHeight / 2;
}

// void		Graphics::_switch(sf::Vector2<int> index, sf::RenderWindow * _window, sf::Vector2<int> position, sf::Vector2<int> size)
// {
// 	switch (_snake.level->map[index.y][index.x])
// 	{
// 		case BLOCK_NONE:
// 			SDrawer::drawCell(_window, sf::Vector2f(position.x, position.y), sf::Vector2f(size.x, size.y));
// 			break;
// 		case BLOCK_WALL:
// 			SDrawer::drawFull(_window, sf::Vector2f(position.x, position.y), sf::Vector2f(size.x, size.y), sf::Color(200, 200, 200));
// 			break;
// 		case BLOCK_NOM:
// 			SDrawer::drawFull(_window, sf::Vector2f(position.x, position.y), sf::Vector2f(size.x, size.y), sf::Color(242, 43, 0));
// 			break;
// 		case BLOCK_HEAD:
// 			SDrawer::drawFull(_window, sf::Vector2f(position.x, position.y), sf::Vector2f(size.x, size.y), sf::Color(76, 153, 0));
// 			break;
// 		default:
// 			SDrawer::drawFull(_window, sf::Vector2f(position.x, position.y), sf::Vector2f(size.x, size.y), sf::Color(204, 102, 0));
// 	}
// }

void		Graphics::drawCell(int x, int y, int width, int height)
{
	for (int i = 0; i < width; ++i)
	{
		for (int j = 0; j < height; ++j)
		{
			mlx_pixel_put( _mlx, _window, x + i, y + j, 0xFF0000 );
		}
	}
}

void		Graphics::draw(void)
{
	unsigned int	middle = _winWidth / 2;
	getLevelInfo();
	// _window->clear();

	unsigned int x = middle;
	unsigned int y = 0;
	unsigned int i;
	unsigned int j;
	for (i = 0; i < _snake.level->width; i++)
	{
		for(j = 0; j < _snake.level->height; j++)
		{
			drawCell(i * 10, j * 10, 10, 10);
			// mlx_pixel_put ( void *mlx_ptr, void *win_ptr, int x, int y, int color );
			// _switch(sf::Vector2<int>(i, j), _window, sf::Vector2<int>(x, y), sf::Vector2<int>(_drawScale, _drawScale));
			x += 20;
			y += 20;
		}
		x = middle - ((20 * i));
		y = ((20 * i));
	}

	// _window->display();
}

IGraphics *	glib_instantiate(const Snake & s)
{
	return new Graphics(s);
}

void		glib_uninstantiate(IGraphics * g)
{
	delete g;
}
