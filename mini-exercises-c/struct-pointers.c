#include <stdio.h>

typedef struct {
    int x;
    int y;
} Point;

void movePoint(Point *p, int dx, int dy) {
    p -> x = (p -> x) + dx;
    p -> y = (p -> y) + dy;
}

int main() {
    Point pt = {3, 4};
    movePoint(&pt, 1, 1);
    printf("x=%d y=%d\n", pt.x, pt.y);  // should print x=4 y=5
    return 0;
}