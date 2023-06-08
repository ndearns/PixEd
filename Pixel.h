
#pragma once
/*----------------------------------------
 * Pixel.h
 *
 * 
 *
 *	Generated with async option
 *
 *----------------------------------------*/

#include <list>
#include <string>
#include "EventQueue.h"
#include "PixelGraphics.h"


namespace PixelGraphics{

	// declare event classes
	
		// none to declare


class Pixel {

public:
	//Pixel()=default;
	~Pixel()=default;

	// state enum
	
		// none to declare

	// attributes

		Coord m_x;
		Coord x() { return m_x; };
		void set_x(Coord x) { m_x = x; };
		Coord m_y;
		Coord y() { return m_y; };
		void set_y(Coord y) { m_y = y; };
		Color m_color;
		Color color() { return m_color; };
		void set_color(Color color) { m_color = color; };

	// relation navigation

		// none to declare

	// Event receiver functions

		// none to declare

	// procedures/methods

		// none to declare

	// state actions

		// none to declare

}; // class

// event class definitions

		// none to declare

}; // namespace


