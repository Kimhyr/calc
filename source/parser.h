#ifndef CALC_PARSER_H
#define CALC_PARSER_H

#include "lexer.h"
#include "expression.h"

enum parser_error {
	_PARSER_ERROR = 101,
	PARSER_ERROR_ = 200,
};

struct parser {
	struct token token;
	struct lexer lexer;
	struct expression *root;
	struct expression *head;
};

inline void initiate_parser(struct parser *parser, const char *source) {
	parser->head = parser->root = NULL;
	initiate_lexer(&parser->lexer, source);
}

enum parser_error parse(struct parser *parser, struct expression *out, struct expression *prev);

#endif // CALC_PARSER_H
