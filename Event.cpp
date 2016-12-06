/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Event.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 08:46:51 by smamba            #+#    #+#             */
/*   Updated: 2016/10/27 08:46:52 by smamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "Event.hpp"
#include "Map.hpp"
#include "Parser.hpp"
#include "UniformWaterScene.hpp"
#include "WaterBufferScene.hpp"
#include "WaterEvapScene.hpp"
#include "DoubleBufferScene.hpp"
#include "RainingScene.hpp"

using namespace std;


int		Event::initEvent(char ** av) {
	this->d->Scenar = atoi(av[2]);
	if (1 != this->d->Scenar && 3 != this->d->Scenar && 4 != this->d->Scenar
		&& 7 != this->d->Scenar && 8 != this->d->Scenar ) {
		cerr << endl << "This option does not exist" << endl << endl;
		cerr << "\t1 -> Raise water uniformly" << endl;
		cerr << "\t3 -> Buffer Water up from beach" << endl;
		cerr << "\t8 -> Rain simulation" << endl;
		cerr << "\t4 -> Uniform water evaporation" << endl;
		cerr << "\t7 -> Double Water buffer" << endl;
		exit(0);
	}

	this->d->map2d 			= ft42::allocMap2D();
	this->d->originMAp 		= ft42::allocMap2D();
	this->d->buffer1 		= ft42::allocMap2D();
	this->d->buffer2	 	= ft42::allocMap2D();
	this->d->upZ 			= 0;
	this->d->pause			= true;
	this->d->map 			= new Map();
	this->d->scene1 		= new UniformWaterScene();
	this->d->scene3 		= new WaterBufferScene();
	this->d->scene4 		= new WaterEvapScene();
	this->d->scene7 		= new DoubleBufferScene();
	this->d->scene8 		= new RainingScene();
	this->d->parser 		= new Parser(av[1]);
	if ( d->scene1 == NULL || d->parser == NULL || d->map == NULL || d == NULL
		|| d->scene1 == NULL || d->scene3 == NULL || d->scene4 == NULL
		|| d->scene7 == NULL || d->scene8 == NULL) {
		cerr << "Event::initEvent: Allocation Error !" << endl;
		throw exception();
	}

	return 0;
}

void	Event::initMap( void ) {
	d->parser->resizeValue(); 					// Scale map
	d->parser->sortByZ_minToMax();				// Sort by height
	d->map->putRandomTo2dMap();					// put points to map2d array
	d->map->doMapHill();						// generate Hill on map2d
}

void	Event::initRender( int ac, char ** av ) {
	glutInit(&ac, av);							// init glut
	glutInitDisplayMode(GLUT_RGB				// set color to RGB
				| GLUT_DOUBLE					// set double buffered windows
				| GLUT_DEPTH);					// Bit mask to select a window with a depth buffer.
	glutInitWindowSize(WINX, WINY);				// Size of windows
	glutInitWindowPosition(STARTX, STARTY);   	// Position of the window relatively to the screen size
	glutCreateWindow(TITLE);					// Create windows with title in param char *
	glClearColor(0.2f, 0.2f, 0.2f, 1); 			// set background/void color
	glEnable(GL_DEPTH_TEST);
	glPointSize(3.0f);
	glLineWidth(2.0f);
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	this->print_str("S to Start", 0, -0.050f);
	this->print_str("SPACE to simulate", -0.05f, -0.050);
	this->print_str("ESC to exit", -0.1f, -0.050);
	glFlush();
	glutSwapBuffers();
	glLoadIdentity();
}

void	Event::renderScene(void ) {
	glutKeyboardFunc(keyboard);					// function for keyboard event
	glutDisplayFunc(display);
	glutTimerFunc(0, timer, 0);
	glutMainLoop();
}

Event::Event() {
	this->d = getData();
}

Event::Event( Event const & rSource ) {
	*this = rSource;
}

Event & Event::operator=( Event const & rSource ) {
	return *this;
}

Event::~Event() {}
