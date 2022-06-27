// Copyright 2022 Jiawei Sun alinajw@bu.edu
// Copyright 2022 Zirui Chen zirui22@bu.edu

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
   	start.setOutlineColor(sf::Color::White);
   	start.setOutlineThickness(2);
   	start.setCharacterSize(40);

   	// setting
   	sf::Text setting;
    setting.setFont(font);
   	setting.setString("Setting");
    setting.setFillColor(sf::Color::White);
   	setting.setOutlineColor(sf::Color::White);
   	setting.setOutlineThickness(2);
   	setting.setCharacterSize(40);

   	// rules
   	sf::Text rules;
    rules.setFont(font);
   	rules.setString("Rules");
    rules.setFillColor(sf::Color::White);
   	rules.setOutlineColor(sf::Color::White);
   	rules.setOutlineThickness(2);
   	rules.setCharacterSize(40);

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

   	window.setFramerateLimit(10);
   	while (window.isOpen()) {
   		window.clear();
   		// display initilal window
   		title.setPosition(400,150);
   		start.setPosition(150,600);
   		setting.setPosition(450,600);
   		rules.setPosition(750,600);
   		window.draw(title);
   		window.draw(start);
   		window.draw(setting);
   		window.draw(rules);
   		window.display();

   		// click start button and choose mode
   		sf::Event starte;
   		while (window.pollEvent(starte)) {
           
            if (starte.type == sf::Event::MouseButtonPressed){
              auto location = start.getPosition();

              double dx =starte.mouseButton.x;
              double dy =starte.mouseButton.y;

              if (150 <= dx && dx <= 190 && 600 <= dy && dy <= 640) {
                window.clear();

                single.setPosition(250,500);
                multi.setPosition(750,500);
                window.draw(single);
                window.draw(multi);
                window.display();
              }
            }
        }
   	}
   	return 0;
}

