#include "Button.hpp"

class Button {
private:
    int numberButton;
    int x;
    int y;
    sf::Text name;
    sf::RectangleShape rec;

public:
    Button(int a, int X, int Y, std::string str)
    {
        x = X;
        y = Y;
        load();
        name.setFont(font);
        numberButton = a;
        name.setString(str);
        name.setPosition(x + 10, y + 10);
    }
    sf::Text nameGet()
    {
        return name;
    }
    void numberButtonSet(int a)
    {
        numberButton = a;
    }
    int numberButtonGet()
    {
        return numberButton;
    }
    void XSet(int a)
    {
        x = a;
    }
    int XGet()
    {
        return x;
    }
    void YSet(int a)
    {
        y = a;
    }
    int YGet()
    {
        return y;
    }
    void load()
    {
        font.loadFromFile("thirdparty/font/sansation.ttf");
    }
    sf::RectangleShape recGet(int a)
    {
        if (a == numberButton) {
            rec.setOutlineThickness(5);
            rec.setOutlineColor(sf::Color::Red);
        } else {
            rec.setOutlineThickness(0);
        }

        sf::Vector2f point(x, y);
        sf::Vector2f size(460, 57);
        rec.setFillColor(sf::Color::Black);
        rec.setPosition(point);
        rec.setSize(size);
        return rec;
    }
};