// Copyright year Jiawei Sun anlinajw@bu.edu
// Copyright year Zirui Chen zirui22@bu.edu
#include<array>
#include<iostream>
#include<map>
#include<string>
#include<vector>
#include "movedef.h"

using std::cout;
using std::string;
using std::vector;
using std::map;

// A helper method that uses recursion to generate 3^9 boards.
vector<string> allBoards;
void generate(string s, int p) {
  string choice = "#xo";
  if (p == 9) {
    allBoards.push_back(s);
    return;
  } else {
    for (int i = 0; i < 3; i++) {
      s.at(p) = choice.at(i);
      generate(s, p + 1);
    }
  }
}

// A helper method that converts vector<Move> to string
int repeat;
int wrong = 0;
string convert(vector<Move> m) {
  repeat = 0;
  string s = "#########";
  int position;
  for (int i = 0; i < m.size(); i++) {
    if (m.at(i).r == 0) {
      position = m.at(i).c + m.at(i).r;
    } else if (m.at(i).r == 1) {
      position = m.at(i).c + m.at(i).r + 2;
    } else if (m.at(i).r == 2) {
      position = m.at(i).c + m.at(i).r + 4;
    } else {
      wrong++;
    }

    s.at(position) = m.at(i).player;
  }

  for (int i = 0; i < m.size() - 1; i++) {
    if (m.at(i).player == m.at(i + 1).player) {
      repeat++;
    }
  }

  return s;
}

// A helper method that checker whether the player wins.
bool wins(string s, char player) {
  if (s.at(0) == player && s.at(1) == player && s.at(2) == player) {
    return true;
  } else if (s.at(3) == player && s.at(4) == player && s.at(5) == player) {
    return true;
  } else if (s.at(6) == player && s.at(7) == player && s.at(8) == player) {
    return true;
  } else if (s.at(0) == player && s.at(3) == player && s.at(6) == player) {
    return true;
  } else if (s.at(1) == player && s.at(4) == player && s.at(7) == player) {
    return true;
  } else if (s.at(2) == player && s.at(5) == player && s.at(8) == player) {
    return true;
  } else if (s.at(0) == player && s.at(4) == player && s.at(8) == player) {
    return true;
  } else if (s.at(2) == player && s.at(4) == player && s.at(6) == player) {
    return true;
  } else {
    return false;
  }
}

// A helper methods that check whether x wins.
bool xWin(string s) {
  return wins(s, 'x');
}

// A helper method that check whether o wins.
bool oWin(string s) {
  return wins(s, 'o');
}

// Classify the board as one of the following: ‘t’ ‘o’ ‘x’ ‘i’ ‘c’ ‘e’.
char tttresult(string tttboard) {
  int x = 0;
  int o = 0;
  int z = 0;
  int error = 0;
  for (int i = 0; i < tttboard.size(); i++) {
    if (tttboard.at(i) == 'x') {
      x++;
    } else if (tttboard.at(i) == 'o') {
      o++;
    } else if (tttboard.at(i) == '#') {
      z++;
    } else {
      error++;
    }
  }

  if (error != 0 || x + o + z + error != 9) {
    return 'e';
  } else {
    if (x == o + 1) {
      if (xWin(tttboard)) {
        if (!oWin(tttboard)) {
          return 'x';
        } else {
          return 'i';
        }
      } else if (z == 0) {
        if (oWin(tttboard)) {
          return 'i';
        } else {
          return 't';
        }
      } else {
        if (!xWin(tttboard) && !oWin(tttboard)) {
          return 'c';
        } else {
          return 'i';
        }
      }
    } else if (x == o) {
      if (oWin(tttboard)) {
        if (!xWin(tttboard)) {
          return 'o';
        } else {
          return 'i';
        }
      } else {
        if (xWin(tttboard)) {
          return 'i';
        } else {
          return 'c';
        }
      }
    } else {
      return 'i';
    }
  }
}

char tttresult(vector<Move> board) {
  string possible = "#xo";
  for (int i = 0; i < board.size(); i++) {
    if (board.at(i).r < 0) {
      return 'e';
    }
    if (board.at(i).r > 2) {
      return 'e';
    }
    if (board.at(i).c < 0) {
      return 'e';
    }
    if (board.at(i).c > 2) {
      return 'e';
    }
    if (possible.find(board.at(i).player) == string::npos) {
      return 'e';
    }
  }

  string s = convert(board);
  int exist = 0;
  for (int i = 0; i < allBoards.size(); i++) {
    if (s != allBoards.at(i)) {
      exist++;
    }
  }

  if (repeat != 0) {
    return 'i';
  } else {
    if (board.at(0).player != 'x') {
      return 'i';
    } else {
      return tttresult(s);
    }
  }
}

vector<string> get_all_boards() {
  string initial = "#########";
  generate(initial, 0);
  return allBoards;
}

// Prints a table of the five possible outcomes and the frequency of that result
void ttt_tally() {
  vector<string> allBoards = get_all_boards();
  string toxic = "toxic";
  map <char, int> tally {
    {'t', 0},
    {'o', 0},
    {'x', 0},
    {'i', 0},
    {'c', 0},
  };
  
  for (int i = 0; i < allBoards.size(); i++) {
    char result = tttresult(allBoards.at(i));
    tally.at(result) += 1;
  }

  for (int i = 0; i < 5; i++) {
    cout << toxic.at(i) << ' ' << tally.at(toxic.at(i)) << "\n";
  }
}

// MAIN