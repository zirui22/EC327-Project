#include <unistd.h>
#include <chrono>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
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


bool attackdefense(int i,int j, int k) {
	int w = 0;
	int xo = 0;
	string s;
while (w <= 1) {
	s = "x";
	if (w == 1) 
		s = "o";
	if( tiles[i].getString == s) 
		xo++;
	if( tiles[j].getString == s)
		xo++;
	if (tiles[k].getString == s)
		xo++;
	if (xo == 2) {
		if( tiles[i].getString == "") {
			tiles.setString("o"); 
			return true;
		}else if( tiles[i+3].getString == "") {
			tiles[j].setString("o");
			return true;
		}else if( tiles[i+6].getString == "") {
			tiles[k].setString("o"); 
			return true;
		}
	}
	w++;
}

	return false;
}

/*bool attack(int i,int j, int k) {
	if( tiles[i].getString == "o") 
		oc++;
	if( tiles[j].getString == "o")
		oc++;
	if (tiles[k].getString == "o")
		oc++;
	if (oc == 2) {
		if( tiles[i].getString == "") {
			tiles.setString("o"); 
			return true;
		}else if( tiles[i+3].getString == "") {
			tiles.setString("o");
			return true;
		}else if( tiles[i+6].getString == "") {
			tiles.setString("o"); 
			return true;
		} 
	}
	return false;
}*/



void AImoves(Tile tiles, int level) {

if (level == 1) {
if(tiles[4].getString() == "") {
	tiles[4].setString("o");
}else if (tiles[4].getString() != "") {



for (int i = 0; i < 3 ; i++) {
		j = i + 3;
		k = i + 6;
		bool ad = attackdefense (i, j, k);
		if (ad) 
			return;
}
for (int i = 0; i < 9 ; i+=3) {
		j = i + 1;
		k = i + 2;
		bool ad = attackdefense (i, j, k);
		if (ad) 
			return;
}
i = 0;
j = 4;
k = 8;
bool ad = attackdefense (i, j, k);
	if (ad) 
		return;
i = 2;
j = 4;
k = 6;
bool ad = attackdefense (i, j, k);
	if (ad) 
		return;

if (tiles[0].getString() == "") {
	tiles[0].setString("o");
	return;
}else if (tiles[3].getString() == "") {
	tiles[3].setString("o");
	return;
}else if (tiles[6].getString() == "") {
	tiles[6].setString("o");
	return;
}else if (tiles[8].getString() == "") {
	tiles[8].setString("o");
	return;
}else {
	while (true) {
		int r = rand() % (8);
		if(tiles[r].getString() == "") {
			tiles[r].setString("o");
			break; 
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
