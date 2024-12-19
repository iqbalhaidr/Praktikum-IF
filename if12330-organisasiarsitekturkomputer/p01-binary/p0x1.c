#include <stdio.h>


int chicken_or_beef(int chicken, int beef){
    int steakayam = (chicken >> 4) & 0xF;
    int steaksapi = (beef << 1) & 0xF;
    return steakayam | steaksapi;
}

int masquerade(){
    return (1 << 31)^1;
}

int airaniiofifteen(int iofi){
    int b0 = iofi & 1;
    int b1 = (iofi >> 1) & 1;
    int b2 = (iofi >> 2) & 1;
    int b3 = (iofi >> 3) & 1;
    int b4plus = !(iofi >> 4);

    return (b0 & b1 & b2 & b3) & b4plus;
}

unsigned yobanashi_deceive(unsigned f){
    return f >> 3;
}

int snow_mix(int N){
    int addend = 1 << 23;
    int sum = N ^ addend;
    int carry = (N & addend) << 1;

    int new_sum = sum ^ carry;
    int new_carry = (sum & carry) << 1;

    return new_sum ^ new_carry;
}
int sky_hundred(int n) {

    int is_negative = (n >> 31) & 1;
    int mod4 = n & 3;
    int modand = mod4 & 1;
    int mods = mod4 >> 1;
    int is_mod0 = !(mod4);
    int is_mod1 = (modand) & ~(mods);
    int is_mod2 = ((mods) & 1) & ~(modand);

    int result = (n & (~is_mod0 + 1)) | 1 &(~is_mod1 + 1) |((n + 1) & (~is_mod2 + 1)); 
    int shift = ~((is_negative << 31) >> 31); 

    return (result & ~is_negative) & shift;
}


int kitsch(int x) {
    int a = x & 63;
    int b = x >> 31;
    int c = ((a + ((x & 3) << 4)) >> 6) + (b & !(!a)); 
    int d = ((x >> 6) + (x >> 2)) + c;
    return d;
}


int ganganji(int x) {
    int part1 = (x >> 3) << 3;  
    int part1b = part1 + (x >> 3);  
    int part2 = (x & 7) << 3;  
    int part2b = part2 + (x & 7);  
    int result = part1b + (part2b >> 3);
    int max_int = ~(1 << 31); 
    int overflow = (result >> 31) & 1;
    int overflow2 = ~overflow + 1;
    return (overflow2 & max_int) | (~overflow2 & result);
}

unsigned how_to_sekai_seifuku(unsigned a) {
    unsigned b = (a >> 15) & 1;
    unsigned c = (a >> 10) & 0x1F;
    unsigned d = a & 0x03FF;
    unsigned e = b << 31;

    if (c == 0) {
        if (d == 0) {
            return e;
        }
        while ((d & 0x0400) == 0) {
            d = d << 1;
            c = c - 1;
        }
        c = c + 1;
        d = d & 0x03FF;
    } else if ((c & 0x1F) == 0x1F) {
        if ((d & 0x3FF) == 0) {
            return e | 0x7F800000;
        }
        return 0x7F800001;
    }

    c = c + (127 - 15);
    e = e | (c << 23);
    e = e | (d << 13);

    return e;
}

int mesmerizer(unsigned uf) {
    unsigned a = uf >> 31;
    unsigned b = (uf >> 23) & 0xFF;
    unsigned c = uf & 0x7FFFFF;
    int d;
    int e;

    if (b == 0xFF) {
        return 0x80000000;
    }
    if (b < 127) {
        return 0;
    }

    c |= 0x800000;
    d = b - 127;
    if (d > 31) {
        return 0x80000000;
    }

    if (d >= 23) {
        e = c << (d - 23);
    } else {
        e = c >> (23 - d);
    }

    if (a) {
        e = -e;
    }

    return e;
}

int main() {
    int x;
    scanf("%d", &x);
    int z = kitsch(x);
    int y = kitsch2(x);
    printf("i: %d\n", z);
    printf("s: %d", y);
    return 0;
}