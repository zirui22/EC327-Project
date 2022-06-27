// Copyright 2022 Jiawei Sun alinajw@bu.edu
// Copyright 2022 Zirui Chen zirui22@bu.edu
// Copyright 2022 Haobin Li lihaobin@bu.edu
// Copyright 2022 Chenyuan Zhao zhaoc23@bu.edu

#include<chrono>
#include<ctime>
#include<iostream>
#include<SFML/Graphics.hpp>
#include<string>
#include "tttanalyzer.h"
using std::cin;
using std::cout;
using sf::Transformable;
using std::string;
using std::to_string;


int main() {
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Tic Tac Toe");
	
	// initial interface
	// title
	sf::Text title;
    sf::Font font;
    font.loadFromFile("/usr/share/fonts/truetype/ubuntu/Ubuntu-BI.ttf");
    title.setFont(font);
   	title.setString("Tic Tac Toe");
    title.setFillColor(sf::Color::White);
   	title.setOutlineColor(sf::Color::Blue);
   	title.setOutlineThickness(2);
   	title.setCharacterSize(50);

   	// start button
   	sf::Text start;
    start.setFont(font);
   	start.setString("Start");
    start.setFillColor(sf::Color::White);
   	start.setOutlineColor(sf::Color::Yellow);
   	start.setOutlineThickness(2);
   	start.setCharacterSize(40);

   	// setting
   	sf::Text setting;
    setting.setFont(font);
   	setting.setString("Setting");
    setting.setFillColor(sf::Color::White);
   	setting.setOutlineColor(sf::Color::Yellow);
   	setting.setOutlineThickness(2);
   	setting.setCharacterSize(40);

   	// rules
   	sf::Text rules;
    rules.setFont(font);
   	rules.setString("Rules");
    rules.setFillColor(sf::Color::White);
   	rules.setOutlineColor(sf::Color::Yellow);
   	rules.setOutlineThickness(2);
   	rules.setCharacterSize(40);
	
	// rules details
	sf::Text rules1;
    rules1.setFont(font);
   	rules1.setString("1. The game is played on a grid that's 3 squares by 3 squares.");
    rules1.setFillColor(sf::Color::White);
   	rules1.setOutlineColor(sf::Color::Red);
   	rules1.setOutlineThickness(1);
   	rules1.setCharacterSize(20);

   	   	sf::Text rules2;
    rules2.setFont(font);
   	rules2.setString("2. You are X, your friend (or the computer in this case) is O. Players take turns putting their marks in" "\n" "empty squares.");
    rules2.setFillColor(sf::Color::White);
   	rules2.setOutlineColor(sf::Color::Blue);
   	rules2.setOutlineThickness(1);
   	rules2.setCharacterSize(20);

   	   	sf::Text rules3;
    rules3.setFont(font);
   	rules3.setString("3. The first player to get 3 of her marks in a row (up, down, across, or diagonally) is the winner.");
    rules3.setFillColor(sf::Color::White);
   	rules3.setOutlineColor(sf::Color::Red);
   	rules3.setOutlineThickness(1);
   	rules3.setCharacterSize(20);

   	   	sf::Text rules4;
    rules4.setFont(font);
   	rules4.setString("4. When all 9 squares are full, the game is over. If no player has 3 marks in a row, the game ends in a" "\n" "tie.");
    rules4.setFillColor(sf::Color::White);
   	rules4.setOutlineColor(sf::Color::Blue);
   	rules4.setOutlineThickness(1);
   	rules4.setCharacterSize(20);


    // mode
        // single
    sf::Text single;
    single.setFont(font);
    single.setString("Single Player");
    single.setFillColor(sf::Color::White);
    single.setOutlineColor(sf::Color::Magenta);
    single.setOutlineThickness(1);
    single.setCharacterSize(30);
        // double
    sf::Text multi;
    multi.setFont(font);
    multi.setString("Double Player");
    multi.setFillColor(sf::Color::White);
    multi.setOutlineColor(sf::Color::Magenta);
    multi.setOutlineThickness(1);
    multi.setCharacterSize(30);

    // sound
    sf::Text sound;
    sound.setFont(font);
    sound.setString("sound");
    sound.setFillColor(sf::Color::White);
    sound.setOutlineColor(sf::Color::Red);
    sound.setOutlineThickness(2);
    sound.setCharacterSize(30);

    // copyright
    sf::Text copy1;
    sf::Text copy2;
    sf::Text copy3;
    sf::Text copy4;
    copy1.setFont(font);
    copy2.setFont(font);
    copy3.setFont(font);
    copy4.setFont(font);
    copy1.setString("// Copyright 2022 Jiawei Sun alinajw@bu.edu");
    copy2.setString("// Copyright 2022 Zirui Chen zirui22@bu.edu");
    copy3.setString("// Copyright 2023 Haobin Li lihaobin@bu.edu");
    copy4.setString("// Copyright 2023 Chenyuan Zhao zhaoc23@bu.edu");
    copy1.setFillColor(sf::Color::White);
    copy2.setFillColor(sf::Color::White);
    copy3.setFillColor(sf::Color::White);
    copy4.setFillColor(sf::Color::White);
    copy1.setCharacterSize(20);
    copy2.setCharacterSize(20);
    copy3.setCharacterSize(20);
    copy4.setCharacterSize(20);

   	// quit 
    sf::Text quit;
    quit.setFont(font);
    quit.setString("Quit");
    quit.setFillColor(sf::Color::White);
    quit.setOutlineColor(sf::Color::Red);
    quit.setOutlineThickness(1);
    quit.setCharacterSize(20);

    bool startb = false;
    bool quitb = false;
    bool settingb = false;
    bool ruleb = false;
    window.setFramerateLimit(100);
    while (window.isOpen()) {
         // display initilal window
        title.setPosition(400,150);
        start.setPosition(150,600);
        setting.setPosition(450,600);
        rules.setPosition(750,600);
        quit.setPosition(800,50);
        window.draw(title);
        window.draw(start);
        window.draw(setting);
        window.draw(rules);
        window.draw(quit);
        window.display();

        // click start button and choose mode
        //
        sf::Event starte;
        while (window.pollEvent(starte)) {
           
        if (starte.type == sf::Event::MouseButtonPressed){
            double dx =starte.mouseButton.x;
            double dy =starte.mouseButton.y;

            if (140 <= dx && dx <= 250 && 600 <= dy && dy <= 650) {
                startb = true;
            } else if (800 <= dx && dx <= 850 && 50 <= dy && dy <= 90) {
                quitb = true;
            } else if (440 <= dx && dx <= 550 && 600 <= dy && dy <= 650) {
                settingb = true;
            } else if (740 <= dx && dx <= 850 && 600 <= dy && dy <= 650) {
                ruleb = true;
            }
        }

        // choose mode
        while (startb) {
            window.clear();
            single.setPosition(250,500);
            multi.setPosition(750,500);
            window.draw(single);
            window.draw(multi);
            window.display();
        }

        // choose sound option
        while (settingb) {
            window.clear();
            sound.setPosition(500,500);
            copy1.setPosition(300,600);
            copy2.setPosition(300,650);
            copy3.setPosition(300,700);
            copy4.setPosition(300,750);
            window.draw(sound);
            window.draw(copy1);
            window.draw(copy2);
            window.draw(copy3);
            window.draw(copy4);
            window.display();
        }

        // see rules
        while (ruleb) {
            window.clear();
            sound.setPosition(500,500);
            window.draw(sound);
        rules1.setPosition(1,300);
        rules2.setPosition(1,400);
        rules3.setPosition(1,500);
        rules4.setPosition(1,600);
        window.draw(rules1);
        window.draw(rules2);
        window.draw(rules3);
        window.draw(rules4);
        window.display();
            window.display();
        }
        }

    }
    
}
