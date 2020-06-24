#include "Menu.hpp"
#include "Button.cpp"
class Menu {
private:
    int currentButton;
    int currentMenu;
    sf::Texture backgroundMenuFon;
    sf::Texture backgroundFon;
    sf::Int32 ftime = 0;
    void eventUpDown(sf::Event event)
    {
        if (currentMenu == 0) {
            int i = currentButtonGet();
            if (i < 1)
                i = 6;
            if (i > 6)
                i = 1;
            if (event.type == sf::Event::KeyPressed)
                if (event.key.code == sf::Keyboard::Up) {
                    i--;
                    timer(200);
                }
            if (event.type == sf::Event::KeyPressed)
                if (event.key.code == sf::Keyboard::Down) {
                    i++;
                    timer(200);
                }
            currentButtonSet(i);
        }
    }
    void timer(sf::Int32 x)
    {
        sf::Clock clock;
        while (ftime < x)
            ftime = clock.getElapsedTime().asMilliseconds();
        ftime = 0;
    }
    bool loadTexture()
    {
        if (!backgroundMenuFon.loadFromFile("thirdparty/image/MenuFon.jpg"))
            return false;
        if (!backgroundFon.loadFromFile("thirdparty/image/Fon.jpg"))
            return false;
        return true;
    }

public:
    Menu(int a = 1)
    {
        currentButton = a;
        currentMenu = 0;
        loadTexture();
    }
    void currentButtonSet(int a)
    {
        currentButton = a;
    }
    int currentButtonGet()
    {
        return currentButton;
    }
    void currentMenuSet(int a)
    {
        currentMenu = a;
    }
    int currentMenuGet()
    {
        return currentMenu;
    }
    void allDraw()
    {
        while (window.isOpen()) {
            if (currentMenu == 0)
                drawMainMenu();
            if (currentMenu == 5)
                drawDevMenu();
            if (currentMenu == 4)
                drawSETMenu();
            if (currentMenu == 3)
                drawLETMenu();
            if (currentMenu == 2)
                drawSEMenu();
            if (currentMenu == 1)
                drawLEMenu();
        }
    }
    void drawMainMenu()
    {
        sf::Sprite fon(backgroundFon);
        sf::Sprite menuFon(backgroundMenuFon);
        menuFon.setPosition(0, 0);
        Button button1(1, 487, 127, "Letter exercise");
        Button button2(2, 487, 196, "Sentence exercise");
        Button button3(3, 487, 266, "Letter exercise(time)");
        Button button4(4, 487, 337, "Sentence exercise(time)");
        Button button5(5, 487, 409, "Developers");
        Button button6(6, 487, 481, "Exit");
        sf::Event event;
        eventUpDown(event);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
            if (currentButton == 6) {
                window.close();
            }
            if (currentButton == 5) {
                currentMenuSet(currentButtonGet());
                return;
            }
            if (currentButton == 4) {
                currentMenuSet(currentButtonGet());
                return;
            }
            if (currentButton == 3) {
                currentMenuSet(currentButtonGet());
                return;
            }
            if (currentButton == 2) {
                currentMenuSet(currentButtonGet());
                return;
            }
            if (currentButton == 1) {
                currentMenuSet(currentButtonGet());
                return;
            }
        }
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(menuFon);
        window.draw(button1.recGet(currentButtonGet()));
        window.draw(button1.nameGet());
        window.draw(button2.recGet(currentButtonGet()));
        window.draw(button2.nameGet());
        window.draw(button3.recGet(currentButtonGet()));
        window.draw(button3.nameGet());
        window.draw(button4.recGet(currentButtonGet()));
        window.draw(button4.nameGet());
        window.draw(button5.recGet(currentButtonGet()));
        window.draw(button5.nameGet());
        window.draw(button6.recGet(currentButtonGet()));
        window.draw(button6.nameGet());
        window.display();
    }
    void drawDevMenu()
    {
        sf::Sprite fon(backgroundFon);
        fon.setPosition(0, 0);
        sf::Event event;
        eventUpDown(event);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            currentMenuSet(0);
        }
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(fon);
        window.display();
    }
    void drawSETMenu()
    {
        sf::Sprite fon(backgroundFon);
        fon.setPosition(0, 0);
        sf::Event event;
        eventUpDown(event);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            currentMenuSet(0);
        }
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(fon);
        window.display();
    }
    void drawLETMenu()
    {
        sf::Sprite fon(backgroundFon);
        fon.setPosition(0, 0);
        sf::Event event;
        eventUpDown(event);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            currentMenuSet(0);
        }
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(fon);
        window.display();
    }
    void drawSEMenu()
    {
        sf::Sprite fon(backgroundFon);
        fon.setPosition(0, 0);
        sf::Event event;
        eventUpDown(event);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            currentMenuSet(0);
        }
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(fon);
        window.display();
    }
    void drawLEMenu()
    {
        sf::Sprite fon(backgroundFon);
        fon.setPosition(0, 0);
        sf::Event event;
        eventUpDown(event);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            currentMenuSet(0);
        }
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(fon);
        window.display();
    }
};
