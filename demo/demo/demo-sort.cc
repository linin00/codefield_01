#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Vector {
public:
    double x1;
    double y1;
    double x2;
    double y2;
    double length;
    Vector(double X1, double Y1, double X2, double Y2) {
        x1 = X1;
        y1 = Y1;
        x2 = X2;
        y2 = Y2;
        double n1;
        double n2;
        n1 = pow(x2 - x1, 2);
        n2 = pow(y2 - y1, 2);
        length = sqrt(n1 + n2);
    }
    Vector() {}
    bool operator< (Vector dot) {
        if (length < dot.length) return true;
        else return false;
    }
    bool operator> (Vector dot) {
        if (length > dot.length) return true;
        else return false;
    }
    friend ostream &operator<< (ostream &os, Vector dot) {
        os << "(" << dot.x1 << "," << dot.y1 << ")->" << "(" << dot.x2 << "," << dot.y2 << ")";
        return os;
    }
private:
};

template <class T>
class Sorter {
    private:
    T min;
    T max;
    Sorter() { }
public:
    Sorter(T min, T max) {
        this->min = min;
        this->max = max;
    }
    void add(T newEle) {
        if (newEle < min) min = newEle;
        if (newEle > max) max = newEle;
    }
    T getMin() const { return min; }
    T getMax() const { return max; }
};

int main()
{
    Sorter<Vector> sorterTstr(Vector(0, 0, 50, 50), Vector(0, 0, 50, 50));
    sorterTstr.add(Vector(0, 0, 13, 13));
    sorterTstr.add(Vector(0, 0, 94, 94));
    sorterTstr.add(Vector(0, 0, 12, 12));
    sorterTstr.add(Vector(0, 0, 403, 403));
    sorterTstr.add(Vector(0, 0, 590, 590));
    cout << "sorter<string>=> min: " << sorterTstr.getMin() << "    max: " << sorterTstr.getMax() << endl;
    return 0;
}