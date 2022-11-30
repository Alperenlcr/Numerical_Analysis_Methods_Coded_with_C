#include <stdio.h>
#define MAX 20

void girdi_alma(float *a, float *b, float *n);
float us_al(float x, int y);
float denklem(float x, float carpanlar[MAX], int derece);
float cozum(float a, float b, float n, float carpanlar[MAX], int derece);

int main()
{
    float carpanlar[MAX] = {0}, a, b, n;
    int derece, i;

    printf("Turevi alinacak denklemin derecesi : ");
    scanf("%d", &derece);
    for ( i = 0; i <= derece; i++)
    {
        printf("x uzeri %d nin carpanini giriniz : ", i);
        scanf("%f",  &carpanlar[i]);
    }
    printf("\n----------------------\n\n");
    girdi_alma(&a, &b, &n);
    printf("Denklemin %.2f  -  %.2f araligindaki integralinin alani : %f\n", a, b, cozum(a, b, n, carpanlar, derece));

    return 0;
}

void girdi_alma(float *a, float *b, float *n)
{
    printf("Integral alinacak araligin baslangic degeri (a): ");
    scanf("%f", a);
    printf("Integral alinacak araligin bitis degeri (b) : ");
    scanf("%f", b);
    printf("n degerini giriniz (a-b arasinda kac yamuk olacak) (n) : ");
    scanf("%f", n);
}

float us_al(float x, int y)
{
    if (y == 0)
        return 1;
    else
        return us_al(x, y-1)*x;
}

float denklem(float x, float carpanlar[MAX], int derece)
{
    int i;
    float res = 0;
    for ( i = 0; i <= derece; i++)
        res += carpanlar[i] * us_al(x, i);
    return res;
}

float cozum(float a, float b, float n, float carpanlar[MAX], int derece)
{
    float h = (b - a) / n;
    float sonuc = h;
    float toplam = (denklem(a, carpanlar, derece) + denklem(b, carpanlar, derece)) / 2.0;
    while (a != b)
    {
        a += h;
        toplam += denklem(a, carpanlar, derece);
    }

    // alan pozitif olmali
    if (toplam < 0)
        toplam *= -1;

    return sonuc*toplam;
}

/*
-2  -1       n=4
x*x*x + 2*x*x - x - 2
0,4166
*/