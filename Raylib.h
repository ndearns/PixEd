#pragma once
#include "raylib.h"
#include <time.h>
#define NDEWHITE (Color) {240,240,240,255}

// Facade to wrap raylib C functions



namespace PixelGraphics {

class Raylib;

class Raylib {
    public:
    void init_window(int width=800, int height=450, const std::string &title="raylib")
        { InitWindow(width, height, title.data());};
    void close_window() 
        { CloseWindow(); };
    bool window_should_close()
        { return WindowShouldClose(); };
    void set_target_fps( int fps )
        { SetTargetFPS( fps ); };
    float get_frame_time()
        { return GetFrameTime(); };
    int get_fps()
        { return GetFPS(); };
    bool is_key_down(int the_key)
        { return IsKeyDown(the_key); };
    bool is_key_pressed(int the_key)
        { return IsKeyPressed(the_key); };
    bool any_key_is_pressed()  
        {   bool result {false};
            if (GetKeyPressed() != 0)  result = true; 
            return result;
        };
    bool mouse_button_is_down(int button)  
        { return IsMouseButtonDown(button); };
    bool mouse_button_pressed(int button)  
        { return IsMouseButtonPressed(button); };
    bool mouse_button_released(int button)  
        { return IsMouseButtonReleased(button); };
    Vector2 get_mouse_position()    
        { return GetMousePosition(); };
    uint16_t get_screen_width()
        { return (uint16_t)GetScreenWidth(); };
    uint16_t get_screen_height()
        { return (uint16_t)GetScreenHeight(); };
    void begin_drawing()
        { return BeginDrawing(); };
    void end_drawing()           
        { EndDrawing(); };
    void clear_background( Color color )      
        { ClearBackground( color );};
    void draw_fps( int x, int y )
        { DrawFPS( x, y ); };
    void draw_text(std::string text, int x, int y, int fontSize, Color color)
        { DrawText(text.c_str(), x, y, fontSize, color);};
    void draw_text(const char* text, int x, int y, int fontSize, Color color)
        { DrawText(text, x, y, fontSize, color);};
    void draw_text(float f, int x, int y, int fontSize, Color color)
        { DrawText(std::to_string(f).data(), x, y, fontSize, color);};
    void draw_circle(int center_x, int center_y, int radius, Color color)  
        {  DrawCircle(center_x, center_y, radius, color);};
    void draw_rectangle(int x, int y, int dx, int dy, Color color)  
        {  DrawRectangle(x, y, dx, dy, color);};
    void draw_rectangle_lines(int x, int y, int dx, int dy, Color color)  
        {  DrawRectangleLines(x, y, dx, dy, color);};
    char* time_HHMM() {

        static char buffer[80];
        time_t raw_time;
        struct tm* time_info;

        time(&raw_time);
        time_info = localtime (&raw_time);

        strftime(buffer, 80, "%H:%M", time_info);
        return buffer;
    };
    char* time_HHMMSS() {

        static char buffer[80];
        time_t raw_time;
        struct tm* time_info;

        time(&raw_time);
        time_info = localtime (&raw_time);

        strftime(buffer, 80, "%H:%M:%S", time_info);
        return buffer;
    };
    Image load_image( std::string filename ) {
        return LoadImage( filename.data() );
    };
    Image gen_image_color( int width, int height, Color color ) {
        return GenImageColor( width, height, color );
    };
    void export_image( Image img ) {
        static char buffer[256];
        time_t raw_time;
        struct tm* time_info;

        time(&raw_time);
        time_info = localtime (&raw_time);

        strftime(buffer, 256, "PixEd_%H%M%S.png", time_info);
        ExportImage( img, buffer );
    };
    void unload_image( Image img ) {
        UnloadImage( img );
    };
    void image_draw_pixel( Image* dst, int posX, int posY, Color color ) {
        ImageDrawPixel( dst, posX, posY, color );
    };
    void draw_image( Image image, int x, int y, Color tint ) {
        Texture t = LoadTextureFromImage( image );
        DrawTexture( t, x, y, tint );
        //DrawTexture( LoadTextureFromImage( image ), x, y, tint );
    };
    Texture load_texture( std::string filename ) {
        return LoadTexture( filename.data() );
    };
    Texture load_texture_from_image( Image image ) {
        return LoadTextureFromImage( image );
    };
    void draw_texture( Texture texture, int x, int y, Color tint ) {
        DrawTexture( texture, x, y, tint );
    };
};
}; // namespace
