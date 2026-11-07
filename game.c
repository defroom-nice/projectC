#include "game.h"

#include "input.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void game_run(void) {
    int target;
    int guess;
    int attempts = 0;

    srand((unsigned int)time(NULL));
    target = rand() % 100 + 1;

    printf("猜数字游戏开始！\n");
    printf("我想好了一个 1 到 100 之间的数字。\n");

    for (;;) {
        if (!read_integer("请输入你的猜测：", &guess)) {
            printf("\n输入结束，游戏退出。\n");
            return;
        }

        if (guess < 1 || guess > 100) {
            printf("请输入 1 到 100 之间的数字。\n");
            continue;
        }

        attempts++;
        if (guess > target) {
            printf("太大了！再试一次。\n");
        } else if (guess < target) {
            printf("太小了！再试一次。\n");
        } else {
            printf("恭喜你，猜对了！答案是 %d。\n", target);
            printf("你一共猜了 %d 次。\n", attempts);
            return;
        }
    }
}
