
#pragma once
/*----------------------------------------
 * Harness.h
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


class Harness {

public:
	//Harness()=default;
	~Harness()=default;

	// state enum
	
		// none to declare

	// attributes

		Image m_img;
		Image img() { return m_img; };
		void set_img(Image img) { m_img = img; };
		Texture m_tex;
		Texture tex() { return m_tex; };
		void set_tex(Texture tex) { m_tex = tex; };
		Vector2 m_mpos;
		Vector2 mpos() { return m_mpos; };
		void set_mpos(Vector2 mpos) { m_mpos = mpos; };
		Boolean m_mdown;
		Boolean mdown() { return m_mdown; };
		void set_mdown(Boolean mdown) { m_mdown = mdown; };
		Boolean m_mpressed;
		Boolean mpressed() { return m_mpressed; };
		void set_mpressed(Boolean mpressed) { m_mpressed = mpressed; };
		Boolean m_sdown;
		Boolean sdown() { return m_sdown; };
		void set_sdown(Boolean sdown) { m_sdown = sdown; };
		Color m_bcolor;
		Color bcolor() { return m_bcolor; };
		void set_bcolor(Color bcolor) { m_bcolor = bcolor; };
		Coord m_t_res;
		Coord t_res() { return m_t_res; };
		void set_t_res(Coord t_res) { m_t_res = t_res; };
		Coord m_p_span;
		Coord p_span() { return m_p_span; };
		void set_p_span(Coord p_span) { m_p_span = p_span; };
		Coord m_x_tile;
		Coord x_tile() { return m_x_tile; };
		void set_x_tile(Coord x_tile) { m_x_tile = x_tile; };
		Coord m_y_tile;
		Coord y_tile() { return m_y_tile; };
		void set_y_tile(Coord y_tile) { m_y_tile = y_tile; };
		Coord m_x_palette;
		Coord x_palette() { return m_x_palette; };
		void set_x_palette(Coord x_palette) { m_x_palette = x_palette; };
		Coord m_y_palette;
		Coord y_palette() { return m_y_palette; };
		void set_y_palette(Coord y_palette) { m_y_palette = y_palette; };
		Coord m_x_save_tile;
		Coord x_save_tile() { return m_x_save_tile; };
		void set_x_save_tile(Coord x_save_tile) { m_x_save_tile = x_save_tile; };
		Coord m_y_save_tile;
		Coord y_save_tile() { return m_y_save_tile; };
		void set_y_save_tile(Coord y_save_tile) { m_y_save_tile = y_save_tile; };
		Coord m_x_load_tile;
		Coord x_load_tile() { return m_x_load_tile; };
		void set_x_load_tile(Coord x_load_tile) { m_x_load_tile = x_load_tile; };
		Coord m_y_load_tile;
		Coord y_load_tile() { return m_y_load_tile; };
		void set_y_load_tile(Coord y_load_tile) { m_y_load_tile = y_load_tile; };
		Coord m_x_add_tile;
		Coord x_add_tile() { return m_x_add_tile; };
		void set_x_add_tile(Coord x_add_tile) { m_x_add_tile = x_add_tile; };
		Coord m_y_add_tile;
		Coord y_add_tile() { return m_y_add_tile; };
		void set_y_add_tile(Coord y_add_tile) { m_y_add_tile = y_add_tile; };
		Coord m_x_del_tile;
		Coord x_del_tile() { return m_x_del_tile; };
		void set_x_del_tile(Coord x_del_tile) { m_x_del_tile = x_del_tile; };
		Coord m_y_del_tile;
		Coord y_del_tile() { return m_y_del_tile; };
		void set_y_del_tile(Coord y_del_tile) { m_y_del_tile = y_del_tile; };
		Coord m_x_next_tile;
		Coord x_next_tile() { return m_x_next_tile; };
		void set_x_next_tile(Coord x_next_tile) { m_x_next_tile = x_next_tile; };
		Coord m_y_next_tile;
		Coord y_next_tile() { return m_y_next_tile; };
		void set_y_next_tile(Coord y_next_tile) { m_y_next_tile = y_next_tile; };
		Coord m_x_prev_tile;
		Coord x_prev_tile() { return m_x_prev_tile; };
		void set_x_prev_tile(Coord x_prev_tile) { m_x_prev_tile = x_prev_tile; };
		Coord m_y_prev_tile;
		Coord y_prev_tile() { return m_y_prev_tile; };
		void set_y_prev_tile(Coord y_prev_tile) { m_y_prev_tile = y_prev_tile; };
		Coord m_working_tile_index;
		Coord working_tile_index() { return m_working_tile_index; };
		void set_working_tile_index(Coord working_tile_index) { m_working_tile_index = working_tile_index; };

	// relation navigation

		Raylib* m_ui;
		void ui_link(Raylib* toobj){m_ui = toobj;};
		void ui_unlink(Raylib* fromObject=nullptr){m_ui = nullptr;};
		Raylib* ui() { return m_ui;}
		Graphic* m_graphic;
		void graphic_link(Graphic* toobj){m_graphic = toobj;};
		void graphic_unlink(Graphic* fromObject=nullptr){m_graphic = nullptr;};
		Graphic* graphic() { return m_graphic;}
		Tile* m_working_tile;
		void working_tile_link(Tile* toobj){m_working_tile = toobj;};
		void working_tile_unlink(Tile* fromObject=nullptr){m_working_tile = nullptr;};
		Tile* working_tile() { return m_working_tile;}
		Palette* m_palette;
		void palette_link(Palette* toobj){m_palette = toobj;};
		void palette_unlink(Palette* fromObject=nullptr){m_palette = nullptr;};
		Palette* palette() { return m_palette;}
		Pixel* m_uses_pixel;
		void uses_pixel_link(Pixel* toobj){m_uses_pixel = toobj;};
		void uses_pixel_unlink(Pixel* fromObject=nullptr){m_uses_pixel = nullptr;};
		Pixel* uses_pixel() { return m_uses_pixel;}
		ColorWell* m_uses_color_well;
		void uses_color_well_link(ColorWell* toobj){m_uses_color_well = toobj;};
		void uses_color_well_unlink(ColorWell* fromObject=nullptr){m_uses_color_well = nullptr;};
		ColorWell* uses_color_well() { return m_uses_color_well;}

	// Event receiver functions

		// none to declare

	// procedures/methods

		// int main() assumed to be c++ main()
		void initialise();
		void start();
		void do_frame(FrameCount frame_number);
		Boolean mdown_on_tile_at(Coord x, Coord y);
		void select_color_well_under_mouse();
		Boolean mdown_in_grid(Coord x1, Coord y1, Coord dx, Coord dy);
		void paint_pixel_under_mouse();
		void erase_pixel_under_mouse();
		void draw_button_at(Label label, Coord x, Coord y);
		void draw_palette();
		void draw_color_well(Coord n);
		void draw_working_tile();
		void draw_pixel(Pixel* p);
		void draw_mouse_coords();
		void draw_time();
		void save_graphic();
		void load_graphic();

	// state actions

		// none to declare

}; // class

// event class definitions

		// none to declare

}; // namespace


