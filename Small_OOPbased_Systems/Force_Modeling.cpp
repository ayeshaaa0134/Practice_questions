#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

template <typename T> class Force2D;
template <typename T> class ForceUtils;

template <typename T>
class Force2D {
private:
    T fx, fy;
    static int objectCount;

    void validate(T x, T y) {
        if (x < 0 || y < 0) {
            throw invalid_argument("Force components must be non-negative.");
        }
    }

public:
    // Constructors
    Force2D() : fx(0), fy(0) { objectCount++; }
    Force2D(T x, T y) { validate(x, y); fx = x; fy = y; objectCount++; }
    Force2D(const Force2D<T>& other) : fx(other.fx), fy(other.fy) { objectCount++; }

    // Destructor
    virtual ~Force2D() { objectCount--; }

    // Setters (with validation)
    void setFx(T val) { if (val < 0) throw invalid_argument("fx must be non-negative."); fx = val; }
    void setFy(T val) { if (val < 0) throw invalid_argument("fy must be non-negative."); fy = val; }

    // Getters
    T getFx() const { return fx; }
    T getFy() const { return fy; }

    static int getObjectCount() { return objectCount; }

    // Virtual Operators
    virtual Force2D<T>& operator+=(const Force2D<T>& rhs) { fx += rhs.fx; fy += rhs.fy; return *this; }
    virtual Force2D<T> operator-(const Force2D<T>& rhs) const {
        T newFx = fx - rhs.fx; T newFy = fy - rhs.fy;
        if (newFx < 0 || newFy < 0) throw invalid_argument("Subtraction results in negative components.");
        return Force2D<T>(newFx, newFy);
    }

    // Other Operators
    bool operator==(const Force2D<T>& rhs) const { return (fx == rhs.fx && fy == rhs.fy); }
    bool operator!=(const Force2D<T>& rhs) const { return !(*this == rhs); }
    bool operator+() const { return (fx > 0 || fy > 0); } // Unary +

    Force2D<T>& operator++() { fx++; fy++; return *this; } // Pre-increment
    Force2D<T> operator++(int) { Force2D<T> temp = *this; fx++; fy++; return temp; } // Post-increment

    // Friend stream operators
    friend ostream& operator<<<T>(ostream& os, const Force2D<T>& f) { os << "F2D(" << f.fx << "," << f.fy << ")"; return os; }
    friend istream& operator>><T>(istream& is, Force2D<T>& f) {
        T tx, ty; is >> tx >> ty;
        if (is.fail() || tx < 0 || ty < 0) { is.setstate(ios::failbit); throw invalid_argument("Invalid 2D input."); }
        f.fx = tx; f.fy = ty; return is;
    }

    // Other Functions
    int countEqualForces(const Force2D<T> arr[], int size) const {
        int count = 0;
        for (int i = 0; i < size; ++i) if (*this == arr[i]) count++;
        return count;
    }

    // Friend class declaration
    friend class ForceUtils<T>;
};

template <typename T> int Force2D<T>::objectCount = 0;

template <typename T>
class Force3D : public Force2D<T> {
private:
    T fz; // Z-component

public:
    // Constructors
    Force3D() : Force2D<T>(), fz(0) {}
    Force3D(T x, T y, T z) : Force2D<T>(x, y) { if (z < 0) throw invalid_argument("fz must be non-negative."); fz = z; }
    Force3D(const Force3D<T>& other) : Force2D<T>(other), fz(other.fz) {}
    ~Force3D() override {} // Calls base destructor automatically

    // Set/Get fz
    void setFz(T val) { if (val < 0) throw invalid_argument("fz must be non-negative."); fz = val; }
    T getFz() const { return fz; }

    // Overrides
    Force3D<T>& operator+=(const Force2D<T>& rhs) override {
        Force2D<T>::operator+=(rhs); // Handle fx, fy
        if (const Force3D<T>* rhs3D = dynamic_cast<const Force3D<T>*>(&rhs)) fz += rhs3D->fz;
        return *this;
    }

    Force3D<T> operator-(const Force2D<T>& rhs) const override {
        Force2D<T> baseResult = Force2D<T>::operator-(rhs); // Get fx, fy result
        T newFz = fz;
        if (const Force3D<T>* rhs3D = dynamic_cast<const Force3D<T>*>(&rhs)) newFz -= rhs3D->fz;
        if (newFz < 0) throw invalid_argument("Subtraction results in negative fz.");
        return Force3D<T>(baseResult.getFx(), baseResult.getFy(), newFz);
    }

