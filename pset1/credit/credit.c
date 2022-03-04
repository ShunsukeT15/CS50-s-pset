#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long Num;
    int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p;
    int ad, cd, ed, gd, id, kd, md, od;
    int Sum, opSum;

    Num = get_long("Number: ");

    //16桁
    if (1000000000000000 <= Num && Num < 10000000000000000)
    {
        a = Num / 1000000000000000;
        b = (Num % 1000000000000000) / 100000000000000;
        c = (Num % 100000000000000) / 10000000000000;
        d = (Num % 10000000000000) / 1000000000000;
        e = (Num % 1000000000000) / 100000000000;
        f = (Num % 100000000000) / 10000000000;
        g = (Num % 10000000000) / 1000000000;
        h = (Num % 1000000000) / 100000000;
        i = (Num % 100000000) / 10000000;
        j = (Num % 10000000) / 1000000;
        k = (Num % 1000000) / 100000;
        l = (Num % 100000) / 10000;
        m = (Num % 10000) / 1000;
        n = (Num % 1000) / 100;
        o = (Num % 100) / 10;
        p = (Num % 10);

        //その数字の最後から2番目の数字から始め,1桁おきに2倍する
        ad = 2 * a;
        cd = 2 * c;
        ed = 2 * e;
        gd = 2 * g;
        id = 2 * i;
        kd = 2 * k;
        md = 2 * m;
        od = 2 * o;

        //積の和
        ad = (ad / 10) + (ad % 10);
        cd = (cd / 10) + (cd % 10);
        ed = (ed / 10) + (ed % 10);
        gd = (gd / 10) + (gd % 10);
        id = (id / 10) + (id % 10);
        kd = (kd / 10) + (kd % 10);
        md = (md / 10) + (md % 10);
        od = (od / 10) + (od % 10);

        Sum = ad + b + cd + d + ed + f + gd + h + id + j + kd + l + md + n + od + p;

        //有効か調べる
        opSum = Sum % 10;
        if (opSum == 0)
        {
            if (a == 4)
            {
                printf("VISA\n");
            }
            else if (a == 5 && (b == 1 || b == 2 || b == 3 || b == 4 || b == 5))
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }

        }
        else
        {
            printf("INVALID\n");

        }

    }
    /*16桁ここまで*/
    //15桁
    else if (100000000000000 <= Num && Num < 1000000000000000)
    {
        b = Num / 100000000000000;
        c = (Num % 100000000000000) / 10000000000000;
        d = (Num % 10000000000000) / 1000000000000;
        e = (Num % 1000000000000) / 100000000000;
        f = (Num % 100000000000) / 10000000000;
        g = (Num % 10000000000) / 1000000000;
        h = (Num % 1000000000) / 100000000;
        i = (Num % 100000000) / 10000000;
        j = (Num % 10000000) / 1000000;
        k = (Num % 1000000) / 100000;
        l = (Num % 100000) / 10000;
        m = (Num % 10000) / 1000;
        n = (Num % 1000) / 100;
        o = (Num % 100) / 10;
        p = (Num % 10);

        cd = 2 * c;
        ed = 2 * e;
        gd = 2 * g;
        id = 2 * i;
        kd = 2 * k;
        md = 2 * m;
        od = 2 * o;

        cd = (cd / 10) + (cd % 10);
        ed = (ed / 10) + (ed % 10);
        gd = (gd / 10) + (gd % 10);
        id = (id / 10) + (id % 10);
        kd = (kd / 10) + (kd % 10);
        md = (md / 10) + (md % 10);
        od = (od / 10) + (od % 10);

        Sum = b + cd + d + ed + f + gd + h + id + j + kd + l + md + n + od + p;

        //有効か調べる
        opSum = Sum % 10;

        if (opSum == 0 && b == 3)
        {
            if (c == 4 || c == 7)
            {
                printf("AMEX\n");

            }
            else
            {
                printf("INVALID\n");

            }

        }
        else
        {
            printf("INVALID\n");
        }

    }
    /*13桁ここから*/
    else if (1000000000000 <= Num && Num < 10000000000000)
    {
        d = Num / 1000000000000;
        e = (Num % 1000000000000) / 100000000000;
        f = (Num % 100000000000) / 10000000000;
        g = (Num % 10000000000) / 1000000000;
        h = (Num % 1000000000) / 100000000;
        i = (Num % 100000000) / 10000000;
        j = (Num % 10000000) / 1000000;
        k = (Num % 1000000) / 100000;
        l = (Num % 100000) / 10000;
        m = (Num % 10000) / 1000;
        n = (Num % 1000) / 100;
        o = (Num % 100) / 10;
        p = (Num % 10);

        //2桁おきに2倍
        ed = 2 * e;
        gd = 2 * g;
        id = 2 * i;
        kd = 2 * k;
        md = 2 * m;
        od = 2 * o;

        ed = (ed / 10) + (ed % 10);
        gd = (gd / 10) + (gd % 10);
        id = (id / 10) + (id % 10);
        kd = (kd / 10) + (kd % 10);
        md = (md / 10) + (md % 10);
        od = (od / 10) + (od % 10);

        Sum = d + ed + f + gd + h + id + j + kd + l + md + n + od + p;

        /*有効か調べる*/
        opSum = Sum % 10;

        if (opSum == 0 && d == 4)
        {
            printf("VISA\n");

        }
        else
        {
            printf("INVALID\n");

        }

    }
    else
    {
        printf("INVALID\n");

    }

    return 0;
}