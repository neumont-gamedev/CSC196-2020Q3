#include "../Engine/pch.h"

const size_t num_points = 10;

nc::Vector2 position{ 400, 300 };
float scale = 2.0f;
std::vector<nc::Vector2> points;

bool Update(float dt)
{
	bool quit = false;
	quit = Core::Input::IsPressed(Core::Input::KEY_ESCAPE);

	if (Core::Input::IsPressed(Core::Input::KEY_LEFT)) position += nc::Vector2{ -1, 0 };
	if (Core::Input::IsPressed(Core::Input::KEY_RIGHT)) position += nc::Vector2{ 1, 0 };

	//for (nc::Vector2& p : points)
	//{
	//	p = nc::Vector2{ nc::random(0.0f, 800.0f), nc::random(0.0f, 600.0f) };
	//}

	for (nc::Vector2& p : points)
	{
		p = nc::Vector2{ nc::random(-10.0f, 10.0f), nc::random(-10.0f, 10.0f) };
	}

	return quit;
}

void Draw(Core::Graphics& graphics)
{
	graphics.SetColor(RGB(255, 255, 255));
	//graphics.SetColor(RGB(nc::random(255), nc::random(255), nc::random(255)));
	
	//graphics.DrawLine(static_cast<float>(rand() % 800), static_cast<float>(rand() % 600), static_cast<float>(rand() % 800), static_cast<float>(rand() % 600));
	//graphics.DrawLines(points.size(), &points[0][0]);

	for (size_t i = 0; i < num_points - 1; i+=2)
	{
		nc::Vector2 p1 = position + (points[i] * scale);
		nc::Vector2 p2 = position + (points[i+1] * scale);

		graphics.DrawLine(p1.x, p1.y, p2.x, p2.y);

		//graphics.DrawLine(points[i].x, points[i].y, points[i + 1].x, points[i + 1].y);
	}
}

int main()
{
	for (size_t i = 0; i < num_points; i++)
	{
		points.push_back({ nc::random(0.0f, 800.0f), nc::random(0.0f, 600.0f) });
	}

	char name[] = "CSC196";
	Core::Init(name, 800, 600);
	Core::RegisterUpdateFn(Update);
	Core::RegisterDrawFn(Draw);

	Core::GameLoop();
	Core::Shutdown();
}
