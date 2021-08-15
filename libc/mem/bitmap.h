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
