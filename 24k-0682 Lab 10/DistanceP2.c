#include <stdio.h>
#include <math.h>
typedef struct {
    double x;
    double y;
} Point;

double calculateDistance(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}
int isPointInRectangle(Point p, double x1, double y1, double x2, double y2) {
    return (p.x >= x1 && p.x <= x2 && p.y >= y1 && p.y <= y2);
}

int main() {
    Point p1 = {3.0, 4.0};
    Point p2 = {6.0, 8.0};
    printf("Distance between points: %.2f\n", calculateDistance(p1, p2));
    double x1 = 2.0, y1 = 3.0, x2 = 7.0, y2 = 9.0;
    Point testPoint = {5.0, 6.0};

    if (isPointInRectangle(testPoint, x1, y1, x2, y2)) {
        printf("Point (%.2f, %.2f) lies within the rectangle.\n", testPoint.x, testPoint.y);
    } else {
        printf("Point (%.2f, %.2f) does not lie within the rectangle.\n", testPoint.x, testPoint.y);
    }

    return 0;
}
