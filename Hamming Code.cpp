#include<bits/stdc++.h>
using namespace std;
char exor(char a, char b)
{
	if (a == b)
		return '0';
	else
		return '1';
}
int main()
{
	int error_bit;
	char sender_data[8], parity[4], receiver_data[8];
	int i, j;
	cout << "ENTER THE DATA OF 8 BITS : ";
	cin >> sender_data;
	sender_data[8] = '\0';
	char sender_codeword[12], receiver_codeword[12];
	for (i = 0; i < 12; i++)
	{
		sender_codeword[i] = '0';
	}
	sender_codeword[0] = 'p';
	sender_codeword[1] = 'q';
	sender_codeword[3] = 'r';
	sender_codeword[7] = 's';
	for (i = 0, j = 0; i < 12; i++)
	{
		if (sender_codeword[i] == '0') {
			sender_codeword[i] = sender_data[j];
			j++;
		}
	}
	sender_codeword[0] = exor(exor(exor(exor(sender_codeword[2], sender_codeword[4]), sender_codeword[6]), sender_codeword[8]), sender_codeword[10]);
	sender_codeword[1] = exor(exor(exor(exor(sender_codeword[2], sender_codeword[5]), sender_codeword[6]), sender_codeword[9]), sender_codeword[10]);
	sender_codeword[3] = exor(exor(exor(sender_codeword[4], sender_codeword[5]), sender_codeword[6]), sender_codeword[11]);
	sender_codeword[7] = exor(exor(exor(sender_codeword[8], sender_codeword[9]), sender_codeword[10]), sender_codeword[11]);
	sender_codeword[12] = '\0';
	cout << "SENDER CODEWORD : " << sender_codeword << endl;
	cout << "ENTER THE RECEIVED CODEWORD : ";
	cin >> receiver_codeword;
	receiver_codeword[12] = '\0';
	parity[3] = exor(exor(exor(exor(exor(receiver_codeword[0], receiver_codeword[2]), receiver_codeword[4]), receiver_codeword[6]), receiver_codeword[8]), receiver_codeword[10]);
	parity[2] = exor(exor(exor(exor(exor(receiver_codeword[1], receiver_codeword[2]), receiver_codeword[5]), receiver_codeword[6]), receiver_codeword[9]), receiver_codeword[10]);
	parity[1] = exor(exor(exor(exor(receiver_codeword[3], receiver_codeword[4]), receiver_codeword[5]), receiver_codeword[6]), receiver_codeword[11]);
	parity[0] = exor(exor(exor(exor(receiver_codeword[7], receiver_codeword[8]), receiver_codeword[9]), receiver_codeword[10]), receiver_codeword[11]);
	parity[4] = '\0';
	cout << parity << endl;
	error_bit = 8 * (parity[0] - 48) + 4 * (parity[1] - 48) + 2 * (parity[2] - 48) + 1 * (parity[3] - 48);
	cout << error_bit << endl;
	if (error_bit == 0)
		cout << "THERE IS NO ERROR IN RECEIVED CODEWORD";
	else
	{
		if (receiver_codeword[error_bit - 1] == '0')
			receiver_codeword[error_bit - 1] = '1';
		else
			receiver_codeword[error_bit - 1] = '0';
	}
	cout << "CORRECTED CODEWORD : " << receiver_codeword << endl;
	for (i = 0, j = 0; i < 12; i++)
	{
		if (i != 0 && i != 1 && i != 3 && i != 7)
		{
			receiver_data[j] = receiver_codeword[i];
			j++;
		}
	}
	receiver_data[8] = '\0';
	cout << "CORRECTED DATA ON RECEIVER SIDE : " << receiver_data << endl;
	return 0;
}
