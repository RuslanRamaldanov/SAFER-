#ifndef SAFER_H
#define SAFER_H
#include <vector>
#include <string>
#include "BMP_reader.h"
#include <map>
class SAFER_PLUS {
private:
	std::vector<std::vector<unsigned char>> keys;
	BMP image;
	unsigned char rounds;
	unsigned char key_lenght;
	std::map<int, int> bitChangeFreq;

	unsigned char cycle_shift(unsigned char byte);
	void xor_add(std::vector<unsigned char>& data, std::vector<unsigned char>& key);
	void nonlinear_lajer(std::vector<unsigned char> & data);
	void xor_add_reverse(std::vector<unsigned char>& data, std::vector<unsigned char>& key);
	void linear_lajer(std::vector<unsigned char> & data);
	void inv_xor_add(std::vector<unsigned char>& data, std::vector<unsigned char>& key);
	void inv_nonlinear_lajer(std::vector<unsigned char>& data);
	void inv_xor_add_reverse(std::vector<unsigned char>& data, std::vector<unsigned char>& key);
	void inv_linear_lajer(std::vector<unsigned char>& data);
	void generate_keys(std::vector<unsigned char> input_key);
	void get_text_blocks(std::string str, std::vector<std::vector<unsigned char>>& data_blocks);

	void restore_string(std::string& data);
	void xor_vectors(std::vector<unsigned char>& first, std::vector<unsigned char>& second);
	void string_to_vector(const std::string& str, std::vector<unsigned char>& vect);
	
public:
	SAFER_PLUS();
	std::string encrypt(const std::string & data, const std::string & key);

	std::string decrypt(const std::string & data, const std::string & key);

	std::string ofb_encrypt(const std::string & data, const std::string & key, const std::string& IV);

	std::string ofb_decrypt(const std::string & data, const std::string & key, const std::string& IV);

	void encrypt_image(const std::string& path, const std::string & key);

	void decrypt_image(const std::string& path, const std::string & key);

	void ofb_encrypt_image(const std::string& path, const std::string& key, const std::string& IV);

	void ofb_decrypt_image(const std::string& path, const std::string& key, const std::string& IV);

	void encrypt_block(std::vector<unsigned char>& input_text, std::vector<unsigned char> key);
	void decrypt_block(std::vector<unsigned char>& input_text, std::vector<unsigned char> key);
};

#endif // !SAFER_H
