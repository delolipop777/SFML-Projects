#include <SFML/Graphics.hpp>

using namespace sf;

int main() {
	RenderWindow window(VideoMode(800, 600), "SFML Window");

	RectangleShape rectangle(Vector2f(100, 100));
	CircleShape circle(50);
	rectangle.setFillColor(Color::Green);
	circle.setFillColor(Color::Red);
	rectangle.setPosition(350, 250);
	circle.setPosition(100, 275);
	while (true) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
				return 0;
			}
		}
		window.clear(Color::White);
		window.draw(rectangle);
		window.draw(circle);
		window.display();
	}
}
