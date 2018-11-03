#ifndef COMMON_H_
#define COMMON_H_

#include <iostream>
#include <ctime>
using namespace std;

class Timer {
public:
    void tic() {
        // start
        clock_ = clock();
    }
    size_t toc() {
        // end
        return static_cast<size_t>(clock() - clock_) * 1000 / CLOCKS_PER_SEC;
    }
private:
    size_t clock_;
};

#define binary_op(op, a, b) [&](){op(a, b);}
#define loop_op(op, n) [&](){for (size_t i = 0; i < n; ++i) {op;}}

template <typename OP>
size_t timing(OP op) {
    Timer timer;
    timer.tic();
    op();
    return timer.toc();
} 

#endif  // COMMON_H_
