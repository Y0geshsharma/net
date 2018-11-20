#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m, n, i, j, k, flag = 0;
    printf("ENTER MAXIMUM FRAME SIZE : ");
    scanf("%d", &m);
    char frame[m];
    printf("\nENTER FRAME DATA : ");
    scanf("%s", frame);
    frame[strlen(frame)] = '\0';
    printf("\nENTER MAXIMUM GENERATOR SIZE : ");
    scanf("%d", &n);
    char generator[n];
    printf("\nENTER GENERATOR DATA : ");
    scanf("%s", generator);
    generator[strlen(generator)] = '\0';
    char temp[strlen(frame)+strlen(generator)-1], crc[strlen(generator) - 1], codeword[strlen(frame)+strlen(generator)-1], remainder[strlen(generator)-1];
    for (i = 0; i < strlen(frame); i++)
        temp[i] = frame[i];
    for (i = strlen(frame); i < strlen(frame) + strlen(generator) - 1; i++)
        temp[i] = '0';
    temp[strlen(frame)+strlen(generator)-1] = '\0';
    for (i = 0; i < strlen(frame); i++)
    {
        j = 0;
        k = i;
        if (temp[k] >= generator[j])
        {
            for (j = 0, k = i; j < strlen(generator); j++, k++)
            {
                if (temp[k] == generator[j])
                    temp[k] = '0';
                else
                    temp[k] = '1';
            }
        }
    }
    for (i = 0, j = strlen(frame); i < strlen(generator) - 1; i++, j++)
        crc[i] = temp[j];
    crc[strlen(generator)-1] = '\0';
    printf("\nCRC BITS : %s", crc);
    for (i = 0; i < strlen(frame); i++)
        codeword[i] = frame[i];
    for (i = strlen(frame), j = 0; i < strlen(frame) + strlen(generator) - 1; i++, j++)
        codeword[i] = crc[j];
    codeword[strlen(frame)+strlen(generator)-1] = '\0';
    printf("\nCODEWORD : %s", codeword);
    for (i = 0; i < strlen(frame) + strlen(generator) - 1; i++)
        temp[i] = codeword[i];
    for (i = 0; i < strlen(frame) + strlen(generator) - 1; i++)
    {
        j = 0;
        k = i;
        if (temp[k] >= generator[j])
        {
            for (j = 0, k = i; j < strlen(generator); j++, k++)
            {
                if (temp[k] == generator[j])
                    temp[k] = '0';
                else
                    temp[k] = '1';
            }
        }
    }
    for (i = strlen(frame), j = 0; i < strlen(frame) + strlen(generator) - 1; i++, j++)
        remainder[j] = temp[i];
    remainder[strlen(generator)-1] = '\0';
    printf("\nREMAINDER : %s", remainder);
    for (i = 0; i < strlen(generator) - 1; i++)
    {
        if (remainder[i] != '0')
        {
            flag = 1;
            break;
        }
    }
    if (!flag)
        printf("\nRECEIVED MESSAGE IS CORRECT");
    else
        printf("\nRECEIVED MESSAGE IS INCORRECT");
    return 0;
}