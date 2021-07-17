#pragma once
#include <stdio.h>
#include "wsyLocation2D.h"

struct Node : public Location2D {
	Node* link;

	Node() : link(NULL) {
	}
	Node(Location2D val) : Location2D(val), link(NULL) {
	}
	void print() {
		printf( " (%d, %d)", row, col);
	}
};