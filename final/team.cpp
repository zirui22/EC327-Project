// Copyright 2022 Jiawei Sun alinajw@bu.edu
// Copyright 2022 Zirui Chen zirui22@bu.edu
// Copyright 2022 Haobin Li lihaobin@bu.edu
// Copyright 2022 Chenyuan Zhao zhaoc23@bu.edu

#include<chrono>
#include<ctime>
#include<iostream>
#include<SFML/Graphics.hpp>
#include<string>
#include"InaGamework.h"
#include <SFML/Audio.hpp>
//#include<SFML/Sprite.hpp>
using std::cin;
using std::cout;
using sf::Transformable;
using std::string;
using std::to_string;

//
int main() {
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Tic Tac Toe");

    // load the music
	sf::Music music;
    if (!music.openFromFile("667.ogg")) {
     return -1; // error
    }
/*
    sf::Image background;
    if (!background.loadFromFile("background.jpg")) {
        return -1;
    }
    
*/
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

    // mute sound
    sf::Text sound;
    sound.setFont(font);
    sound.setString("mute music");
    sound.setFillColor(sf::Color::White);
    sound.setOutlineColor(sf::Color::Red);
    sound.setOutlineThickness(2);
    sound.setCharacterSize(30);

    // play sound
    sf::Text ysound;
    ysound.setFont(font);
    ysound.setString("play music");
    ysound.setFillColor(sf::Color::White);
    ysound.setOutlineColor(sf::Color::Red);
    ysound.setOutlineThickness(2);
    ysound.setCharacterSize(30);

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
    copy3.setString("// Copyright 2022 Haobin Li lihaobin@bu.edu");
    copy4.setString("// Copyright 2022 Chenyuan Zhao zhaoc23@bu.edu");
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

    // easy level
    sf::Text easy;
    easy.setFont(font);
    easy.setString("easy");
    easy.setFillColor(sf::Color::White);
    easy.setOutlineColor(sf::Color::Cyan);
    easy.setOutlineThickness(1);
    easy.setCharacterSize(25);

    // hard level
    sf::Text hard;
    hard.setFont(font);
    hard.setString("hard");
    hard.setFillColor(sf::Color::White);
    hard.setOutlineColor(sf::Color::Cyan);
    hard.setOutlineThickness(1);
    hard.setCharacterSize(25);

    // back to initial page (from start, setting, and rules) 
    sf::Text back;
    back.setFont(font);
    back.setString("Back");
    back.setFillColor(sf::Color::White);
    back.setOutlineColor(sf::Color::Red);
    back.setOutlineThickness(1);
    back.setCharacterSize(20);

    bool startb = false;
    bool quitb = false;
    bool settingb = false;
    bool ruleb = false;
    bool easyb = false;
    bool hardb = false;
	bool multib = false;
    bool backeasy = false;
    bool backhard = false;
    bool backd = false;
    bool backplay = false;
    bool backset = false;
    bool backrule = false;
    bool mute = false;
    int count = 0;
    window.setFramerateLimit(100);
    while (window.isOpen()) {

        // play the music
        if (music.getStatus() != sf::Music::Status::Playing && mute == false) {
            music.play();
            music.play();
            music.play();
            music.play();
            music.play();
            music.play();
            music.play();
            music.play();
            music.play();
        }


        // load the background
        //sf::Sprite background;
        
        // display initilal window
        window.clear();
        title.setPosition(400,150);
        start.setPosition(150,600);
        setting.setPosition(450,600);
        rules.setPosition(750,600);
        quit.setPosition(875,25);
        window.draw(title);
        window.draw(start);
        window.draw(setting);
        window.draw(rules);
        window.draw(quit);
        window.display();

        // click start button and choose mode
        sf::Event starte;
        while (window.pollEvent(starte)) {
           
        if (starte.type == sf::Event::MouseButtonPressed){
            double dx =starte.mouseButton.x;
            double dy =starte.mouseButton.y;

            if (140 <= dx && dx <= 250 && 600 <= dy && dy <= 650) {
                startb = true;
            } else if (865 <= dx && dx <= 975 && 15 <= dy && dy <= 55) {
                quitb = true;
            } else if (440 <= dx && dx <= 550 && 600 <= dy && dy <= 650) {
                settingb = true;
            } else if (740 <= dx && dx <= 850 && 600 <= dy && dy <= 650) {
                ruleb = true;
            }
        }

        // choose mode
            // choose mode
        while (startb) {
            window.clear();    
            single.setPosition(150,450);
            easy.setPosition(170,500);
            hard.setPosition(170,550);
            multi.setPosition(650,450);
            back.setPosition(875,25);
            window.draw(easy);
            window.draw(hard);
            window.draw(single);
            window.draw(multi);
            window.draw(back);
            window.display();
            sf::Event startm;

	        while (window.pollEvent(startm)) {
                
            if (startm.type == sf::Event::MouseButtonPressed){
            double ddx =startm.mouseButton.x;
            double ddy =startm.mouseButton.y;
             if (160 <= ddx && ddx <= 270 && 500 <= ddy && ddy <= 540) {
                easyb = true;
            } else if (160 <= ddx && ddx <= 270 && 550 <= ddy && ddy <= 590) {
                hardb = true;
            } else if (640 <= ddx && ddx <= 850 && 450 <= ddy && ddy <= 500) {
				multib = true;
            } else if (865 <= ddx && ddx <= 975 && 15 <= ddy && ddy <= 55) {
                backplay = true;
            }

            // back to previous page
            if (backplay) {
                startb = false;
                backplay = false;
            }
            
            // single easy
            while (easyb) {
            window.setVisible(false);
            Game g;
            backeasy = g.run(0);
            if (backeasy) {
                easyb = false;
                window.setVisible(true);
            }
            }

            // single hard
            while (hardb) {
            window.setVisible(false);
            Game g;
            backhard = g.run(1);
            bool s = g.mulb();
            if (backhard) {
                hardb = false;
                window.setVisible(true);
            }
            }

            //double
	    	while(multib) { 
            window.setVisible(false);
		 	Game g;
            backd = g.mul();
            if (backd) {
                multib = false;
                window.setVisible(true);
            }
            }
        }       
    }
}
    // choose sound option
        while (settingb) {
            window.clear();
            sound.setPosition(500,500);
            ysound.setPosition(500,500);
            copy1.setPosition(300,600);
            copy2.setPosition(300,650);
            copy3.setPosition(300,700);
            copy4.setPosition(300,750);
            back.setPosition(875,25);
            window.draw(copy1);
            window.draw(copy2);
            window.draw(copy3);
            window.draw(copy4);
            if (count % 2 == 1) {
                window.draw(ysound);
            } else if (count % 2 == 0) {
                window.draw(sound);
            }
            window.draw(back);
            window.display();

            sf::Event settingm;

            while (window.pollEvent(settingm)) { 
            if (settingm.type == sf::Event::MouseButtonPressed){
            double ddx =settingm.mouseButton.x;
            double ddy =settingm.mouseButton.y;
             if (865 <= ddx && ddx <= 975 && 15 <= ddy && ddy <= 55) {
                backset = true;
            } else if (490 <= ddx && ddx <= 600 && 490 <= ddy && ddy <= 600) {
                count++;
                mute = true;
            }
            }
            if (backset) {
                settingb = false;
                backset = false;
            }
            if (count % 2 == 1) {
                music.pause();
            } else if (count % 2 == 0  && count != 0) {
                music.play();
                
            }
            }
        }

        // see rules
        while (ruleb) {
        window.clear();
        rules1.setPosition(1,300);
        rules2.setPosition(1,400);
        rules3.setPosition(1,500);
        rules4.setPosition(1,600);
        back.setPosition(875,25);
        window.draw(rules1);
        window.draw(rules2);
        window.draw(rules3);
        window.draw(rules4);
        window.draw(back);
        window.display();
            
        sf::Event rulesm;

        while (window.pollEvent(rulesm)) { 
            if (rulesm.type == sf::Event::MouseButtonPressed){
                double ddx =rulesm.mouseButton.x;
                double ddy =rulesm.mouseButton.y;
             if (865 <= ddx && ddx <= 975 && 15 <= ddy && ddy <= 55) {
                backrule = true;
            } 
            }
            if (backrule) {
                ruleb = false;
                backrule = false;
            }
            }

        }
        // quit the game from intial page
        while (quitb) {
            music.stop();
            window.close();
        }
}
}
}