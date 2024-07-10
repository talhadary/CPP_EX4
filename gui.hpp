#ifndef GUI_HPP
#define GUI_HPP

#include <SFML/Graphics.hpp>
#include "tree.hpp"
#include <sstream>

template <typename T, std::size_t K = 2>
class GUI {
public:
    GUI(Tree<T, K>& t);
    void run();

private:
    void drawNode(sf::RenderWindow& window, sf::Font& font, const Node<T>* node, float x, float y, float xOffset);
    std::string toString(const T& value);

    Tree<T, K>& tree;
    sf::RenderWindow window;
};

template <typename T, std::size_t K>
GUI<T, K>::GUI(Tree<T, K>& t) : tree(t), window(sf::VideoMode(800, 600), "Tree Viewer") {}

template <typename T, std::size_t K>
void GUI<T, K>::run() {
    sf::Font font;
    if (!font.loadFromFile("Ubuntu-Regular.ttf")) {
        return; // Handle error
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        if (tree.get_root() != nullptr) {
            drawNode(window, font, tree.get_root(), 400, 50, 200);
        }
        window.display();
    }
}

template <typename T, std::size_t K>
void GUI<T, K>::drawNode(sf::RenderWindow& window, sf::Font& font, const Node<T>* node, float x, float y, float xOffset) {
    if (!node) return;

    sf::CircleShape circle(30);
    circle.setFillColor(sf::Color::Green);
    circle.setPosition(x - circle.getRadius(), y - circle.getRadius());
    window.draw(circle);

    sf::Text text;
    text.setFont(font);
    text.setString(toString(node->getValue()));
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::Black);
    text.setPosition(x - 20, y - 20);
    window.draw(text);

    float childX = x - xOffset;
    float childY = y + 100;
    for (auto child : node->getChildren()) {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(x, y), sf::Color::Blue),
            sf::Vertex(sf::Vector2f(childX, childY), sf::Color::Blue)
        };
        window.draw(line, 2, sf::Lines);

        drawNode(window, font, child, childX, childY, xOffset / 2);
        childX += xOffset;
    }
}

template <typename T, std::size_t K>
std::string GUI<T, K>::toString(const T& value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

#endif // GUI_HPP
