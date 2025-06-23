#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

// Function to determine orientation of three points
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;  // Collinear
    return (val > 0) ? 1 : 2; // 1 -> Clockwise, 2 -> Counterclockwise
}

// Function to find the reference point (lowest y, then lowest x)
bool compare(Point p1, Point p2) {
    return (p1.y < p2.y) || (p1.y == p2.y && p1.x < p2.x);
}

// Convex Hull using Graham's Scan
vector<Point> convexHull(vector<Point> &points) {
    int n = points.size();
    if (n < 3) return {}; // Convex hull is not possible with < 3 points

    // Step 1: Find the lowest point (smallest y, then x)
    sort(points.begin(), points.end(), compare);
    Point ref = points[0];

    // Step 2: Sort remaining points based on polar order (left turn preference)
    sort(points.begin() + 1, points.end(), [&](Point p1, Point p2) {
        int o = orientation(ref, p1, p2);
        if (o == 0) // Collinear points: keep the farthest one
            return ((ref.x - p1.x) * (ref.x - p1.x) + (ref.y - p1.y) * (ref.y - p1.y)) <
                   ((ref.x - p2.x) * (ref.x - p2.x) + (ref.y - p2.y) * (ref.y - p2.y));
        return (o == 2); // Counterclockwise comes first
    });

    // Step 3: Use a stack to build the convex hull
    stack<Point> s;
    s.push(points[0]);
    s.push(points[1]);

    for (int i = 2; i < n; i++) {
        while (s.size() > 1 && orientation(next(s.top()), s.top(), points[i]) != 2) {
            s.pop(); // Remove right turns
        }
        s.push(points[i]);
    }

    // Step 4: Store result in a vector
    vector<Point> hull;
    while (!s.empty()) {
        hull.push_back(s.top());
        s.pop();
    }

    return hull;
}

int main() {
    vector<Point> points = {{0, 0}, {4, 0}, {4, 3}, {2, 5}, {0, 3}};

    vector<Point> hull = convexHull(points);

    cout << "Points in Convex Hull:\n";
    for (Point p : hull) {
        cout << "(" << p.x << ", " << p.y << ")\n";
    }

    return 0;
}
