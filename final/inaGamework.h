#include <unistd.h>
#include <chrono>
#include <SFML/Window.hpp>
#include <unistd.h>
#include <chrono>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "tttanalyzer.h"
class Tile{
private:
    float x,y;
    sf::Text t;
public:
    Tile();
    string getText(){return t.getString();}
    void setText(string s){t.setString(s);}
    void setXY(float xtmp,float ytmp){
        x=xtmp;y=ytmp;
        t.setPosition(x,y);
        t.setFillColor(sf::Color::Yellow);
        }
    float getX(){return x;}
    float getY(){return y;}
    sf::Text getT(){return t;}
};
Tile::Tile(){
    sf::Font font;
    font.loadFromFile("/usr/share/fonts/truetype/ubuntu/Ubuntu-BI.ttf");
    t.setFont(font);
    t.setString("");
}

class Game
{
public:
    Game();
    bool run(int level);
    bool mul();
    void newGame();
    bool quits();
    bool mulb();
private:
    sf::RectangleShape *blokus;
public:
    bool quitsin = false;
    bool quitmul = false;
};

Game::Game(){
    blokus=new sf::RectangleShape[11];
    //第一个矩形为棋盘外框，2-10为棋子外框，11为newGame按钮
    blokus[0].setSize(sf::Vector2f(800.f,800.f));
    blokus[0].setPosition(0,0);
    blokus[0].setOutlineColor(sf::Color::Black);
    blokus[0].setFillColor(sf::Color::Blue);
    for(int i=1;i<10;i++){
        blokus[i].setSize(sf::Vector2f(200.f,200.f));
        float x,y;
        switch (i)
        {
        case 1:
        case 2:
        case 3:
            y=50.f;
            break;
        case 4:
        case 5:
        case 6:
            y=300.f;
            break;
        case 7:
        case 8:
        case 9:
            y=550.f;
            break;
        }
        switch (i)
        {
        case 1:
        case 4:
        case 7:
            x=50.f;
            break;
        case 2:
        case 5:
        case 8:
            x=300.f;
            break;
        case 3:
        case 6:
        case 9:
            x=550.f;
            break;
        }
        blokus[i].setPosition(x,y);
        blokus[i].setOutlineColor(sf::Color::Black);
        blokus[i].setFillColor(sf::Color::White);

    }
    blokus[10].setSize(sf::Vector2f(200.f,100.f));
    blokus[10].setPosition(825,100);
    blokus[10].setOutlineColor(sf::Color::Black);
    blokus[10].setFillColor(sf::Color::Blue);
}

bool attackdefense(int i,int j, int k, sf::Text *tiles) {
    int w = 0;
    int xo = 0;
    string s;
while (w <= 1) {
    xo = 0;
    s = "o";
    if (w == 1) 
        s = "x";
    if( tiles[i].getString() == s) 
        xo++;
    if( tiles[j].getString() == s)
        xo++;
    if (tiles[k].getString() == s)
        xo++;
    if (xo == 2) {
        if( tiles[i].getString() == "") {
            tiles[i].setString("o"); 
            return true;
        }else if( tiles[j].getString() == "") {
            tiles[j].setString("o");
            return true;
        }else if( tiles[k].getString() == "") {
            tiles[k].setString("o"); 
            return true;
        }
    }
    w++;
}

    return false;
}

