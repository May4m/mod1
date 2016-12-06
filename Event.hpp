/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Event.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 08:46:47 by smamba            #+#    #+#             */
/*   Updated: 2016/10/27 08:46:48 by smamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_CLASS_HPP
# define EVENT_CLASS_HPP

# include "main.hpp"
# include "MapOps.hpp"

class Event : public ft42 {
public:
	t_data *d;

	Event();
	~Event();

	int		initEvent(char **av);
	void	initMap(void);
	void	initRender(int ac, char **av);
	void	renderScene(void);

private:
	Event( Event const & rSource );
	Event & operator=( Event const & rSource );

};

#endif
