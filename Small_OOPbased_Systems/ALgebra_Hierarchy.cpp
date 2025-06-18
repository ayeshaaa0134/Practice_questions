#include <iostream>
#include <stdexcept>
#include <algorithm> // Required for std::min, std::abs

template <typename T>
class Algebra;

template <typename T>
class AlgebraUtils {
public:
    static Algebra<T> maxSum(const Algebra<T> arr[], int size);
    static Algebra<T> minDiff(const Algebra<T> arr[], int size);
};

template <typename T>
class Algebra {
private:
    T a, b;
    static int objectCount;

    void validateNonNegative(T val, const std::string& argName) {
        if (val < 0) {
            throw std::invalid_argument(argName + " must be non-negative.");
        }
    }

public:
    Algebra() : a(0), b(0) {
        objectCount++;
    }

    Algebra(T a_val, T b_val) : a(0), b(0) {
        validateNonNegative(a_val, "a");
        validateNonNegative(b_val, "b");
        a = a_val;
        b = b_val;
        objectCount++;
    }

    Algebra(const Algebra<T>& other) : a(other.a), b(other.b) {
        objectCount++;
    }

    virtual ~Algebra() {
        objectCount--;
    }

    void setA(T val) {
        validateNonNegative(val, "a");
        a = val;
    }

    void setB(T val) {
        validateNonNegative(val, "b");
        b = val;
    }

    T getA() const { return a; }
    T getB() const { return b; }

    virtual Algebra<T>& operator+=(const Algebra<T>& rhs) {
        setA(this->a + rhs.a);
        setB(this->b + rhs.b);
        return *this;
    }

    virtual Algebra<T> operator-(const Algebra<T>& rhs) const {
        return Algebra<T>(this->a - rhs.a, this->b - rhs.b);
    }

    bool operator==(const Algebra<T>& rhs) const {
        return (a == rhs.a && b == rhs.b);
    }

    bool operator!=(const Algebra<T>& rhs) const {
        return !(*this == rhs);
    }

    bool operator+() const {
        return (a > 0 || b > 0);
    }

    Algebra<T>& operator++() {
        setA(a + 1);
        setB(b + 1);
        return *this;
    }

    Algebra<T> operator++(int) {
        Algebra<T> temp = *this;
        ++(*this);
        return temp;
    }

    static int getObjectCount() {
        return objectCount;
    }

    int countEqualObjects(const Algebra<T> arr[], int size) const {
        int count = 0;
        for (int i = 0; i < size; ++i) {
            if (*this == arr[i]) {
                count++;
            }
        }
        return count;
    }

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const Algebra<U>& obj);

    template <typename U>
    friend std::istream& operator>>(std::istream& is, Algebra<U>& obj);

    friend class AlgebraUtils<T>;
};

template <typename T>
int Algebra<T>::objectCount = 0;

template <typename T>
std::ostream& operator<<(std::ostream& os, const Algebra<T>& obj) {
    os << "A: " << obj.a << ", B: " << obj.b;
    return os;
}

template <typename T>
std::istream& operator>>(std::istream& is, Algebra<T>& obj) {
    T temp_a, temp_b;
    is >> temp_a >> temp_b;
    obj.setA(temp_a);
    obj.setB(temp_b);
    return is;
}

template <typename T>
class Algebra3D : public Algebra<T> {
private:
    T c;

    void validateNonNegative(T val, const std::string& argName) {
        if (val < 0) {
            throw std::invalid_argument(argName + " must be non-negative.");
        }
    }

public:
    Algebra3D() : Algebra<T>(), c(0) {}

    Algebra3D(T a_val, T b_val, T c_val) : Algebra<T>(a_val, b_val), c(0) {
        validateNonNegative(c_val, "c");
        c = c_val;
    }

    Algebra3D(const Algebra3D<T>& other) : Algebra<T>(other), c(other.c) {}

    void setC(T val) {
        validateNonNegative(val, "c");
        c = val;
    }