void AImoves(sf::Text *tiles, int level) {

if (level == 1) {
    if(tiles[4].getString() == "") {
        tiles[4].setString("o");
    }else if (tiles[4].getString() != "") {
        int j = 0, k = 0;

        bool ad = false;
        for (int i = 0; i < 3 ; i++) {
            j = i + 3;
            k = i + 6;
            ad = attackdefense (i, j, k, tiles);
            if (ad) {
                ad = false;
                return;
            }
        }
        for (int i = 0; i < 7 ; i+=3) {
            j = i + 1;
            k = i + 2;
            ad = attackdefense (i, j, k, tiles);
            if (ad) {
                ad = false;
                return;
            }
        }
        int i = 0;
        j = 4;
        k = 8;
        ad = attackdefense (i, j, k, tiles);
        if (ad) {
            ad = false;
            return;
        }
        i = 2;
        j = 4;
        k = 6;
        ad = attackdefense (i, j, k, tiles);
        if (ad) {
            ad = false;
            return;
        } if (tiles[0].getString() == "x" && (tiles[8].getString() == "x" && tiles[4].getString() == "o")) {
            if (tiles[1].getString() == "") {
                tiles[1].setString("o");
                return;
            } else if (tiles[3].getString() == "") {
                tiles[3].setString("o");
                return;
            } else if (tiles[5].getString() == "") {
                tiles[5].setString("o");
                return;
            } else if (tiles[7].getString() == "") {
                tiles[7].setString("o");
                return;
            }
        } else if (tiles[2].getString() == "x" && (tiles[6].getString() == "x" && tiles[4].getString() == "o")) {
            if (tiles[1].getString() == "") {
                tiles[1].setString("o");
                return;
            } else if (tiles[3].getString() == "") {
                tiles[3].setString("o");
                return;
            } else if (tiles[5].getString() == "") {
                tiles[5].setString("o");
                return;
            } else if (tiles[7].getString() == "") {
                tiles[7].setString("o");
                return;
            }
        } else if (tiles[0].getString() == "") {
            tiles[0].setString("o");
            return;
        }else if (tiles[2].getString() == "") {
            tiles[2].setString("o");
            return;
        }else if (tiles[6].getString() == "") {
            tiles[6].setString("o");
            return;
        }else if (tiles[8].getString() == "") {
            tiles[8].setString("o");
            return;
        }
        else {
            if (tiles[1].getString() == "" ) {
                tiles[1].setString("o");
                return;
            }else if (tiles[3].getString() == "" ) {
                tiles[3].setString("o");
                return;
            }else if (tiles[5].getString() == "") {
                tiles[5].setString("o");
                return;
            }else if (tiles[7].getString() == "" ) {
                tiles[7].setString("o");
                return;
            }
        }
        
}
}else if (level == 0) {
    while (true) {
        int r = rand() % (8);
        if(tiles[r].getString() == "") {
            tiles[r].setString("o");
            break; 
        }
    }
}

}



