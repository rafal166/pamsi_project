
/* 
 * File:   Player.h
 * Author: rafal
 *
 * Created on 12 maja 2020, 20:21
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <string>

using namespace std;

class Player {
public:
	string name;
	unsigned int win_games = 0;
	unsigned int lose_games = 0;
	string shape;

	Player(string new_name, string new_shape) {
		name = new_name;
		shape = new_shape;
	}
};


#endif /* PLAYER_H */

