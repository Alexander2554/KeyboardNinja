#include "Menu.hpp"
#include "Button.cpp"
#include "Exercise.cpp"
class Menu {
private:
    int currentButton;
    int currentMenu;
    sf::Text textInMenu;
    sf::Text nameMenu;
    sf::Texture backgroundMenuFon;
    sf::Texture backgroundFon;
    sf::Int32 ftime = 0;
    sf::Clock clock1;
    void startTimer(sf::Int32 x)
    {
        sf::Clock clock;
        sf::Int32 temp = 0;
        while (temp < x) {
            temp = clock.getElapsedTime().asMilliseconds();
        }
        ftime += temp;
    }
    void ZeroFtime()
    {
        ftime = 0;
    }
    void eventUpDown(sf::Event event)
    {
        int i = currentButtonGet();
        if (i < 1)
            i = 7;
        if (i > 7)
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
    void timer(sf::Int32 x)
    {
        sf::Clock clock;
        while (ftime < x) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                currentMenuSet(0);
                return;
            }
            ftime = clock.getElapsedTime().asMilliseconds();
        }
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

    bool loadFont()
    {
        font.loadFromFile("thirdparty/font/sansation.ttf");
        return true;
    }

public:
    Menu(int a = 1)
    {
        currentButton = a;
        currentMenu = 0;
        loadTexture();
        loadFont();
        textInMenu.setFont(font);
        nameMenu.setFont(font);
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
    void textIMSet(int x, int y, std::string str)
    {
        textInMenu.setPosition(x, y);
        textInMenu.setString(str);
    }
    sf::Text textIMGet()
    {
        return textInMenu;
    }
    void textNMSet(int x, int y, std::string str)
    {
        nameMenu.setPosition(x, y);
        nameMenu.setString(str);
    }
    sf::Text textNMGet()
    {
        return nameMenu;
    }
    void allDraw()
    {
        while (window.isOpen()) {
            if (currentMenu == 0)
                drawMainMenu();
            if (currentMenu == 6)
                drawInsMenu();
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
        textNMSet(450, 10, "MENU");
        Button button1(1, 487, 127, "Letter exercise");
        Button button2(2, 487, 196, "Sentence exercise");
        Button button3(3, 487, 266, "Letter exercise(time)");
        Button button4(4, 487, 337, "Sentence exercise(time)");
        Button button5(5, 487, 409, "Developers");
        Button button6(6, 487, 481, "Instruction");
        Button button7(7, 487, 552, "Exit");
        sf::Event event;
        eventUpDown(event);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
            if (currentButton == 7) {
                window.close();
            }
            if (currentButton == 6) {
                currentMenuSet(currentButtonGet());
                return;
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
        window.draw(button7.recGet(currentButtonGet()));
        window.draw(button7.nameGet());
        window.draw(textNMGet());
        window.display();
    }
    void drawInsMenu()
    {
        sf::Sprite fon(backgroundFon);
        fon.setPosition(0, 0);
        textNMSet(400, 10, "INSTRUCTION");
        textIMSet(
                100,
                100,
                "In the first menu item, you need to click on the button that "
                "\n"
                "the application requires. In the second menu item, you are \n"
                "required to type the CORRECT set of words. In the third, you "
                "\n"
                "need to press the button that is being asked of you in a \n"
                "while. In the fourth for a while you need to print a set of \n"
                "words. The fifth is information about the "
                "developers.\n\n\n\n\n\n\n\n\n\n\nGo "
                "back to the menu when pressed ESC");
        sf::Event event;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            currentMenuSet(0);
        }
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(fon);
        window.draw(textNMGet());
        window.draw(textIMGet());
        window.display();
    }
    void drawDevMenu()
    {
        sf::Sprite fon(backgroundFon);
        fon.setPosition(0, 0);
        textNMSet(400, 10, "DEVELOPERS");
        textIMSet(
                400,
                300,
                "Alexandr Karpik\nRoman "
                "Pospelovski\nDaniil "
                "Prikaschikov");
        sf::Event event;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            currentMenuSet(0);
        }
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(fon);
        window.draw(textNMGet());
        window.draw(textIMGet());
        window.display();
    }
    void drawSETMenu()
    {
        int i = 0;
        answer = true;
        sf::Text Input("", font);

        Input.setPosition(250, 400);
        std::string temp;
        sf::Sprite fon(backgroundFon);
        fon.setPosition(0, 0);
        textNMSet(400, 10, "SENTENCE EXERCISE");
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            currentMenuSet(0);
        }
        Exercise exercise;
        while (window.isOpen()) {
            if (answer) {
                exercise.RandomSentence();
                textIMSet(300, 200, "INPUT " + exercise.sentenceGet());
                answer = false;
            }
            sf::Event event;
            window.clear();
            window.draw(fon);
            window.draw(textNMGet());
            window.draw(textIMGet());
            window.draw(Input);
            window.display();

            while (!answer) {
                if (exercise.CheckAnswer(Input.getString(), ' ')) {
                    answer = true;
                    if (ftime > exercise.countWordGet() * 2500)
                        textIMSet(400, 200, "SLOWLY");
                    else
                        textIMSet(400, 200, "EXCELLENT");
                    exercise.Clear();
                    ZeroFtime();
                    Input.setString("");
                    temp.clear();
                    i = 0;
                    window.clear();
                    window.draw(fon);
                    window.draw(textNMGet());
                    window.draw(textIMGet());
                    window.draw(Input);
                    window.display();

                } else {
                    answer = false;
                }
                while (window.pollEvent(event)) {
                    if (event.type == sf::Event::Closed) {
                        window.close();
                        return;
                    }
                    if (event.type == sf::Event::TextEntered) {
                        if (event.text.unicode == 8)
                            if (i > 0) {
                                i--;
                                temp.erase(temp.begin() + i);
                                Input.setString(temp);
                            }
                        if (event.text.unicode < 123 && event.text.unicode > 31
                            && i < 40) {
                            temp += event.text.unicode;
                            i++;
                            Input.setString(temp);
                        }
                    }
                    if (event.text.unicode == 27) {
                        currentMenuSet(0);
                        return;
                    }
                }
                startTimer(100);
                std::cout << ftime << "\n";
                window.clear();
                window.draw(fon);
                window.draw(textNMGet());
                window.draw(textIMGet());
                window.draw(Input);
                window.display();
                if (answer)
                    timer(1000);
            }
        }
    }
    void drawLETMenu()
    {
        answer = true;
        sf::Sprite fon(backgroundFon);
        fon.setPosition(0, 0);
        textNMSet(400, 10, "LETTER EXERCISE");
        Exercise exercise;
        while (window.isOpen()) {
            if (answer) {
                timerCount(fon);
                exercise.RandomLetter();
                answer = false;
            }
            char tempc[] = {exercise.letterGet()};
            std::string temp(tempc);
            textIMSet(450, 200, "Press " + temp);
            sf::Event event;
            window.clear();
            window.draw(fon);
            window.draw(textNMGet());
            window.draw(textIMGet());
            window.display();
            startTimer(100);
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                    return;
                }
                if (event.type == sf::Event::TextEntered) {
                    if (event.text.unicode < 123 && event.text.unicode > 31) {
                        if (exercise.CheckAnswer(
                                    exercise.sentenceGet(),
                                    static_cast<char>(event.text.unicode))) {
                            answer = true;
                            if (ftime > 1000)
                                textIMSet(400, 200, "SLOWLY");
                            else
                                textIMSet(400, 200, "EXCELLENT");
                            ZeroFtime();
                        } else {
                            answer = false;
                        }
                    }
                    if (event.text.unicode == 27) {
                        currentMenuSet(0);
                        return;
                    }
                }
            }
            window.clear();
            window.draw(fon);
            window.draw(textNMGet());
            window.draw(textIMGet());
            window.display();
            if (answer)
                timer(1000);
        }
    }
    void drawSEMenu()
    {
        int i = 0;
        answer = true;
        sf::Text Input("", font);
        Input.setPosition(250, 400);
        std::string temp;
        sf::Sprite fon(backgroundFon);
        fon.setPosition(0, 0);
        textNMSet(400, 10, "SENTENCE EXERCISE");
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            currentMenuSet(0);
        }
        Exercise exercise;
        while (window.isOpen()) {
            if (answer) {
                exercise.RandomSentence();
                textIMSet(300, 200, "INPUT " + exercise.sentenceGet());
                answer = false;
            }
            sf::Event event;
            window.clear();
            window.draw(fon);
            window.draw(textNMGet());
            window.draw(textIMGet());
            window.draw(Input);
            window.display();
            while (!answer) {
                if (exercise.CheckAnswer(Input.getString(), ' ')) {
                    answer = true;
                    textIMSet(400, 200, "CORRECT");
                    exercise.Clear();
                    Input.setString("");
                    temp.clear();
                    i = 0;
                    window.clear();
                    window.draw(fon);
                    window.draw(textNMGet());
                    window.draw(textIMGet());
                    window.draw(Input);
                    window.display();
                    timer(1000);
                } else {
                    answer = false;
                }
                while (window.pollEvent(event)) {
                    if (event.type == sf::Event::Closed) {
                        window.close();
                        return;
                    }
                    if (event.type == sf::Event::TextEntered) {
                        if (event.text.unicode == 8)
                            if (i > 0) {
                                i--;
                                temp.erase(temp.begin() + i);
                                Input.setString(temp);
                            }
                        if (event.text.unicode < 123 && event.text.unicode > 31
                            && i < 40) {
                            temp += event.text.unicode;
                            i++;
                            Input.setString(temp);
                        }
                    }
                    if (event.text.unicode == 27) {
                        currentMenuSet(0);
                        return;
                    }
                }
                window.clear();
                window.draw(fon);
                window.draw(textNMGet());
                window.draw(textIMGet());
                window.draw(Input);
                window.display();
            }
        }
    }

    void timerCount(sf::Sprite fon)
    {
        int count = 3;
        while (window.isOpen()) {
            sf::Event event;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                currentMenuSet(0);
                return;
            }
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                    return;
                }
            }
            if (count == 0)
                textIMSet(450, 200, "START");
            else
                textIMSet(500, 200, std::to_string(count));
            window.clear();
            window.draw(fon);
            window.draw(textNMGet());
            window.draw(textIMGet());
            window.display();
            if (count < 0)
                return;
            count--;
            timer(1000);
        }
    }
    void drawLEMenu()
    {
        answer = true;
        sf::Sprite fon(backgroundFon);
        fon.setPosition(0, 0);
        textNMSet(400, 10, "LETTER EXERCISE");
        Exercise exercise;
        while (window.isOpen()) {
            if (answer) {
                timerCount(fon);
                exercise.RandomLetter();
                answer = false;
            }
            char tempc[] = {exercise.letterGet()};
            std::string temp(tempc);
            textIMSet(450, 200, "Press " + temp);
            sf::Event event;
            window.clear();
            window.draw(fon);
            window.draw(textNMGet());
            window.draw(textIMGet());
            window.display();
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                    return;
                }
                if (event.type == sf::Event::TextEntered) {
                    if (event.text.unicode < 123 && event.text.unicode > 31) {
                        if (exercise.CheckAnswer(
                                    exercise.sentenceGet(),
                                    static_cast<char>(event.text.unicode))) {
                            answer = true;
                            textIMSet(400, 200, "CORRECT");
                        } else {
                            answer = false;
                            textIMSet(400, 200, "UNCORRECT");
                        }
                    }
                    if (event.text.unicode == 27) {
                        currentMenuSet(0);
                        return;
                    }
                }
            }
            window.clear();
            window.draw(fon);
            window.draw(textNMGet());
            window.draw(textIMGet());
            window.display();
            timer(1000);
        }
    }
};
