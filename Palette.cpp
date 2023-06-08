
/*----------------------------------------
 * Palette.cpp
 *
 * 
 *
 *	Generated with async option
 *
 *----------------------------------------*/

#include <iostream>
#include <cassert>
#include "PixelGraphics.h"
#include "Palette.h"

//-------------------------------------------------------------------------
// Related Objects
//-------------------------------------------------------------------------

#include "ColorWell.h"


using namespace PixelGraphics;

extern PixelGraphics::SWA* swa;

//-------------------------------------------------------------------------
// Event Handlers
//-------------------------------------------------------------------------



//-------------------------------------------------------------------------
// Procedures/Methods
//-------------------------------------------------------------------------

void Palette::initialise()
{
	this->add_color_well( WHITE );
	this->add_color_well( BLACK );
	this->add_color_well( BLANK );
	this->add_color_well( LIGHTGRAY );
	this->add_color_well( GRAY );
	this->add_color_well( DARKGRAY );
	this->add_color_well( YELLOW );
	this->add_color_well( GOLD );
	this->add_color_well( ORANGE );
	this->add_color_well( PINK );
	this->add_color_well( RED );
	this->add_color_well( MAROON );
	this->add_color_well( GREEN );
	this->add_color_well( LIME );
	this->add_color_well( DARKGREEN );
	this->add_color_well( SKYBLUE );
	this->add_color_well( BLUE );
	this->add_color_well( DARKBLUE );
	this->add_color_well( PURPLE );
	this->add_color_well( VIOLET );
	this->add_color_well( DARKPURPLE );
	this->add_color_well( BEIGE );
	this->add_color_well( BROWN );
	this->add_color_well( DARKBROWN );
	this->add_color_well( MAGENTA );
	this->add_color_well( RAYWHITE );
	this->add_color_well( NDEWHITE );
}

void Palette::add_color_well(Color color)
{
	ColorWell* well{new ColorWell};
	well->set_color( color );
	this->color_wells_link( well );
}



//-------------------------------------------------------------------------
// State Actions
//-------------------------------------------------------------------------



