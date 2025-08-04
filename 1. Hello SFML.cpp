#include <SFML/Graphics.hpp>

using namespace sf;

int main() {
	RenderWindow window(VideoMode(800, 600), "SFML Window");

	while (true) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
				return 0;
			}
		}	
}