    T getC() const { return c; }

    Algebra3D<T>& operator+=(const Algebra<T>& rhs) override {
        const Algebra3D<T>* rhs3D = dynamic_cast<const Algebra3D<T>*>(&rhs);
        if (rhs3D) {
            this->setA(this->getA() + rhs3D->getA());
            this->setB(this->getB() + rhs3D->getB());
            this->setC(this->c + rhs3D->getC());
        } else {
            this->setA(this->getA() + rhs.getA());
            this->setB(this->getB() + rhs.getB());
        }
        return *this;
    }

    Algebra3D<T> operator-(const Algebra<T>& rhs) const override {
        T res_a = this->getA() - rhs.getA();
        T res_b = this->getB() - rhs.getB();
        T res_c;

        const Algebra3D<T>* rhs3D = dynamic_cast<const Algebra3D<T>*>(&rhs);
        if (rhs3D) {
            res_c = this->c - rhs3D->getC();
        } else {
            res_c = this->c - 0;
        }

        if (res_a < 0) res_a = 0;
        if (res_b < 0) res_b = 0;
        if (res_c < 0) res_c = 0;

        return Algebra3D<T>(res_a, res_b, res_c);
    }

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const Algebra3D<U>& obj);

    template <typename U>
    friend std::istream& operator>>(std::istream& is, Algebra3D<U>& obj);
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Algebra3D<T>& obj) {
    os << "A: " << obj.getA() << ", B: " << obj.getB() << ", C: " << obj.c;
    return os;
}

template <typename T>
std::istream& operator>>(std::istream& is, Algebra3D<T>& obj) {
    T temp_a, temp_b, temp_c;
    is >> temp_a >> temp_b >> temp_c;
    obj.setA(temp_a);
    obj.setB(temp_b);
    obj.setC(temp_c);
    return is;
}

template <typename T>
Algebra<T> AlgebraUtils<T>::maxSum(const Algebra<T> arr[], int size) {
    if (size <= 0) {
        throw std::invalid_argument("Array size must be positive for maxSum.");
    }

    Algebra<T> maxObj = arr[0];
    T currentMaxSum = arr[0].getA() + arr[0].getB();
    const Algebra3D<T>* arr0_3D = dynamic_cast<const Algebra3D<T>*>(&arr[0]);
    if (arr0_3D) {
        currentMaxSum += arr0_3D->getC();
    }

    for (int i = 1; i < size; ++i) {
        T currentSum = arr[i].getA() + arr[i].getB();
        const Algebra3D<T>* arr_i_3D = dynamic_cast<const Algebra3D<T>*>(&arr[i]);
        if (arr_i_3D) {
            currentSum += arr_i_3D->getC();
        }

        if (currentSum > currentMaxSum) {
            currentMaxSum = currentSum;
            maxObj = arr[i];
        }
    }
    return maxObj;
}

template <typename T>
Algebra<T> AlgebraUtils<T>::minDiff(const Algebra<T> arr[], int size) {
    if (size <= 0) {
        throw std::invalid_argument("Array size must be positive for minDiff.");
    }

    Algebra<T> minObj = arr[0];
    T currentMinDiff;
    const Algebra3D<T>* arr0_3D = dynamic_cast<const Algebra3D<T>*>(&arr[0]);
    if (arr0_3D) {
        T diff_a_b = std::abs(arr0_3D->getA() - arr0_3D->getB());
        T diff_b_c = std::abs(arr0_3D->getB() - arr0_3D->getC());
        T diff_a_c = std::abs(arr0_3D->getA() - arr0_3D->getC());
        currentMinDiff = std::min({diff_a_b, diff_b_c, diff_a_c});
    } else {
        currentMinDiff = std::abs(arr[0].getA() - arr[0].getB());
    }

    for (int i = 1; i < size; ++i) {
        T currentDiff;
        const Algebra3D<T>* arr_i_3D = dynamic_cast<const Algebra3D<T>*>(&arr[i]);
        if (arr_i_3D) {
            T diff_a_b = std::abs(arr_i_3D->getA() - arr_i_3D->getB());
            T diff_b_c = std::abs(arr_i_3D->getB() - arr_i_3D->getC());
            T diff_a_c = std::abs(arr_i_3D->getA() - arr_i_3D->getC());
            currentDiff = std::min({diff_a_b, diff_b_c, diff_a_c});
        } else {
            currentDiff = std::abs(arr[i].getA() - arr[i].getB());
        }

        if (currentDiff < currentMinDiff) {
            currentMinDiff = currentDiff;
            minObj = arr[i];
        }
    }
    return minObj;
}

