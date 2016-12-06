/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhandler.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 08:47:19 by smamba            #+#    #+#             */
/*   Updated: 2016/10/27 08:47:20 by smamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
#include "Map.hpp"

void  		keyboard(unsigned char key, int x, int y)
{
	(void)x;
	(void)y;
	t_data *	d = getData();
	while (42)
	{
		if (key == 'q' || key == 27 ) {
			d->map->delData(d);
			if (true == DEBUGG)
				d->debug << "\t!!!! Exit Success !!!! from 'ECHAP' 'Q'" << std::endl;
			d->debug.close();
			std::free( d );
			exit(0);
		}
		else if (key == 32 ) {
			if (DEBUGG)
				d->debug << "\t!!!! Keyboard Pause == " << d->pause << std::endl;
			d->pause = !d->pause;
			glutPostRedisplay();
			return;

		}
		else if ( key == 's' ) {
			if ( true == DEBUGG)
				d->debug << "\t!!!! Keyboard 'S' == START" << std::endl;
			d->pause = false;
			glutPostRedisplay();
			return;
		}
		else {
			d->map->delData( d );
			if (DEBUGG) {
				d->debug << "\t!!!! ELSE Exit Success !!!! from keyboard" << std::endl;
			}
			d->debug.close();
			std::free( d );
			exit(0);
		}
	}
}

void		timer(int extra)
{
	(void)extra;
	glutPostRedisplay();
	glutTimerFunc(0, timer, 0);
}

t_data		*getData( void )
{
	static t_data	*d = NULL;

	if (d == NULL) {
		d = new t_data;
		if (d == NULL)
			return NULL;
		return d;
	}

	return d;
}
