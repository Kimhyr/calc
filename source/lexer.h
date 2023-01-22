#ifndef CALC_LEXER_H
#define CALC_LEXER_H

#include "token.h"

#define SUCCESS 0

typedef uint8_t lexer_error_t;
enum lexer_error {
	_LEXER_ERROR = 1,
	BUFFER_OVERFLOW_LEXER_ERROR,
	LEXER_ERROR_ = 100,
};

struct lexer {
	const char *iter;
	struct position position;
};

void initiate_lexer(struct lexer *lexer, const char *iter);
lexer_error_t lex(struct lexer *lexer, struct token *out);

#endif // CALC_LEXER_H
