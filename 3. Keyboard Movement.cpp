#include <SFML/Graphics.hpp>

using namespace sf;

int main() {
	RenderWindow window(VideoMode(800, 600), "SFML Window");

	RectangleShape rectangle(Vector2f(100, 100));
	rectangle.setFillColor(Color::Green);
	rectangle.setPosition(350, 250);
	while (true) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
				return 0;
			}
			if (event.type == Event::KeyPressed) {
				switch (event.key.code) {
				case Keyboard::Up:
					rectangle.move(0, -10);
					break;
				case Keyboard::Down:
					rectangle.move(0, 10);
					break;
				case Keyboard::Left:
					rectangle.move(-10, 0);
					break;
				case Keyboard::Right:
					rectangle.move(10, 0);
					break;
				case Keyboard::Escape:
					window.close();
					return 0;
				default:
					break;
				}
			}
		}
		window.clear(Color::White);
		window.draw(rectangle);
		window.display();
	}
}
