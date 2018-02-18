#include "windmill.hpp"

#include <GL/gl.h>
#include <GL/glut.h>
#include <cmath>

// PRIVATE STUFFS

const double PI = 3.141592654;

float get_rad(float mod, float mult, int rotation);

// END OF PRIVATE STUFFS

Windmill::Windmill(float x, float y, float radius, float spade_width, float height,
    int rotation_acceleration)
{
    this->x = x;
    this->y = y;

    this->radius = radius;
    this->spade_width = spade_width;
    this->height = height;

    this->rotation_acceleration = rotation_acceleration;
}

void Windmill::update()
{
    this->rotation += this->rotation_speed;
}

void Windmill::draw()
{
    //float adjust_radius = 0.2f;
    //float adjust_spade = 25;
    //float height = 1.0;

    glColor3f(1.0f, 1.0f, 1.0f);
    
    glBegin(GL_TRIANGLES);
    
    glVertex2f(this->x, this->y);
    glVertex2f(this->x+0.005f, this->y + this->height);
    glVertex2f(this->x-0.005f, this->y + this->height);
    
    glEnd();
    
    for (int i = 0; i < 4; i++) {
        glColor3f(this->spade_colors[i][0],this->spade_colors[i][1],
            this->spade_colors[i][2]);

        glBegin(GL_TRIANGLES);
        
        glVertex2f(this->x, this->y+this->height);
        glVertex2f((sin(get_rad(0,i,this->rotation))*this->radius) + this->x,
            (cos(get_rad(0,i,this->rotation))*this->radius) + this->y+this->height);
        glVertex2f((sin(get_rad(this->spade_width,i,this->rotation))*this->radius) +
            this->x,(cos(get_rad(this->spade_width,i,this->rotation))*this->radius)
            +this->y+this->height);
        
        glEnd();
    }
}

void Windmill::change_spade_colors(float colors[][3])
{
    for(int i = 0; i < 4; ++i) {
        for(int j =0; j < 3; ++j){
            this->spade_colors[i][j] = colors[i][j];
        }
    }
}

void Windmill::rotate_left()
{
    this->rotation_speed += this->rotation_acceleration;
}
    
void Windmill::rotate_right()
{
    this->rotation_speed -= this->rotation_acceleration;
}

// IMPLEMENTATION OF PRIVATE STUFFS

float get_rad(float mod, float mult, int rotation) {
    return (mod + rotation + 90 * mult) * PI/180;
}