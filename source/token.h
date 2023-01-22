#ifndef CALC_TOKEN_H
#define CALC_TOKEN_H

#include <stdint.h>

#include "space.h"

typedef int8_t token_kind_t;
enum token_kind {
	END_TOKEN_KIND = 0,
	UNKNOWN_TOKEN_KIND,
	NUMBER_TOKEN_KIND,
	PLUS_TOKEN_KIND = '+',
};

struct token {
	struct span span;
	token_kind_t kind;
	char *value;
};

#endif // CALC_TOKEN_H
