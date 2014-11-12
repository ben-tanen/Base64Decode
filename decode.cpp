#include <iostream>
#include <string>
#include <tgmath.h>

using namespace std;

string base64_2_text(string base64)
{
	string result;
	string bit_string;

	for (int i=0; i<base64.length(); i++){

		int ascii = base64[i];
		int index;

		if (ascii == 92) {
			i = i + 2;
			ascii = base64[i];
		}

		if (ascii > 64 && ascii < 91) {
			index = ascii - 65;
		} else if (ascii > 96 && ascii < 123) {
			index = ascii - 71;
		} else if (ascii > 47 && ascii < 58) {
			index = ascii + 4;
		} else if (ascii == 43) {
			index = 62;
		} else if (ascii == 47) {
			index = 63;
		}

		for (int j=5; j>=0; j--){
			int power = pow(2,j);
			if (index % power < index){
				bit_string = bit_string + "1";
				index = index % power;
			} else {
				bit_string = bit_string + "0";
			}
		}
	}

	string text;
	int num_char = ceil(bit_string.length() / 8.0);

	int sum = 0;
	for (int i=0;i<num_char*8;i++){
		if (i % 8 == 0 && i != 0) {
			text = text + char(sum);
			sum = 0;
		} 

		if (bit_string[i] == '1') {
			sum = sum + pow(2,7-(i%8));
		}
	}
	text = text + char(sum);

	return text;
}

int main(int argc, char const *argv[])
{
	string str;
	cin >> str;
	
	cout << base64_2_text(str) << endl;
	return 0;
}