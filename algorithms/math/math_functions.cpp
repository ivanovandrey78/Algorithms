#include "math_functions.h"
#include <sstream> 

namespace math {

std::string angle_string(double angle_rad, double tolerance) {
    double normalized = angle_rad;
    while (normalized > PI) normalized -= 2 * PI;
    while (normalized <= -PI) normalized += 2 * PI;

    auto is_close = [tolerance](double a, double b) {
        return abs(a - b) < tolerance;
    };

    // Особые случаи
    if (is_close(normalized, 0.0)) return "0";
    if (is_close(normalized, PI) || is_close(normalized, -PI)) 
        return (normalized < 0) ? "-pi" : "pi";
    if (is_close(normalized, PI/2) || is_close(normalized, -PI/2))
        return (normalized < 0) ? "-pi/2" : "pi/2";


    const int max_den = 12;
    double ratio = normalized / PI;
    int best_num = 0;
    int best_den = 1;
    double best_error = 1e9;

    for (int den = 1; den <= max_den; ++den) {
        int num = static_cast<int>(math::round(ratio * den));
        double approx = static_cast<double>(num) / den;
        double err = abs(approx - ratio);
        if (err < best_error) {
            best_error = err;
            best_num = num;
            best_den = den;
        }
    }

    if (best_error < tolerance * 10) {
        int g = gcd(abs(best_num), best_den);
        best_num /= g;
        best_den /= g;

        std::ostringstream oss;
        if (best_num < 0) oss << "-";

        int abs_num = abs(best_num);
        if (abs_num == 0) return "0";
        if (abs_num == 1) oss << "pi";
        else oss << abs_num << "pi";

        if (best_den != 1)
            oss << "/" << best_den;

        return oss.str();
    }

    // Out in rad if string hasn't pi/n 
    std::ostringstream stream;
    stream.precision(6);
    stream << std::fixed << angle_rad << " rad";
    return stream.str();
}

double sqrt(double n,int maxIterations) {
    if (n < 0) { std::cerr << "Number must be positive" << '\n'; return 1; }
    if (n == 1) return 1.0;
    if (n == 0) return 0.0;
    
    if (maxIterations <= 0) {
        int d = 1;
        while (d*d <= n) {
            if (d * d == n) return static_cast<double>(d);
            d++;
        }
        d--;
        double derivative = 1.0/(2.0*d);
        return d + (n - d*d)*derivative;
    }

    double currentApprox = sqrt(n, maxIterations-1);
    
    double derivative = 1.0/(2.0*currentApprox);
    double result = currentApprox + (n - currentApprox*currentApprox)*derivative;
    
    return result;
}

int min(int a,int b) {
    return (a <= b) ? a : b; 
}

int max(int a,int b) { 
    return (a >= b) ? a : b; 
}

double pow (double n,int rec) {
double prod = 1;
for (int i = 0;i < rec;i++) {prod *= n;}
return prod;
}

// Rounding.
double round(double x) {
    if (x >= 0.0) {
        return static_cast<long long>(x + 0.5);
    } else {
        return static_cast<long long>(x - 0.5);
    }
}

double floor(double x) {
    double result = static_cast<long long>(x);
    if (x < 0.0 && x != result) {
        result -= 1.0;
    }
    return result;
}

double ceil(double x) {
    double result = static_cast<long long>(x);
    if (x > 0.0 && x != result) {
        result += 1.0;
    }
    return result;
}

double trunc(double x) {
    return static_cast<long long>(x);
}

unsigned long factorial(unsigned int n) {
unsigned long result;
if (n==0) {
    result = 1;
} else {
    result = n * factorial(n-1);
}
return result;
}

double ln(double x) {
    if (x <= 0) { 
        throw "ln(x) undefined for x <= 0"; 
    }
    
    int m = 0;
    double s = x;
    
    while (s >= 2.0) {
        s /= 2.0;
        m++;
    }
    while (s < 1.0) {
        s *= 2.0;
        m--;
    }

    double t = (s - 1.0) / (s + 1.0);
    double t_sq = t * t;
    double term = t;
    double sum = term;
    
    for (int k = 1; k <= 20; k++) {
        term *= t_sq;
        double new_term = term / (2*k + 1);
        sum += new_term;
        
        if (new_term < 1e-16) break;
    }
    
    return 2.0 * sum + m * LN2;
}

int abs(int x) {
    return (x > 0) ? x : -x;
}

double abs(double x) {
    return (x > 0.0) ? x : -x;
}

bool isPrime(int n) { 
    bool flag = true;
    for (int d = 2; d < sqrt(n); d++) {
        if (n%d == 0) flag = false;
    }
    return flag;
}

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

double arctan(double x) {
    if (x > 1.0)
        return PI_2 - arctan(1.0 / x);
    if (x < -1.0)
        return -PI_2 - arctan(1.0 / x);

    if (x > 0.0) {
        double t = (x - 1.0) / (x + 1.0);
        double t2 = t * t;
        double sum = 0.0;
        double term = t;
        int sign = 1;

        for (int n = 0; n < 50; ++n) {
            sum += sign * term / (2 * n + 1);
            term *= t2;
            sign = -sign;
        }

        return PI_4 + 2.0 * sum;
    }

    return -arctan(-x);
}

double arctan2(double y, double x) {

    // Сhecking that the value is defined 
    if (x == 0.0) {
        if (y == 0.0) {
            return 0.0;
        }
        return (y > 0.0) ? PI_2 : -PI_2;
    } 

    double ratio = y / x;
    double angle = arctan(ratio);

    if (x < 0.0) {
        if (y >= 0.0) {
            angle += PI;
        } else {
            angle -= PI;
        }
    }

    return angle;
}

}