/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DoubleBufferScene.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 08:45:57 by smamba            #+#    #+#             */
/*   Updated: 2016/10/27 08:45:58 by smamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DoubleBufferScene.hpp"

DoubleBufferScene::DoubleBufferScene() {
	this->d = getData();
	this->d->toShow = this->d->map2d;
}

DoubleBufferScene::DoubleBufferScene( DoubleBufferScene const & rSource ) {
	*this = rSource;
}

DoubleBufferScene & DoubleBufferScene::operator=( DoubleBufferScene const & rSource ) {
	if ( this != &rSource ) {
		this->d = rSource.d;
	}

	return *this;
}

DoubleBufferScene::~DoubleBufferScene() {}

void	DoubleBufferScene::go( void ) {
	int 	y = 0;
	int 	x;
	float	xResult;
	float	yResult;
	float	color[3];

	glBegin(GL_POINTS);
		while ( y < TAB_SIZE ) {
			x = 0;
			while ( x < TAB_SIZE ) {
				ft42::hillColor_toShow( d, y, x );
				x++;
			}
			y++;
		}
	glEnd();
	ft42::oceanBorder();
}

int 	DoubleBufferScene::Clamp(int x, int min, int max) {
	if (x < min)
		x = min;
	else if (x > max)
		x = max;
	return (x);
}

void	DoubleBufferScene::rUpWater(t_data * d, int z, int y, int x, bool line) {
	int tmp = 0;
	int tmp1 = 0;
	int tmp2 = 0;
	int tmp3 = 0;
	short int dir = 0;

	if (d->map2d[y][x].z - d->z >= -2) {
		d->map2d[y][x].z = d->z;
	}
	else {
		d->NeedUp += 1;
		d->map2d[y][x].z++;
	}
	d->map2d[y][x].type = WATER;
	if (d->map2d[y][x].upWater == 0) {
		if (x + 1 < TAB_SIZE && d->map2d[y][x + 1].z < d->map2d[y][x].z)
			dir = 1;
		else if (x - 1 >= 0 && d->map2d[y][x - 1].z < d->map2d[y][x].z)
			dir = 2;
		else if (y + 1 < TAB_SIZE && d->map2d[y + 1][x].z < d->map2d[y][x].z)// || (y + 2 < TAB_SIZE && d->map2d[y + 2][x].z < d->map2d[y][x].z))
			dir = 3;
		else if (y - 1 >= 0 && d->map2d[y - 1][x].z < d->map2d[y][x].z)// || (y - 2 > 0 && d->map2d[y - 2][x].z < d->map2d[y][x].z))
			dir = 4;
		if ( dir == 1 && x + 1 < TAB_SIZE && d->map2d[y][x + 1].type != WATER && d->map2d[y][x + 1].z < d->map2d[y][x].z ) {
			d->NeedUp += 1;
			d->map2d[y][x + 1].type = WATER;
		}
		if ( dir == 2 && x - 1 >= 0 && d->map2d[y][x - 1].type != WATER && d->map2d[y][x - 1].z < d->map2d[y][x].z) {
			d->NeedUp += 1;
			d->map2d[y][x - 1].type = WATER;
			d->map2d[y][x - 1].upWater = 1;
		}
		if ( dir == 3 && y + 1 < TAB_SIZE && d->map2d[y + 1][x].type != WATER && d->map2d[y + 1][x].z < d->map2d[y][x].z &&(x - 1 < 0 || d->map2d[y + 1][x - 1].type != WATER)) {
			d->NeedUp += 1;
			d->map2d[y + 1][x].type = WATER;
			d->map2d[y + 1][x].upWater = 1;
		}
		if ( dir == 4 && y - 1 >= 0 && d->map2d[y - 1][x].type != WATER && d->map2d[y - 1][x].z < d->map2d[y][x].z && (x - 1 < 0 || d->map2d[y - 1][x - 1].type != WATER)) {
			d->NeedUp += 1;
			d->map2d[y - 1][x].type = WATER;
			d->map2d[y - 1][x].upWater = 1;
		}
	}
	else {
		d->map2d[y][x].upWater = 0;
	}
	if (line == true) {
		x--;
		while (x >= 0 && d->map2d[y][x].type != WATER) {
			x--;
		}
		if (x >= 0)
			rUpWater(d, d->map2d[y][x].z, y, x, true);
	}
}

void	DoubleBufferScene::upWater( void ) {
	int y = 0;
	int x;

	if ( this->d->NeedUp < WATERFLUX_6 ) {
		this->d->z++;
	}
	this->d->NeedUp = 0;
	while ( y < TAB_SIZE ) {
		x = TAB_SIZE;
		while ( x >= 0 && this->d->map2d[y][x].type != WATER ) {
			x--;
		}
		rUpWater(this->d, this->d->map2d[y][x].z, y, x, true);
		y++;
	}
}

void DoubleBufferScene::InitWater( void ) {
	static bool called = false;
	if (called == false)
		called = true;
	else
		return ;
	int y = 0;

	while ( y < TAB_SIZE ) {
		if ( this->d->map2d[y][0].type != HILL ) {
			this->d->map2d[y][0].type = WATER;
			this->d->map2d[y][0].z = 0;
		}
		y++;
	}
	this->d->z = 1;
	this->d->Water = 0;
	this->d->NeedUp = 0;
}
