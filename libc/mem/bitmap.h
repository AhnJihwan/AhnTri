/*
bitmap array:
                    0	1	2	3	4	5	6	7         8
bitmap[]	1	1	1	1	1	1	1	1         1
                |  bitmap_set(bitmap, 0);
                V
                    0	1	2	3	4	5	6	7         8
bitmap[]	0	0	0	0	0	0	0	0         0
*/

#define BITMAP_ROW_SIZE 32

void bitmap_set(uint32_t *bitmap, int bit) {
    bitmap[bit / BITMAP_ROW_SIZE] |= (1 << (bit % BITMAP_ROW_SIZE));
}

void bitmap_unset(uint32_t *bitmap, int bit) {
    bitmap[bit / BITMAP_ROW_SIZE] &= ~(1 << (bit % BITMAP_ROW_SIZE));
}

// The following (int) function is borrowed from (lucic71/lucicOS) licenced under (BSD 2-Clause "Simplified" License)
int bitmap_first_unset(uint32_t *bitmap, size_t size) {
    uint32_t rem_bits = size % 32;
    for (uint32_t i = 0; i < size / 32; i++){
        if (bitmap[i] != 0XFFFFFFFF){
            for (int j = 0; j < 32; j++){
                if (!(bitmap[i] & (1 << j))){
                    return (i * 32) + j;
                }
            }
        }
    }
    if (rem_bits) {
        for (uint32_t j = 0; j < rem_bits; j++){
            if (!(bitmap[size / 32] & (1 << j))){
                    return ((size / 32) * 32) + j;
            }
        }
    }
    return -1;
}
