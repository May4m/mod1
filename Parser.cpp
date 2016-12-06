/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 08:47:30 by smamba            #+#    #+#             */
/*   Updated: 2016/10/27 08:47:31 by smamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"
#include "main.hpp"

Parser::Parser() {}

Parser::Parser(char *path) : _pathToSource(path) { this->_d = getData(); }

Parser::Parser(Parser const &rSource) { *this = rSource; }

Parser &Parser::operator=(Parser const &rSource)
{
	// to be implemented
    return *this;
}

Parser::~Parser() {}

Point Parser::fileToTab(void)
{
    std::ifstream		source(this->_pathToSource);
    t_data 				*d = getData();
    std::stringstream 	buff;
    Point 				*tmp;
    std::string 		tmp_str;
    int 				pos = 0;
    int 				tmp_nbr;
    std::string 		c_left = "(";
    std::string 		c_right = ")";
    std::string 		c_coma = ",";

    d->XMapMax = 0.0f;
    d->YMapMax = 0.0f;
    d->ZMapMax = 0.0f;
    d->XMapMin = 2147483647.0f;
    d->YMapMin = 2147483647.0f;
    d->ZMapMin = 2147483647.0f;
    if (!source)
		throw Parser::ErrorParse();
    buff << source.rdbuf();
    tmp_str = buff.str();
    source.close();
    while ((pos = tmp_str.find(c_left)) != std::string::npos)
    {
		tmp = new Point;
		tmp_str = &tmp_str[pos + 1];
		tmp->y = static_cast<float>(atoi(tmp_str.c_str())); // first X
		if ((pos = tmp_str.find(c_coma)) == std::string::npos)
			throw Parser::ErrorParse();
		tmp_str = &tmp_str[pos + 1];
		tmp->x = static_cast<float>(atoi(tmp_str.c_str())); // first Y
		if ((pos = tmp_str.find(c_coma)) == std::string::npos)
			throw Parser::ErrorParse();
		tmp_str = &tmp_str[pos + 1];
		tmp->z = static_cast<float>(atoi(tmp_str.c_str())); // first Z
		if (d->XMapMax < tmp->x)			    // Store Max X & min X
			d->XMapMax = tmp->x;
		else if (d->XMapMin > tmp->x)
			d->XMapMin = tmp->x;
		if (d->YMapMax < tmp->y) // Store Max Y & min Y
			d->YMapMax = tmp->y;
		else if (d->YMapMin > tmp->y)
			d->YMapMin = tmp->y;
		if (d->ZMapMax < tmp->z) // Store Max Z & min Z
			d->ZMapMax = tmp->z;
		else if (d->ZMapMin > tmp->z)
			d->ZMapMin = tmp->z;
		this->_d->randomPts.push_back(tmp);
		}
		if (DEBUGG == true)
		{
		this->_d->debug << "Parser::fileToTab end" << std::endl;
    }
}

void Parser::sortByZ_minToMax(void)
{
    t_data *d = getData();
    bool run;
    Point tmp;
    std::list<Point *>::iterator it;
    std::list<Point *>::iterator tmp_list;
    std::list<Point *>::iterator end = d->randomPts.end();

    run = true;
    while (run == true)
    {
	run = false;
	tmp_list = it = d->randomPts.begin();
	tmp_list++;
	while (tmp_list != end)
	{
	    if ((*it)->y > (*tmp_list)->y)
	    {
		tmp.x = (*it)->x;
		tmp.y = (*it)->y;
		tmp.z = (*it)->z;
		(*it)->x = (*tmp_list)->x;
		(*it)->y = (*tmp_list)->y;
		(*it)->z = (*tmp_list)->z;
		(*tmp_list)->x = tmp.x;
		(*tmp_list)->y = tmp.y;
		(*tmp_list)->z = tmp.z;
		run = true;
	    }
	    it++;
	    tmp_list++;
	}
    }
}

void Parser::resizeValue(void)
{
    t_data *d = getData();
    int big = 0;
    std::list<Point *>::iterator it;
    std::list<Point *>::iterator end = d->randomPts.end();

    big = d->XMapMax > d->YMapMax ? d->XMapMax : d->YMapMax;
    big = d->ZMapMax > big ? d->ZMapMax : big;
    while (big > TAB_SIZE - 1)
    {
	big /= SCALE_MAP;
	it = d->randomPts.begin();
	while (it != end)
	{
	    if ((*it)->x / SCALE_MAP >= 0)
		(*it)->x /= SCALE_MAP;
	    else
		(*it)->x = 0;
	    if ((*it)->y / SCALE_MAP >= 0)
		(*it)->y /= SCALE_MAP;
	    else
		(*it)->y = 0;
	    it++;
	}
    }

    big = d->ZMapMax;
    while (big > MAX_HEIGHT - 1)
    {
	big /= SCALE_MAP;
	it = d->randomPts.begin();
	while (it != end)
	{
	    (*it)->z /= SCALE_HILL;
	    it++;
	}
    }
}

void Parser::printMap(void)
{
    if (DEBUGG == true)
    {
	this->_d->debug << "Parser::printMap start" << std::endl;
    }
    if (DEBUGG == true)
    {
	std::list<Point *>::iterator it = (this->_d->randomPts).begin();
	std::list<Point *>::iterator end = (this->_d->randomPts).end();
	while (it != end)
	{
	    this->_d->debug << "Parser::printMap: X-[" << (*it)->x << "] ";
	    this->_d->debug << "Y-[" << (*it)->y << "] ";
	    this->_d->debug << "Z-[" << (*it)->z << "]" << std::endl;
	    it++;
	}
	this->_d->debug << "min X=[" << this->_d->XMapMin << "] ";
	this->_d->debug << "max X=[" << this->_d->XMapMax << "] ";
	this->_d->debug << "min Y=[" << this->_d->YMapMin << "] ";
	this->_d->debug << "max Y=[" << this->_d->YMapMax << "]" << std::endl;
    }
    if (DEBUGG == true)
    {
	this->_d->debug << "Parser::printMap end" << std::endl;
    }
}

const char *Parser::ErrorParse::what() const throw()
{
    return "Exception: Error in file parsing...";
}
