#include "lexer.h"

#include <ctype.h>
#include <stdlib.h>

static void advance_lexer(struct lexer *lexer);

void initiate_lexer(struct lexer *lexer, const char *iter) {
	lexer->iter = iter;
	lexer->position.column = 1;
	lexer->position.row = 1;
}

lexer_error_t lex(struct lexer *lexer, struct token *out) {
	lexer_error_t ret = SUCCESS;
	while (isspace(*lexer->iter))
		advance_lexer(lexer);
	out->span.start = lexer->position;
	switch (*lexer->iter) {
	case PLUS_TOKEN_KIND:
	case END_TOKEN_KIND:
		out->kind = *lexer->iter;
		advance_lexer(lexer);
		break;
	default:
		if (isdigit(*lexer->iter)) {
			uint16_t i = 0;
			char buffer[1024];
			do {
				buffer[i] = *lexer->iter;
				advance_lexer(lexer);
				if (++i >= sizeof(buffer)) {
					ret = BUFFER_OVERFLOW_LEXER_ERROR;
					goto end;
				}
			} while(isdigit(*lexer->iter));
			buffer[i] = 0;
			out->value = (char *)malloc(sizeof(char) * i + 1);
			for (i = 0; buffer[i]; ++i)
				out->value[i] = buffer[i];
			out->value[i] = buffer[i];
			out->kind = NUMBER_TOKEN_KIND;
			break;
		}
		out->kind = UNKNOWN_TOKEN_KIND;
	}
end:
	out->span.end = lexer->position;
	return ret;
}

static void advance_lexer(struct lexer *lexer) {
	if (*(++lexer->iter) == '\n') {
		++lexer->position.row;
		lexer->position.column = 0;
	}
	++lexer->position.column;
}
