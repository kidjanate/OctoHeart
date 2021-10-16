#include "Object.h"
#include "GameWindow.h"

void CreateObject(RenderWindow& win, string shape, int x, int y, int scaleX, int scaleY, int rotate) {
	if (shape == "cube") {
		RectangleShape obj(Vector2f(scaleX, scaleY));
		obj.setPosition(Vector2f(x, y));
		obj.rotate(rotate);
		win.draw(obj);
	}
	if (shape == "circle") {
		CircleShape obj(50);
		obj.setPosition(Vector2f(x, y));
		obj.setScale(Vector2f(scaleX, scaleY));
		obj.rotate(rotate);
		win.draw(obj);
	}
}
