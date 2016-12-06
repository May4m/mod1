/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Display.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 08:47:02 by smamba            #+#    #+#             */
/*   Updated: 2016/10/27 08:47:02 by smamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
#include "Map.hpp"
#include "UniformWaterScene.hpp"
#include "WaterBufferScene.hpp"
#include "WaterEvapScene.hpp"
#include "DoubleBufferScene.hpp"
#include "RainingScene.hpp"

void  display( void ) {
	static bool first_preview = false;
	t_data *	d = getData();
	if (false == d->pause) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glScalef(SCALE_GL, SCALE_GL, SCALE_GL);
		if (d->Scenar == 1) {
			d->scene1->upWater(d->upZ);
			d->scene1->go();
		}
		else if (d->Scenar == 3) {
			d->scene3->initWater();
			d->scene3->upWater();
			d->scene3->go();
		}
		else if (d->Scenar == 4) {
			d->scene4->initWater();
			d->scene4->downWater();
			d->scene4->go();
		}
		else if (d->Scenar == 7) {
			d->scene7->InitWater();
			d->scene7->upWater();
			d->scene7->go();
		}
		else if (d->Scenar == 8) {
			d->scene8->initWater();
			d->scene8->upWater();
			d->scene8->go();
		}
		else {
			d->scene1->upWater(d->upZ);
			d->scene1->go();
		}
		if (d->upZ < TAB_SIZE )
			(d->upZ) += 1;
		glFlush();
		glutSwapBuffers();
		glLoadIdentity();
	}
	else
		usleep(50000);
}
