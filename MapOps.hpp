/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapOps.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 08:46:33 by smamba            #+#    #+#             */
/*   Updated: 2016/10/27 08:46:34 by smamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT42_CLASS_HPP
# define FT42_CLASS_HPP

# include "main.hpp"
/*
This is a base class for all scene
*/
class ft42 {
public:
	ft42();
	~ft42();

	virtual void		delData( t_data * d );
	virtual void		freeAllTab( t_data * d );
	static void			hillColor_toShow( t_data *d, int y, int x );
	virtual void		oceanBorder( void );
	virtual Point 		**allocMap2D( void );
	static void			upperLeft( void * d );
	static void			upperRight( void * d );
	static void			lowerRight( void * d );
	static void			lowerLeft( void * d );
	static void			print_str(char const * word, float y, float x);

private:
	ft42(ft42 const &rSource );
	ft42& operator=(ft42 const &rSource );
};

#endif
