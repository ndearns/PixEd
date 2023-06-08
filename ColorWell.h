
#pragma once
/*----------------------------------------
 * ColorWell.h
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


class ColorWell {

public:
	//ColorWell()=default;
	~ColorWell()=default;

	// state enum
	
		// none to declare

	// attributes

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


