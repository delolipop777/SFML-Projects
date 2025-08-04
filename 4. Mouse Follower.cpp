#include <SFML/Graphics.hpp>

using namespace sf;

int main() {
	RenderWindow window(VideoMode(800, 600), "SFML Window");

	CircleShape circle(50.f);
	circle.setFillColor(Color::Green);
	circle.setPosition(400, 300);
	Clock clock;

	float speed = 200.f;
	while (window.isOpen()) {
		float dt = clock.restart().asSeconds();
		Event event;
		
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
				return 0;
			}
		}

		Vector2i mousePos = Mouse::getPosition(window);
		Vector2f circlePos = circle.getPosition();
		Vector2f target(mousePos.x - 50, mousePos.y - 50);

		float dx = target.x - circlePos.x;
		float dy = target.y - circlePos.y;
		float distance = std::sqrt(dx * dx + dy * dy);

		if (distance > 0) {
			float moveX = (dx / distance) * speed * dt;
			float moveY = (dy / distance) * speed * dt;
			circle.move(moveX, moveY);
		}

		window.clear(Color::White);
		window.draw(circle);
		window.display();
	}
}
