#include "Menu.hpp"

class Menu {
private:
    int currentButton;
    sf::Texture backgroundMenuFon;
    sf::Texture backgroundFon;

public:
    void currentButtonSet(int a)
    {
        currentButton = a;
    }
    int currentButtonGet()
    {
        return currentButton;
    }
    bool loadTexture()
    {
        if (!backgroundMenuFon.loadFromFile("thirdparty/image/MenuFon.jpg"))
            return false;
        if (!backgroundFon.loadFromFile("thirdparty/image/Fon.jpg"))
            return false;
        return true;
    }
    void drawMainMenu()
    {
        sf::Sprite menuFon(backgroundMenuFon);
        sf::Sprite fon(backgroundFon);
        menuFon.setPosition(0, 0);
        while (window.isOpen()) { // obrabotchik nujen
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            window.clear();
            window.draw(menuFon);
            window.display();
        }
    }
};