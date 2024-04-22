#include <iostream>
#include "SAFER.h"
#include <vector>
#include "SAFER_CONSTS.h"
#include "BMP_reader.h"
#include <algorithm>
#include <map>
using namespace std;

void print_vector(const vector<unsigned char>& vect) {
	for (int i = 0; i < vect.size(); i++)
		cout << (int)vect[i] << " ";
	cout << endl << " ";
}
void get_bits(const vector<unsigned char>& vect, vector<unsigned char>& bits_from_text) {
	for (int i = 0; i < vect.size(); i++) {
		unsigned char byte = vect[i];
		int c = 0;
		while (c < 8) {
			bits_from_text.push_back(byte & 1);
			byte = byte >> 1;
			c += 1;
		}
	}
}
// AUTHOCORRELATION TEST //////////////////////////////////////////////////////
vector<unsigned char> reverse_half(const vector<unsigned char>& vect) {
	vector<unsigned char> result = vect;
	for (char i = 0; i < 8; i++) {
		unsigned char byte = result[i];
		byte = ~byte;
		result[i] = byte;
	}
	return result;
}

vector<unsigned char> reverse_even(const vector<unsigned char>& vect) {
	vector<unsigned char> result = vect;
	const unsigned char mask = 0xAA; //1010 1010
	for (char i = 0; i < result.size(); i++) {
		unsigned char byte = result[i];
		result[i] = (byte ^ mask);
	}
	return result;
}
int count_A(const vector<unsigned char>& vect, int n, int d) {
	int A = 0;
	vector<unsigned char> bits_from_text;
	get_bits(vect, bits_from_text);
	std::reverse(bits_from_text.begin(), bits_from_text.end());
	for (int i = 0; i < (n - d); i++)
		A += (bits_from_text[i] ^ bits_from_text[i + d]);
	return A;
}
double authocorrelation_test(const vector<unsigned char>& vect, int n, int d) {
	return 2 * (count_A(vect, n, d) - ((n - d) / 2)) / sqrt(n - d);
}

/////////////////////////////////////////////////////////////////////////////////

// SERIES TEST //////////////////////////////////////////////////////////////////
void count_series(map<int, int>& count_ones, map<int, int>& count_zeros, const vector<unsigned char>& text) {
	vector<unsigned char> bits_from_text;
	get_bits(text, bits_from_text);
	int curr_sequence = bits_from_text[0];
	int curr_length = 1;
	for (size_t i = 1; i <= bits_from_text.size(); i++) {
		if (i < bits_from_text.size() && bits_from_text[i] == bits_from_text[i - 1]) {
			curr_length++;
		}
		else {
			if (curr_sequence == 0) {
				count_zeros[curr_length]++;
			}
			else {
				count_ones[curr_length]++;
			}
			if (i < bits_from_text.size()) {
				curr_sequence = bits_from_text[i];
				curr_length = 1;
			}
		}
	}
}
double sum_of_series(map<int, int>& series, const int& n) {
	double e = 0;
	double sum = 0;
	int maxI = 0;
	int E = 0;
	for (map<int, int>::iterator it = series.begin(); it != series.end(); it++) {
		e = (n - it->first + 3) / pow(2, (it->first + 2));
		if (e >= 5)
			sum += (pow(it->second, 2)) / e;
		if ((e >= 5) & (maxI < it->first)) {
			maxI = it->first;
			E = e;
		}

	}
	cout << "<><><>" << endl;
	cout << maxI << " " << E << endl;
	return sum;
}
////////////////////////////////////////////////////////////////////////////////////////////////

// FREQ TEST ///////////////////////////////////////////////////////////////////////////////////
double freq_test(const vector<unsigned char> text, const int& n) {
	vector<unsigned char> bits_from_text;
	get_bits(text, bits_from_text);
	int ones = 0;
	int zeros = 0;
	for (int i = 0; i < bits_from_text.size(); i++) {
		if (bits_from_text[i] == 0)
			ones += 1;
		else
			zeros += 1;
	}
	return pow(zeros - ones, 2) / n;
}
int main()
{
	SAFER_PLUS safer;
	vector<unsigned char> plain_text = { 149, 200, 212, 42, 49, 50, 51, 32, 198, 192, 100, 89, 98, 99, 15, 16 };
	vector<unsigned char> key = { 'a', 'b', 'c', '1', '5', 's', 's', '0', '!', '#', '@', 'g', ']', '[', '}', '{' };

	vector<unsigned char> first = reverse_half(plain_text);
	std::reverse(plain_text.begin(), plain_text.end());
	vector<unsigned char> second = reverse_even(plain_text);
	std::reverse(plain_text.begin(), plain_text.end());

	std::map<int, int> count_ones;
	std::map<int, int> count_zeros;

	size_t number_of_bits = 128;
	size_t d = number_of_bits / 2;

	safer.encrypt_block(first, key);
	safer.encrypt_block(second, key);

	cout << "AUTHOCORELLATION TEST FOR FIRST INPUT:" << endl;
	for (int i = 1; i <= d; i++) {
		cout << authocorrelation_test(first, number_of_bits, i) << " ";
		if (i % 8 == 0)
			cout << endl;
	}
	cout << endl;
	cout << "AUTHOCORELLATION TEST FOR SECOND INPUT:" << endl;
	for (int i = 1; i <= d; i++) {
		cout << authocorrelation_test(second, number_of_bits, i) << " ";
		if (i % 8 == 0)
			cout << endl;
	}
	cout << endl;

	cout << "SERIES TEST FOR FIRST INPUT:" << endl;
	count_series(count_ones, count_zeros, first);
	cout << sum_of_series(count_ones, number_of_bits) + sum_of_series(count_zeros, number_of_bits) << endl;
	cout << endl;
	count_ones.clear();
	count_zeros.clear();
	cout << "SERIES TEST FOR SECOND INPUT:" << endl;
	count_series(count_ones, count_zeros, second);
	cout << sum_of_series(count_ones, number_of_bits) + sum_of_series(count_zeros, number_of_bits) << endl;
	cout << endl;
	cout << "FREQ TEST FOR FIRST INPUT:" << endl;
	cout << freq_test(first, number_of_bits) << endl;
	cout << "FREQ TEST FOR SECCOND INPUT:" << endl;
	cout << freq_test(second, number_of_bits) << endl;
}