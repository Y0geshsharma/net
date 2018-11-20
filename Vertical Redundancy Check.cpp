#include<bits/stdc++.h>
using namespace std;
int main()
{
    int len, i, n0, n1;
    printf("SENDER SIDE\nENTER THE LENGTH OF DATA : ");
    scanf("%d", &len);
    char sender_data[len];
    printf("ENTER THE DATA : ");
    scanf("%s", sender_data);
    len = strlen(sender_data);
    sender_data[len] = '\0';
    char sender_codeword[len+1], receiver_codeword[len+1], codeword[len+2], receiver_data[len];
    sender_codeword[len+1] = '\0';
    receiver_codeword[len+1] = '\0';
    codeword[len+2] = '\0';
    receiver_data[len] = '\0';
    n0 = 0;
    n1 = 0;
    for (i = 0; i < len; i++)
    {
        sender_codeword[i] = sender_data[i];
        if (sender_data[i] == '0')
            n0++;
        else if (sender_data[i] == '1')
            n1++;
    }
    if (n1 % 2 != 0)
        sender_codeword[len] = '1';
    else
        sender_codeword[len] = '0';
    printf("CODEWORD : %s\n", sender_codeword);
    printf("RECEIVER\n");
    printf("ENTER THE RECEIVED CODEWORD : ");
    scanf("%s", receiver_codeword);
    n0 = 0;
    n1 = 0;
    for (i = 0; i < len+1; i++)
    {
        codeword[i] = receiver_codeword[i];
        if (receiver_codeword[i] == '0')
            n0++;
        else if (receiver_codeword[i] == '1')
            n1++;
    }
    if (n1 % 2 != 0)
    {
        codeword[len+1] = '1';
        printf("THE RECEIVED DATA IS INCORRECT");
    }
    else
    {
        codeword[len+1] = '0';
        for(i = 0; i < len; i++)
        {
            receiver_data[i] = codeword[i];
        }
        printf("THE RECEIVED DATA IS CORRECT\nTHE DATA RECEIVED IS : %s", receiver_data);
    }
    return 0;
}