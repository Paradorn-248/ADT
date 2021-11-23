#include <stdio.h>
#include <string.h>
//น่าจะแก้codeให้เลือกตัวแปรที่มีค่ามากค่าน้อยไว้เลย โดยที่ถ้าน้อยกว่าก้สลับประมานนี้ จะได้ไม่ต้องif-else มากเกิน

int main()
{
    char a[100000], b[100000];
    scanf("%s", a);
    scanf("%s", b);
    int i, lena, len, lenb, summ, carry = 0, res[100001], nub = 0;
    lena = strlen(a);  
    lenb = strlen(b);
    if (lena > lenb)
        len = strlen(b);
    else
        len = strlen(a);
    // printf("%d %d\n",lena,lenb);
    for (i = len - 1; i >= 0; i--)
    {
        summ = (a[lena - nub - 1] - 48) + (b[lenb - nub - 1] - 48) + carry;
        
        if (summ < 10)
        {
            res[nub] = summ;
            carry = 0;
        }
        else
        {
            res[nub] = summ % 10;
            carry = 1;
        }
        nub += 1;
        // printf("%d %d %d\n", summ,carry,nub);
        
    }

    int nub2 = nub;
    if (lena > lenb)
    {
        for (i = lena - nub-1; i >= 0; i--)
        {
            summ = (a[i] - 48) + carry;
            if (summ < 10)
            {
                res[nub2] = summ;
                carry = 0;
            }
            else
            {
                res[nub2] = summ % 10;
                carry = 1;
            }
            nub2 += 1;
            // printf("%d %d %d %d\n",res[nub2], summ,carry,nub2);
        }
    }
    else
    {
        for (i = lenb - nub-1; i >= 0; i--)
        {
            summ = (b[i] - 48) + carry;
            if (summ < 10)
            {
                res[nub2] = summ;
                carry = 0;
            }
            else
            {
                res[nub2] = summ % 10;
                carry = 1;
            }
            nub2 += 1;
        }
    }

    if(carry == 1)
    {
        res[nub2] = 1;
        nub2 += 1;
    }

    for (i = nub2 - 1; i >= 0; i--)
    {
        printf("%d", res[i]);
    }
    return 0;
}