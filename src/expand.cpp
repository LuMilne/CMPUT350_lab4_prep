#include <cassert>  // assert
#include <cstddef>  // size_t
#include <cstdint>  // uint64_t, uint32_t
#include <iostream>
# include <climits>

// Expands the binary representation of input by a factor of scale.
// e.g., expand(0b1111ull, 3) == 0b001001001001
uint64_t expand(uint64_t input, uint32_t scale) {
    assert(scale>0);
    std::cout << sizeof(input)*CHAR_BIT << "\n";
    //for(size_t i = 0; i < input.size())
    return 0;  // replace this with your impl!
}

int main() {
    // test here...
    uint64_t x = expand(0b1111ull, 3);
    return 0;
}
