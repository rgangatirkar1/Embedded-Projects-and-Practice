#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Point;

void createPoint(Point **p, int x, int y) {
    Point *new_point = malloc(sizeof(Point));
    new_point -> x = x;
    new_point -> y = y;
    *p = new_point;
}

int main() {
    Point *pt;
    createPoint(&pt, 7, 8);
    printf("x=%d y=%d\n", pt->x, pt->y);  // should print x=7 y=8
    free(pt);
    return 0;
}