    // Friend stream operators for Force3D
    friend ostream& operator<<<T>(ostream& os, const Force3D<T>& f) { os << "F3D(" << f.fx << "," << f.fy << "," << f.fz << ")"; return os; }
    friend istream& operator>><T>(istream& is, Force3D<T>& f) {
        T tx, ty, tz; is >> tx >> ty >> tz;
        if (is.fail() || tx < 0 || ty < 0 || tz < 0) { is.setstate(ios::failbit); throw invalid_argument("Invalid 3D input."); }
        f.fx = tx; f.fy = ty; f.fz = tz; return is;
    }
};

// --- Friend Class: ForceUtils ---
template <typename T>
class ForceUtils {
public:
    // Finds force with max magnitude in a 2D array
    static Force2D<T> maxMagnitude(const Force2D<T> arr[], int size) {
        if (size <= 0) throw invalid_argument("Array size must be positive.");
        T maxMag = sqrt(arr[0].fx * arr[0].fx + arr[0].fy * arr[0].fy);
        Force2D<T> maxF = arr[0];
        for (int i = 1; i < size; ++i) {
            T currentMag = sqrt(arr[i].fx * arr[i].fx + arr[i].fy * arr[i].fy);
            if (currentMag > maxMag) { maxMag = currentMag; maxF = arr[i]; }
        }
        return maxF;
    }

    // Finds a force that contributes to the min Fx difference
    static Force2D<T> minFxDifference(const Force2D<T> arr[], int size) {
        if (size < 2) throw invalid_argument("Array size must be at least 2.");
        T minDiff = abs(arr[0].fx - arr[1].fx);
        Force2D<T> resultF = arr[0];
        for (int i = 0; i < size; ++i) {
            for (int j = i + 1; j < size; ++j) {
                T currentDiff = abs(arr[i].fx - arr[j].fx);
                if (currentDiff < minDiff) { minDiff = currentDiff; resultF = arr[i]; }
            }
        }
        return resultF;
    }

    // Helper for 2D magnitude
    static T calculateMagnitude2D(const Force2D<T>& f) { return sqrt(f.fx * f.fx + f.fy * f.fy); }
    // Helper for 3D magnitude
    static T calculateMagnitude3D(const Force3D<T>& f) { return sqrt(f.getFx() * f.getFx() + f.getFy() * f.getFy() + f.fz * f.fz); }
};

// --- Main Demonstration ---
int main() {
    cout << "--- Force Demos ---" << endl;

    try {
        Force2D<double> f2d_a(10.0, 5.0);
        cout << "F2D_A: " << f2d_a << " | Objects: " << Force2D<double>::getObjectCount() << endl;

        Force3D<double> f3d_a(1.0, 2.0, 3.0);
        cout << "F3D_A: " << f3d_a << " | Objects: " << Force2D<double>::getObjectCount() << endl;

        // Operator tests
        Force2D<double> f2d_b(3.0, 7.0);
        f2d_a += f2d_b;
        cout << "F2D_A += F2D_B: " << f2d_a << endl;

        Force3D<double> f3d_b(0.5, 1.5, 2.5);
        f3d_a += f3d_b; // Polymorphic add
        cout << "F3D_A += F3D_B: " << f3d_a << endl;

        Force2D<double> f_diff = f2d_a - f2d_b;
        cout << "F2D_A - F2D_B: " << f_diff << endl;

        cout << "F2D_A == F2D_B? " << (f2d_a == f2d_b ? "Yes" : "No") << endl;
        cout << "F2D_A positive? " << (+f2d_a ? "Yes" : "No") << endl;
        cout << "++F2D_A: " << ++f2d_a << endl;

        // Exception test
        try { Force2D<double> invalid_f(-1, 0); }
        catch (const invalid_argument& e) { cerr << "Error: " << e.what() << endl; }

        // Array functions
        Force2D<double> f_array[] = {Force2D<double>(10,0), Force2D<double>(3,4), Force2D<double>(6,8)};
        cout << "Max Magnitude Force: " << ForceUtils<double>::maxMagnitude(f_array, 3) << endl;
        cout << "Min Fx Diff Force: " << ForceUtils<double>::minFxDifference(f_array, 3) << endl;
        cout << "Magnitude of F3D_A: " << ForceUtils<double>::calculateMagnitude3D(f3d_a) << endl;

    } catch (const exception& e) {
        cerr << "Unhandled Error: " << e.what() << endl;
    }

    cout << "\nFinal Object Count: " << Force2D<double>::getObjectCount() << endl;

    return 0;
}