int main() {
    std::cout << "--- Testing Algebra<int> ---" << std::endl;
    Algebra<int> alg1;
    std::cout << "alg1 (default): " << alg1 << std::endl;

    try {
        Algebra<int> alg2(10, 20);
        std::cout << "alg2 (10, 20): " << alg2 << std::endl;
        Algebra<int> alg3(-5, 10);
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error creating alg3: " << e.what() << std::endl;
    }

    Algebra<int> alg4(30, 40);
    Algebra<int> alg5 = alg4;
    std::cout << "alg5 (copy of alg4): " << alg5 << std::endl;

    alg1.setA(5);
    alg1.setB(7);
    std::cout << "alg1 after setters: " << alg1 << std::endl;
    std::cout << "alg1.getA(): " << alg1.getA() << ", alg1.getB(): " << alg1.getB() << std::endl;

    try {
        alg1.setA(-1);
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error setting alg1.A: " << e.what() << std::endl;
    }

    std::cout << "Object count: " << Algebra<int>::getObjectCount() << std::endl;

    Algebra<int> op1(10, 5);
    Algebra<int> op2(2, 3);
    std::cout << "op1: " << op1 << ", op2: " << op2 << std::endl;

    op1 += op2;
    std::cout << "op1 += op2: " << op1 << std::endl;

    Algebra<int> op3 = op1 - op2;
    std::cout << "op1 - op2: " << op3 << std::endl;

    std::cout << "op1 == Algebra(12, 8)? " << (op1 == Algebra<int>(12, 8) ? "True" : "False") << std::endl;
    std::cout << "op1 != Algebra(1, 1)? " << (op1 != Algebra<int>(1, 1) ? "True" : "False") << std::endl;

    std::cout << "Unary +op1 (a>0 or b>0): " << (+op1 ? "True" : "False") << std::endl;

    Algebra<int> pre_inc_alg(1, 1);
    std::cout << "pre_inc_alg (before ++pre_inc_alg): " << pre_inc_alg << std::endl;
    ++pre_inc_alg;
    std::cout << "pre_inc_alg (after ++pre_inc_alg): " << pre_inc_alg << std::endl;

    Algebra<int> post_inc_alg(3, 3);
    std::cout << "post_inc_alg (before post_inc_alg++): " << post_inc_alg << std::endl;
    Algebra<int> temp_alg = post_inc_alg++;
    std::cout << "post_inc_alg (after post_inc_alg++): " << post_inc_alg << std::endl;
    std::cout << "temp_alg (result of post_inc_alg++): " << temp_alg << std::endl;

    Algebra<int> input_alg;
    std::cout << "Enter values for input_alg (e.g., 100 200): ";
    std::cin >> input_alg;
    std::cout << "input_alg: " << input_alg << std::endl;

    Algebra<int> arr_alg[] = {Algebra<int>(1, 2), Algebra<int>(1, 2), Algebra<int>(3, 4)};
    std::cout << "Count of (1,2) in array: " << Algebra<int>(1, 2).countEqualObjects(arr_alg, 3) << std::endl;

    std::cout << "--- Testing Algebra3D<float> ---" << std::endl;
    Algebra3D<float> alg3D_1;
    std::cout << "alg3D_1 (default): " << alg3D_1 << std::endl;

    try {
        Algebra3D<float> alg3D_2(1.1f, 2.2f, 3.3f);
        std::cout << "alg3D_2 (1.1, 2.2, 3.3): " << alg3D_2 << std::endl;
        Algebra3D<float> alg3D_3(1.0f, 2.0f, -3.0f);
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error creating alg3D_3: " << e.what() << std::endl;
    }

    Algebra3D<float> alg3D_4(4.4f, 5.5f, 6.6f);
    Algebra3D<float> alg3D_5 = alg3D_4;
    std::cout << "alg3D_5 (copy of alg3D_4): " << alg3D_5 << std::endl;

    alg3D_1.setA(0.5f);
    alg3D_1.setB(0.6f);
    alg3D_1.setC(0.7f);
    std::cout << "alg3D_1 after setters: " << alg3D_1 << std::endl;

    Algebra3D<float> op3D_1(10.0f, 5.0f, 1.0f);
    Algebra3D<float> op3D_2(2.0f, 3.0f, 0.5f);
    std::cout << "op3D_1: " << op3D_1 << ", op3D_2: " << op3D_2 << std::endl;

    op3D_1 += op3D_2;
    std::cout << "op3D_1 += op3D_2: " << op3D_1 << std::endl;

    Algebra<float> base_alg_for_add(1.0f, 1.0f);
    op3D_1 += base_alg_for_add;
    std::cout << "op3D_1 += base_alg_for_add: " << op3D_1 << std::endl;

    Algebra3D<float> op3D_3 = op3D_1 - op3D_2;
    std::cout << "op3D_1 - op3D_2: " << op3D_3 << std::endl;

    Algebra3D<float> op3D_4(5.0f, 5.0f, 5.0f);
    Algebra3D<float> op3D_5(10.0f, 10.0f, 10.0f);
    Algebra3D<float> op3D_6 = op3D_4 - op3D_5;
    std::cout << "op3D_4 - op3D_5 (clamped): " << op3D_6 << std::endl;

    Algebra3D<float> input_alg3D;
    std::cout << "Enter values for input_alg3D (e.g., 10.5 20.5 30.5): ";
    std::cin >> input_alg3D;
    std::cout << "input_alg3D: " << input_alg3D << std::endl;

    std::cout << "--- Testing AlgebraUtils ---" << std::endl;

    Algebra<int> alg_arr_int[] = {
        Algebra<int>(1, 2),
        Algebra<int>(10, 5),
        Algebra3D<int>(2, 3, 4),
        Algebra<int>(0, 0),
        Algebra3D<int>(100, 1, 1)
    };
    int size_int = sizeof(alg_arr_int) / sizeof(alg_arr_int[0]);

    Algebra<int> max_sum_int = AlgebraUtils<int>::maxSum(alg_arr_int, size_int);
    std::cout << "Max sum object (int): " << max_sum_int << std::endl;

    Algebra<int> min_diff_int = AlgebraUtils<int>::minDiff(alg_arr_int, size_int);
    std::cout << "Min diff object (int): " << min_diff_int << std::endl;

    Algebra<float> alg_arr_float[] = {
        Algebra<float>(1.1f, 1.2f),
        Algebra3D<float>(5.0f, 5.1f, 5.2f),
        Algebra<float>(10.0f, 0.0f)
    };
    int size_float = sizeof(alg_arr_float) / sizeof(alg_arr_float[0]);

    Algebra<float> max_sum_float = AlgebraUtils<float>::maxSum(alg_arr_float, size_float);
    std::cout << "Max sum object (float): " << max_sum_float << std::endl;

    Algebra<float> min_diff_float = AlgebraUtils<float>::minDiff(alg_arr_float, size_float);
    std::cout << "Min diff object (float): " << min_diff_float << std::endl;

    std::cout << "Final object count: " << Algebra<int>::getObjectCount() + Algebra<float>::getObjectCount() << std::endl;

    return 0;
}