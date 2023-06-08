
/*----------------------------------------
 * Tile.cpp
 *
 * 
 *
 *	Generated with async option
 *
 *----------------------------------------*/

#include <iostream>
#include <cassert>
#include "PixelGraphics.h"
#include "Tile.h"

//-------------------------------------------------------------------------
// Related Objects
//-------------------------------------------------------------------------

#include "Graphic.h"
#include "Pixel.h"


using namespace PixelGraphics;

extern PixelGraphics::SWA* swa;

//-------------------------------------------------------------------------
// Event Handlers
//-------------------------------------------------------------------------



//-------------------------------------------------------------------------
// Procedures/Methods
//-------------------------------------------------------------------------

void Tile::initialise(Graphic* graphic)
{
	this->graphic_link( graphic );
	this->set_span( graphic->tile_span());

	// foreach														
	for( Coord n = 0; 0<= n && n <( span()* span()); n++) {								
		 make_pixel( n );												
	}																

}

void Tile::make_pixel(Coord n)
{
	Pixel* p{new Pixel};
	p->set_x( n % span());
	p->set_y( n / span());
	p->set_color( this->graphic()->background_color());
	this->pixels_link( p );
}



//-------------------------------------------------------------------------
// State Actions
//-------------------------------------------------------------------------



