#include "parser.h"

#include <stdlib.h>
#include <stdio.h>

static enum parser_error parse_factor(struct parser *parser, struct expression *out);
static enum parser_error parse_binary(struct parser *parser, struct expression *out, struct expression *first);

enum parser_error parse(struct parser *parser, struct expression *out, struct expression *prev) {
	puts("parse");
	enum parser_error ret = (enum parser_error)SUCCESS;
	lex(&parser->lexer, &parser->token);
	switch (parser->token.kind) {
	case NUMBER_TOKEN_KIND: return parse_factor(parser, out);  
	case PLUS_TOKEN_KIND: return parse_binary(parser, out, prev);
	case UNKNOWN_TOKEN_KIND: return (enum parser_error)UNKNOWN_TOKEN_KIND;
	case END_TOKEN_KIND: out->kind = END_EXPRESSION_KIND; break;
	}
	parser->head = out;
	return ret;
}

enum parser_error parse_factor(struct parser *parser, struct expression *out) {
	puts("parse_factor");
	out->value.factor = (struct factor *)malloc(sizeof(struct factor));
	out->value.factor->value = parser->token.value;
	out->kind = FACTOR_EXPRESSION_KIND;
	return parse(parser, &out->value.factor->next, out);
}

enum parser_error parse_binary(struct parser *parser, struct expression *out, struct expression *first) {
	puts("parse_factor");
	out->value.binary = (struct binary *)malloc(sizeof(struct factor));
	out->value.binary->first = first;
	out->value.binary->operation = parser->token.kind;
	out->kind = BINARY_EXPRESSION_KIND;
	if (first->kind == FACTOR_EXPRESSION_KIND) {
		parser->root = out;
	}
	return parse(parser, &out->value.binary->second, out);
}