bool Game::run(int level){
    sf::RenderWindow window(sf::VideoMode(1100, 800), "new Game!");
    sf::Event event;
    window.setFramerateLimit(10);
    //九个棋子
    //Tile *tiles=new Tile[9];
    sf::Text *tiles=new sf::Text[9];
    sf::Font font;
    font.loadFromFile("/usr/share/fonts/truetype/ubuntu/Ubuntu-BI.ttf");
    for(int i=0;i<9;i++){
        float x,y;
        switch (i)
        {
        case 0:
        case 1:
        case 2:
            y=75.f;
            break;
        case 4:
        case 5:
        case 3:
            y=325.f;
            break;
        case 7:
        case 8:
        case 6:
            y=575.f;
            break;
        }
        switch (i){
        case 0:
        case 3:
        case 6:
            x=125.f;
            break;
        case 1:
        case 4:
        case 7:
            x=375.f;
            break;
        case 2:
        case 5:
        case 8:
            x=625.f;
            break;
        }
        tiles[i].setPosition(x,y);
        tiles[i].setFont(font);
        tiles[i].setCharacterSize(100);
        //string s="x"+std::to_string(i);
        string s="";
        tiles[i].setString(s);
        tiles[i].setFillColor(sf::Color::Black);
        tiles[i].setOutlineColor(sf::Color::Blue);
        tiles[i].setOutlineThickness(2);
    }
    //文字
    sf::Text resultText,result,renew;
    resultText.setString("Result:");
    resultText.setPosition(815,410);
    resultText.setFillColor(sf::Color::Yellow);
    resultText.setCharacterSize(24);
    resultText.setFont(font);
    result.setPosition(830,470);
    result.setFillColor(sf::Color::Yellow);
    result.setCharacterSize(24);
    result.setFont(font);
    renew.setString("New Game");
    renew.setPosition(825,100);
    renew.setFillColor(sf::Color::Yellow);
    renew.setFont(font);
    renew.setCharacterSize(24);

    // back from single
    sf::Text back1;
    back1.setFont(font);
    back1.setString("Back");
    back1.setFillColor(sf::Color::White);
    back1.setOutlineThickness(1);
    back1.setCharacterSize(24);
    back1.setPosition(825,150);

    int flag=0;
    bool end = false;
    while (window.isOpen())
    {
        if (quitsin) {
            window.close();
            return true;
        }
        while (window.pollEvent(event)){
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    //cout<<"click"<<endl;
                    //获取鼠标点击的坐标
                    float x=event.mouseButton.x;
                    float y=event.mouseButton.y;
                    //cout<<"x"<<x<<"y"<<y<<endl;
                    //点击重新开始时
                    if(x>= 825 && x<=1025 && y>=100 && y<=140){
                        for(int i=0;i<9;i++){
                            tiles[i].setString("");
                        }
                        result.setString("");
                        flag = 0;
                        end = false;
                    }
                    if (x >= 825 && x <= 1025 && y >= 150 && y <= 200) {
                        quitsin = true;
                    }

                    int i=-1;
                    //点击棋子时
                    if(x>=50 && x<=250){
                        //0 3 6
                        if(y>=50 && y<=250){
                            i=0;
                        }else if(y>=300 && y<=500){
                            i=3;
                        }else if(y>=550 && y<= 750){
                            i=6;
                        }
                    }else if(x>=300 && x<=500){
                        //1 4 7
                        if(y>=50 && y<=250){
                            i=1;
                        }else if(y>=300 && y<=500){
                            i=4;
                        }else if(y>=550 && y<= 750){
                            i=7;
                        }
                    }else if(x>=550 && x<= 750){
                        //2 5 8
                        if(y>=50 && y<=250){
                            i=2;
                        }else if(y>=300 && y<=500){
                            i=5;
                        }else if(y>=550 && y<= 750){
                            i=8;
                        }
                    }
                    if(i != -1){
                        string s= (string)tiles[i].getString();
                        if(s == "" && end !=true){
                            s="x";
                            flag++;
                            tiles[i].setString(s);
                            //这里机器人下
                            //将棋子的string赋值为"o"
                            //
            string m = "";
            for(int i=0;i<9;i++){
            //cout<<(string)tiles[i].getString()<<endl;
            if((string)tiles[i].getString() == ""){
                m=m+"#";
            }else{
                m=m+(string)tiles[i].getString();
            }
        }
                            char ch=tttresult(m);
            //cout<<"CH: "<<ch<<endl;
            if (ch != 'c') {
            switch (ch)
            {
            case 'o':
                /* code */
                //lose
                result.setString("LOSE!");
                flag = 0;
                end = true;
                break;
            case 'x':
                /* code */
                //win
                result.setString("WIN!!!");
                flag = 0;
                end = true;
                break;
                case 't':
                /* code */
                result.setString("TIE!");
                flag = 0;
                end = true;
                break;
                case 'i':
                /* code */
                result.setString("ERROR!");
                flag = 0;
                end = true;
                break;
            default:
                break;
            }
        }

                            //
                            if (end) {
                            break;
                            }
                            if (flag < 5) {
                                //int level = 1;
                                if (level == 0) {
                                    
                                    AImoves(tiles, flag%2);
                                }
                                if (level == 1) {
                                    AImoves(tiles, 1);
                                }
                            }
                        }
                    }
                    break;
            }
        }
        window.clear();
        //图形化界面输出
        for(int i=0;i<11;i++){
            window.draw(blokus[i]);
        }
        string s="";
        //标志字符用来判断是否有空地

        for(int i=0;i<9;i++){
            window.draw(tiles[i]);
            //cout<<(string)tiles[i].getString()<<endl;
            if((string)tiles[i].getString() == ""){
                s=s+"#";
            }else{
                s=s+(string)tiles[i].getString();
            }
        }
        //cout<<"Str:"<<s<<endl;
        if(flag >= 3){
            if (flag == 9) {
                //cout<<"filled"<<endl;
                flag = 0;
                end = true;
            }
            //满了判断输赢
            char ch=tttresult(s);
            //cout<<"CH: "<<ch<<endl;
            if (ch != 'c') {
            switch (ch)
            {
            case 'o':
                /* code */
                //lose
                result.setString("LOSE!");
                flag = 0;
                end = true;
                break;
            case 'x':
                /* code */
                //win
                result.setString("WIN!!!");
                flag = 0;
                end = true;
                break;
                case 't':
                /* code */
                result.setString("TIE!");
                flag = 0;
                end = true;
                break;
                case 'i':
                /* code */
                result.setString("ERROR!");
                flag = 0;
                end = true;
                break;
            default:
                break;
            }
        }

        }
        window.draw(renew);
        window.draw(result);
        window.draw(resultText);
        window.draw(back1);
        //window.draw(words);
        window.display();
    }
}

