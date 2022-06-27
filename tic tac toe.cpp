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

   	window.setFramerateLimit(10);
   	while (window.isOpen()) {
   		window.clear();

   		sf::Event event;

   		//
   		title.setPosition(450,300);
   		start.setPosition(150,600);
   		setting.setPosition(450,600);
   		rules.setPosition(600,600);
   		window.draw(title);
   		window.draw(start);
   		window.draw(setting);
   		window.draw(rules);
   		window.display();
   	}
   	return 0;
}
