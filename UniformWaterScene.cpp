/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UniformWaterScene.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 08:47:46 by smamba            #+#    #+#             */
/*   Updated: 2016/10/27 08:47:46 by smamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "UniformWaterScene.hpp"

void	UniformWaterScene::go( void ) {
	int y = 0;
	int x;

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
	usleep(100000);
}

void	UniformWaterScene::rUpWater(t_data * d, int z, int y, int x) {
	if ( d->map2d[y][x].type == WATER ) // if already WATER up one more Z
		d->map2d[y][x].z = z;

	if (  z >= d->map2d[y][x].z ) {
		d->map2d[y][x].type = WATER;
		d->map2d[y][x].z = z;
	}

}

void	UniformWaterScene::upWater( int z ) {
	int y = 0;
	int x = 0;
	while ( y < TAB_SIZE ) {
		x = 0;
		while ( x < TAB_SIZE ) {
			rUpWater(this->d, z, y, x);
			x++;
		}
		y++;
	}
}

UniformWaterScene::UniformWaterScene() {
	this->d = getData();
	this->d->toShow = this->d->map2d;
}

UniformWaterScene::UniformWaterScene( UniformWaterScene const & rSource ) {
	*this = rSource;
}

UniformWaterScene & UniformWaterScene::operator=( UniformWaterScene const & rSource ) {
	if ( this != &rSource ) {
		this->d = rSource.d;
	}

	return *this;
}

UniformWaterScene::~UniformWaterScene() {}
