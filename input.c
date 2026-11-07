#include "input.h"

#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read_integer(const char *prompt, int *value) {
    char line[128];

    for (;;) {
        char *end;
        long parsed;

        fputs(prompt, stdout);
        if (fgets(line, sizeof(line), stdin) == NULL) {
            return 0;
        }

        if (strchr(line, '\n') == NULL && !feof(stdin)) {
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) {
            }
            puts("输入太长，请重新输入。");
            continue;
        }

        errno = 0;
        parsed = strtol(line, &end, 10);
        if (end == line) {
            puts("请输入有效的整数。");
            continue;
        }

        while (isspace((unsigned char)*end)) {
            end++;
        }

        if (*end != '\0' || errno == ERANGE || parsed < INT_MIN ||
            parsed > INT_MAX) {
            puts("请输入有效的整数。");
            continue;
        }

        *value = (int)parsed;
        return 1;
    }
}
