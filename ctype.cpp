#include "common.h"

template <typename OP>
void timing_op(OP op) {
    size_t loop_time = 1000000000;
    cout << timing(loop_op(op(), loop_time)) - timing(loop_op({}, loop_time)) << " ms" << endl;
}

#define timing_binary_op(op, DType) \
    timing_op([](){DType a=39.12, b=34.93;DType c = op;})

#define timing_basic_binary_op(DType) \
    cout << "Test " #DType << endl; \
    timing_binary_op(a + b, DType); \
    timing_binary_op(a - b, DType); \
    timing_binary_op(a * b, DType); \
    timing_binary_op(a / b, DType);

int main() {
    timing_basic_binary_op(int8_t);
    timing_basic_binary_op(int16_t);
    timing_basic_binary_op(int32_t);
    timing_basic_binary_op(int64_t);
    timing_basic_binary_op(float);
    timing_basic_binary_op(double);
    return 0;
}
