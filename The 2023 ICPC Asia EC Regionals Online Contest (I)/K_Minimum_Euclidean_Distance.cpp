#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

template<class T>
struct Point {
    T x;
    T y;
    Point(const T &x_ = 0, const T &y_ = 0) : x(x_), y(y_) {}

    template<class U>
    operator Point<U>() {
        return Point<U>(U(x), U(y));
    }

    Point &operator-=(const Point &p) & {
        x -= p.x;
        y -= p.y;
        return *this;
    }

    Point &operator+=(const Point &p) & {
        x += p.x;
        y += p.y;
        return *this;
    }

    Point &operator/=(const T &v) & {
        x /= v;
        y /= v;
        return *this;
    }

    friend Point operator-(Point a, const Point &b) {
        return a -= b;
    }

    friend Point operator+(Point a, const Point &b) {
        return a += b;
    }

    friend Point operator/(Point a, const T &b) {
        return a /= b;
    }
};

template<class T>
struct Line {
    Point<T> a;
    Point<T> b;
    Line(const Point<T> &a_ = Point<T>(), const Point<T> &b_ = Point<T>()) : a(a_), b(b_) {}
};

template<class T>
T dot(const Point<T> &a, const Point<T> &b) {
    return a.x * b.x + a.y * b.y;
}

template<class T>
T cross(const Point<T> &a, const Point<T> &b) {
    return a.x * b.y - a.y * b.x;
}

template<class T>
double length(const Point<T> &p) {
    return sqrt(dot(p, p));
}

template<class T>
double length(const Line<T> &l) {
    return length(l.a - l.b);
}

template<class T>
double distance(const Point<T> &a, const Point<T> &b) {
    return length(a - b);
}

template<class T>
double distancePL(const Point<T> &p, const Line<T> &l) {
    return abs(cross(l.a - l.b, l.a - p)) / length(l);
}

template<class T>
double distancePS(const Point<T> &p, const Line<T> &l) {
    if (dot(p - l.a, l.b - l.a) < 0) {
        return distance(p, l.a);
    }
    if (dot(p - l.b, l.a - l.b) < 0) {
        return distance(p, l.b);
    }
    return distancePL(p, l);
}

template<class T>
bool pointOnLineLeft(const Point<T> &p, const Line<T> &l) {
    return cross(l.b - l.a, p - l.a) > 0;
}

template<class T>
bool pointOnSegment(const Point<T> &p, const Line<T> &l) {
    return cross(p - l.a, l.b - l.a) == 0 && min(l.a.x, l.b.x) <= p.x && p.x <= max(l.a.x, l.b.x) && min(l.a.y, l.b.y) <= p.y && p.y <= max(l.a.y, l.b.y);
}

template<class T>
double distanceToPolygon(const Point<T> &a, const vector<Point<T>> &p) {
    int n = p.size();
    double res = 1e18;
    for (int i = 0; i < n; i++) {
        auto u = p[i];
        auto v = p[(i + 1) % n];
        res = min(res, distancePS(a, Line(u, v)));
    }
    return res;
}

template<class T>
bool pointInPolygon(const Point<T> &a, const vector<Point<T>> &p) {
    int n = p.size();
    for (int i = 0; i < n; i++) {
        if (pointOnSegment(a, Line(p[i], p[(i + 1) % n]))) {
            return true;
        }
    }

    int t = 0;
    for (int i = 0; i < n; i++) {
        auto u = p[i];
        auto v = p[(i + 1) % n];
        if (u.x < a.x && v.x >= a.x && pointOnLineLeft(a, Line(v, u))) {
            t ^= 1;
        }
        if (u.x >= a.x && v.x < a.x && pointOnLineLeft(a, Line(u, v))) {
            t ^= 1;
        }
    }
    return t == 1;
}

using ld = long double;
using P = Point<ld>;

constexpr ld eps = 1e-6;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<P> p(n);
    for (int i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;
        p[i] = {x, y};
    }

    while (q--) {
        P a, b;
        cin >> a.x >> a.y >> b.x >> b.y;
        P c = (a + b) / 2;
        double r = length(Line(a, b)) / 2;

        double res = r * r / 2;
        if (!pointInPolygon(c, p)) {
            // cerr << "ok\n";
            double d = distanceToPolygon(c, p);
            res += d * d;
        }

        cout << fixed << setprecision(10) << res << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}