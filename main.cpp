#include <stdio.h>
#include <stdint.h>

int main(int argc, char *argv[], char *env[]){
    FILE *fp = fopen(argv[1], "rb");
    FILE *fp1 = fopen(argv[2], "rb");
    uint32_t n1;
    uint32_t n2;
    uint32_t r1 = 0;
    uint32_t r2 = 0;
    fread(&n1, 4, 1, fp);
    fread(&n2, 4, 1, fp1);
    for(int i = 0; i < 4; i++){
        r1 |= ((n1 >> (i*8)) & 0xff) << ((3-i)*8);
        r2 |= ((n2 >> (i*8)) & 0xff) << ((3-i)*8);
    }
    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)", r1, r1, r2, r2, r1+r2, r1+r2);
}