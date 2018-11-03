#include "common.h"

template <typename OP>
void timing_op(OP op) {
    size_t loop_time = 1000000000;
    cout << timing(loop_op(op(), loop_time)) << " ms" << endl;
}

#define timing_binary_op(op, DType) \
    timing_op([](){DType a=3943321.32132, b=34321439.9312311;DType c = op;})

#define timing_basic_binary_op(DType) \
    cout << "Test " #DType << endl; \
    timing_binary_op(a + b, DType); \
    timing_binary_op(a - b, DType); \
    timing_binary_op(a * b, DType); \
    timing_binary_op(a / b, DType);

int main() {
    timing_basic_binary_op(int);
    timing_basic_binary_op(int32_t);
    timing_basic_binary_op(int64_t);
    timing_basic_binary_op(float);
    timing_basic_binary_op(double);
    return 0;
}
