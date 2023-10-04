#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct time {
    int hour;
    int min;
    int sec;
};

// Read time details
struct time read(struct time t) {
    printf("Enter time in 24hrs format (HH:MM:SS):\n");
    scanf("%d", &t.hour);
    scanf("%d", &t.min);
    if (t.min > 59) {
        printf("Wrong Entry! Please Try Again:\n");
        scanf("%d", &t.min);
    }
    scanf("%d", &t.sec);
    if (t.sec > 59) {
        printf("Wrong Entry! Please Try Again:\n");
        scanf("%d", &t.sec);
    }
    return t;
}

// Display time details
void display(struct time t) {
    printf("%02d:%02d:%02d\n", t.hour, t.min, t.sec);
    printf("\n");
}

struct time add(struct time t1, struct time t2) {
    struct time sum;
    sum.sec = (t1.sec + t2.sec) % 60;
    int extrasec = (t1.sec + t2.sec) / 60;
    sum.min = (t1.min + t2.min + extrasec) % 60;
    int extramin = (t1.min + t2.min + extrasec) / 60;
    sum.hour = t1.hour + t2.hour + extramin;

    return sum;
}

struct time sub(struct time t1, struct time t2) {
    struct time diff;
    diff.sec = t1.sec - t2.sec;
    if (diff.sec < 0) {
        diff.sec += 60;
        t1.min--;
    }
    diff.min = t1.min - t2.min;
    if (diff.min < 0) {
        diff.min += 60;
        t1.hour--;
    }
    diff.hour = t1.hour - t2.hour;

    return diff;
}


int main() {
    struct time t1 = read(t1);
    struct time t2 = read(t2);
    struct time sum = add(t1, t2);
    struct time diff = sub(t1, t2);
    printf("Time 1:\n");
    display(t1);
    printf("Time 2:\n");
    display(t2);
    printf("Sum is:\n");
    display(sum);
    printf("Difference is:\n");
    display(diff);
}