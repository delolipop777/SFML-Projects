#include <SFML/Graphics.hpp>
#include <vector>

int main() {
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Smooth Jump Animation");
    window.setFramerateLimit(60);

    sf::Texture texture;
    if (!texture.loadFromFile("C:/Users/Bilolbek/Downloads/spritesheet_01.png"))
        return -1;
    texture.setSmooth(true);

    const int frameCount = 4;
    const int frameWidth = texture.getSize().x / frameCount;
    const int frameHeight = texture.getSize().y;

    // Precompute frames
    std::vector<sf::IntRect> frames;
    for (int i = 0; i < frameCount; i++) {
        frames.push_back(sf::IntRect(i * frameWidth, 0, frameWidth, frameHeight));
    }

    sf::Sprite sprite(texture);
    sprite.setPosition(400, 200);

    float frameTime = 0.1f;
    float timer = 0.f;
    int currentFrame = 0;

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float deltaTime = clock.restart().asSeconds();
        timer += deltaTime;

        if (timer >= frameTime) {
            timer -= frameTime;
            currentFrame = (currentFrame + 1) % frameCount; // always forward
            sprite.setTextureRect(frames[currentFrame]);
        }

        window.clear(sf::Color::Black);
        window.draw(sprite);
        window.display();
    }

    return 0;
}
