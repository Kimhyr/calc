#include <stdio.h>

#include "lexer.h"
#include "parser.h"

#define PRINTC(ENUM) case ENUM: fputs(#ENUM, stdout)
#define PRINTLC(ENUM) case ENUM: puts(#ENUM)
#define PRINTE(ENUM) puts(#ENUM)


int lexer_t() {
	struct lexer lexer;
	initiate_lexer(&lexer, "1 + 234234");
	for (;;) {
		struct token token;
		if (lex(&lexer, &token)) {
			PRINTE(BUFFER_OVERLFOW_LEXER_ERROR);
			return 1;
		}
		switch (token.kind) {
		PRINTLC(END_TOKEN_KIND); goto stop;
		PRINTLC(UNKNOWN_TOKEN_KIND); goto stop;
		PRINTC(NUMBER_TOKEN_KIND); printf(" %s\n", token.value); continue;
		PRINTLC(PLUS_TOKEN_KIND); continue;
		}
	stop: break;
	}
	return 0;
}

int parser_t() {
	struct parser parser;
	initiate_parser(&parser, "21 + 14");
	struct expression expr;
	enum parser_error res = parse(&parser, &expr, NULL);
	if (res != SUCCESS)
		return res;
	return 0;
}

int main() {
	return parser_t();
}

