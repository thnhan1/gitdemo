#include <stdio.h>

typedef struct {
    int ts; // Tử số
    int ms; // Mẫu số
} PhanSo;

// Định lý Euclidean để tìm ước chung lớn nhất
int ucln(int a, int b) {
    if (b == 0) return a; // Điều kiện dừng: nếu b = 0, trả về a
    return ucln(b, a % b); // Đệ quy
}

int bcnn(int a, int b) {
    return (a*b)/ucln(a, b);
}

void rutGon(PhanSo *p) {
    int uc = ucln(p->ts, p->ms);
    p->ts = p->ts / uc;
    p->ms = p->ms / uc;
}

PhanSo congPs(PhanSo a, PhanSo b) {
    PhanSo c;
    
    c.ts = a.ts*b.ms + b.ts*a.ms;
    c.ms = a.ms*b.ms;
    return c;
}

int main() {
    PhanSo p;
    p.ts = 2;
    p.ms = 4;
    printf("Phân số ban đầu: %d/%d\n", p.ts, p.ms);
    rutGon(&p);
    printf("Phân số rút gọn: %d/%d\n", p.ts, p.ms);
    
    PhanSo c = congPs(p, congPs(p, p));
    rutGon(&c);
    printf("Phân số rút gọn: %d/%d\n", c.ts, c.ms);
    return 0;
}
