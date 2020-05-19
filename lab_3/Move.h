

/* 
 * File:   Move.h
 * Author: rafal
 *
 * Created on 15 maja 2020, 15:13
 */

#ifndef MOVE_H
#define MOVE_H

class Move {
public:
	int column, row;
	string shape;

	Move(int arg_col, int arg_row, string arg_shape = " ") {
		column = arg_col;
		row = arg_row;
		shape = arg_shape;
	}

	Move(const Move* source) {
		column = source->column;
		row = source->row;
		shape = source->shape;
	}

	Move& operator=(Move other) {
		column = other.column;
		row = other.row;
		shape = other.shape;
		return *this;
	}

};


#endif /* MOVE_H */

