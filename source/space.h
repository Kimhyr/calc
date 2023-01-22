#ifndef CALC_SPACE_H
#define CALC_SPACE_H

#include <stdint.h>
#include <stddef.h>

struct position {
	size_t row;
	size_t column;
};

struct span {
	struct position start;
	struct position end;
};

#endif // CALC_SPACE_H
