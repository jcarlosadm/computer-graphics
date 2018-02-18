#ifndef WINDMILL_HPP
#define WINDMILL_HPP

class Windmill
{
	float x, y, radius, spade_width, height;

	int rotation = 0;

	int rotation_speed = 0;

	int rotation_acceleration = 1;

	float spade_colors[4][3] =
    {
        {0.0f,1.0f,0.0f},
        {1.0f,0.0f,0.0f},
        {0.0f,0.0f,1.0f},
        {1.0f,1.0f,0.0f}
    };

public:

	Windmill(float x, float y, float radius, float spade_width, float height,
		int rotation_acceleration);

	void change_spade_colors(float colors[][3]);

	void rotate_left();

	void rotate_right();

	void update();

	void draw();
};

#endif // WINDMILL_HPP