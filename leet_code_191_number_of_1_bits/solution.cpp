class Solution {
public:
    int hammingWeight(uint32_t n) 
    {
        static size_t constexpr BIT_COUNT{ sizeof(n) * 8U }; // 8 bits per byte
        int one_bit_count{ 0 }; // hamming weight
        for(size_t i{ 0 }; i < BIT_COUNT; ++i)
        {
            one_bit_count += n & 0x1;
            n >>= 1;
        }
        return one_bit_count;
    }
};