bool Game::mul() {
        sf::RenderWindow window(sf::VideoMode(1100, 800), "new Game!");
    sf::Event event;
    window.setFramerateLimit(10);
    //九个棋子
    //Tile *tiles=new Tile[9];
    sf::Text *tiles=new sf::Text[9];
    sf::Font font;
    font.loadFromFile("/usr/share/fonts/truetype/ubuntu/Ubuntu-BI.ttf");
    for(int i=0;i<9;i++){
        float x,y;
        switch (i)
        {
        case 0:
        case 1:
        case 2:
            y=75.f;
            break;
        case 4:
        case 5:
        case 3:
            y=325.f;
            break;
        case 7:
        case 8:
        case 6:
            y=575.f;
            break;
        }
        switch (i){
        case 0:
        case 3:
        case 6:
            x=125.f;
            break;
        case 1:
        case 4:
        case 7:
            x=375.f;
            break;
        case 2:
        case 5:
        case 8:
            x=625.f;
            break;
        }
        tiles[i].setPosition(x,y);
        tiles[i].setFont(font);
        tiles[i].setCharacterSize(100);
        //string s="x"+std::to_string(i);
        string s="";
        tiles[i].setString(s);
        tiles[i].setFillColor(sf::Color::Black);
        tiles[i].setOutlineColor(sf::Color::Blue);
        tiles[i].setOutlineThickness(2);
    }
    //文字
    sf::Text resultText,result,renew;
    resultText.setString("Result:");
    resultText.setPosition(815,410);
    resultText.setFillColor(sf::Color::Yellow);
    resultText.setCharacterSize(24);
    resultText.setFont(font);
    result.setPosition(830,470);
    result.setFillColor(sf::Color::Yellow);
    result.setCharacterSize(24);
    result.setFont(font);
    renew.setString("New Game");
    renew.setPosition(825,100);
    renew.setFillColor(sf::Color::Yellow);
    renew.setFont(font);
    renew.setCharacterSize(24);

    // back from single
    sf::Text back1;
    back1.setFont(font);
    back1.setString("Back");
    back1.setFillColor(sf::Color::White);
    back1.setOutlineThickness(1);
    back1.setCharacterSize(24);
    back1.setPosition(825,150);


    int count = 0;
    int flag=0;
    bool end = false;
    while (window.isOpen())
    {
        if (quitmul) {
            return true;
        }
        while (window.pollEvent(event)){
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    //cout<<"click"<<endl;
                    //获取鼠标点击的坐标
                    float x=event.mouseButton.x;
                    float y=event.mouseButton.y;
                    //cout<<"x"<<x<<"y"<<y<<endl;
                    //点击重新开始时
                    if(x>= 825 && x<=1025 && y>=100 && y<=140){
                        end = false;
                        count = 0;
                        //cout<< count<< "\n";
                        for(int i=0;i<9;i++){
                            tiles[i].setString("");
                        }
                        result.setString("");
                    }
                    if (x >= 825 && x <= 1025 && y >= 150 && y <= 200) {
                        quitmul = true;
                    }

                    int i=-1;
                    if (end) {
                        break;
                    }
                    //点击棋子时
                    if(x>=50 && x<=250){
                        //0 3 6
                        if(y>=50 && y<=250){
                            i=0;
                        }else if(y>=300 && y<=500){
                            i=3;
                        }else if(y>=550 && y<= 750){
                            i=6;
                        }
                    }else if(x>=300 && x<=500){
                        //1 4 7
                        if(y>=50 && y<=250){
                            i=1;
                        }else if(y>=300 && y<=500){
                            i=4;
                        }else if(y>=550 && y<= 750){
                            i=7;
                        }
                    }else if(x>=550 && x<= 750){
                        //2 5 8
                        if(y>=50 && y<=250){
                            i=2;
                        }else if(y>=300 && y<=500){
                            i=5;
                        }else if(y>=550 && y<= 750){
                            i=8;
                        }
                    }
                    if(i != -1){
                        string s= (string)tiles[i].getString();
                        if(s == "" && count % 2 == 0){
                            s="x";
                            flag++;
                            tiles[i].setString(s);
                            count++;
                        } else if (s == "" && count % 2 == 1) {
                            s="o";
                            flag++;
                            tiles[i].setString(s);s="x";
                            count++;
                        }
                    }
                    break;
            }
        }
        window.clear();
        //图形化界面输出
        for(int i=0;i<11;i++){
            window.draw(blokus[i]);
        }
        string s="";
        //标志字符用来判断是否有空地

        for(int i=0;i<9;i++){
            window.draw(tiles[i]);
            //cout<<(string)tiles[i].getString()<<endl;
            if((string)tiles[i].getString() == ""){
                s=s+"#";
            }else{
                s=s+(string)tiles[i].getString();
            }
        }
        //cout<<"Str:"<<s<<endl;
        if(flag >= 3){
            if (flag == 9) {
                //cout<<"filled"<<endl;
                flag = 0;
                count = 0;
                end = true;
            }
            //满了判断输赢
            char ch=tttresult(s);
            //cout<<"CH: "<<ch<<endl;
            if (ch != 'c') {
            switch (ch)
            {
            case 'o':
                /* code */
                //lose
                result.setString("O Win!!!");
                flag = 0;
                count = 0;
                end = true;
                break;
            case 'x':
                /* code */
                //win
                result.setString("X WIN!!!");
                flag = 0;
                count = 0;
                end = true;
                break;
                case 't':
                /* code */
                result.setString("TIE!");
                flag = 0;
                count = 0;
                end = true;
                break;
                case 'i':
                /* code */
                result.setString("ERROR!");
                flag = 0;
                count = 0;
                end = true;
                break;
            default:
                break;
            }
        }

        }
        window.draw(renew);
        window.draw(result);
        window.draw(resultText);
        window.draw(back1);
        //window.draw(words);
        window.display();
}
}
bool Game::quits() {
    return quitsin;
}
bool Game::mulb() {
    return quitmul;
}


