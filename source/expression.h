#ifndef CALC_EXPRESSION_H
#define CALC_EXPRESSION_H

#include "token.h"

typedef uint8_t expression_kind_t;
enum expression_kind {
	END_EXPRESSION_KIND,
	FACTOR_EXPRESSION_KIND,
	BINARY_EXPRESSION_KIND,
};

struct expression {
	expression_kind_t kind;
	union {
		struct binary *binary;
		struct factor *factor;
	} value;
};

struct binary {
	token_kind_t operation;
	struct expression *first;
	struct expression second;
};

struct factor {
	const char *value;
	struct expression next;
};

#endif // CALC_EXPRESSION_H
