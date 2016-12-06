/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 08:45:10 by smamba            #+#    #+#             */
/*   Updated: 2016/10/27 08:45:12 by smamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
# define MAIN_HPP

# define TITLE "MOD1"
# define WINX 1200 			// 1200 default
# define WINY 1200 			// 1200 default
# define STARTX 620 		// 620 default
# define STARTY 100 		// 100 default

# define TAB_SIZE 500 		// 500 dfault
# define MAX_HEIGHT 150 	// 150 default MUST be less 255 for rgb

# define SCALE_MAP 1.1f 	// 1.1f default
# define SCALE_HILL 1.115f 	// 1.115f default
# define SCALE_GL 0.001f 	// 0.001f default
# define CTE1 0.99f 		// 0.99f default
# define CTE2 0.99f 		// 0.99f default

# define SLOPE 1 			// + 1x, - SLOPE Z
# define RADIUS 25			// 25 default radius hill default
# define WATERFLUX_6 40		// 40 default scenar 6
# define WATERFLUX_3 15 	// 15 default scenar 3
# define PURGE_START 50 	// default 100 set water start: hill + water height

# define RAINFLUX 1000		// 1000 default add X rain per frame
# define RAINUP ((TAB_SIZE * TAB_SIZE) / RAINFLUX)

# define EMPTY 'e'
# define WATER 'w'
# define HILL 'h'
# define RAIN 'r'

// Option logs debugs in file 
# define DEBUGG false		//default false

# include <fstream>
# include <iostream>
# include <cstdlib>
# include <list>
# include <stdexcept>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <string>
# include <sstream>
# include <time.h>
# include <unistd.h>
# include <vector>

//OpenGL
# ifdef linux //sudo apt-get install freeglut3 freeglut3-dev
#	include <GL/gl.h>
#	include <GL/glu.h>
#	include <GL/glut.h>
# endif
# ifdef __APPLE__
#	include <openGL/gl.h>
#	include <openGL/glu.h>
#	include <glut/glut.h>
# endif

class 						UniformWaterScene;
class 						WaterBufferScene;
class 						WaterEvapScene;
class 						DoubleBufferScene;
class 						RainingScene;
class 						Parser;
class 						Map;

typedef struct s_pts {
	char					type;
	bool					checked;
	float					x;
	float					y;
	float					z;
	float					upWater;
	int 					HillHeight;
}Point;

typedef struct s_data {
	std::ofstream			debug; 		// file where debugg're print
	std::list<Point *>		randomPts; 	// random pts from file .mod
	Point **				map2d; 		// tab 2D pts im memory
	Point **				originMAp;	// original 2D map without WATER
	Point **				buffer1;
	Point **				buffer2;
	Point **				toShow;
	UniformWaterScene		*scene1;
	WaterBufferScene		*scene3;
	WaterEvapScene			*scene4;
	DoubleBufferScene		*scene7;
	RainingScene			*scene8;
	Parser *				parser;
	Map *					map;
	bool					pause;
	int 					upZ;
	float					XMapMax;
	float					XMapMin;
	float					YMapMax;
	float					YMapMin;
	float					ZMapMax;
	float					ZMapMin;
	int 					z;			// water level
	int 					Water;		// Water level up
	int						NeedUp;		// true if water need up, else false
	int 					Scenar;
}t_data;

t_data *	getData( void );
void  		display( void );
void		keyboard(unsigned char touche, int x, int y);
void		timer(int extra);

#endif
