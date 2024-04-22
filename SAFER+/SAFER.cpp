#include "SAFER.h"
#include "SAFER_CONSTS.h"
#include <iostream>
#include <string>

void SAFER_PLUS::generate_keys(std::vector<unsigned char> input_key) {
	if (input_key.size() == 16) {
		keys.push_back(input_key);
		unsigned char buff = 0;
		int it = 1;
		std::vector<unsigned char> key_reg = input_key;
		for (int i = 0; i < key_reg.size(); i++) {
			buff ^= key_reg[i];
		}
		key_reg.push_back(buff);
		//------------------
		int iteration = 1;
		for (int i = 0; i < key_reg.size(); i++) {
			key_reg[i] = cycle_shift(key_reg[i]);
		}
		std::vector<unsigned char> round_key;

		while (iteration != 16) {
			while(true) {
				round_key.push_back(key_reg[it]);
				if (round_key.size() == 16)
					break;
				it = (it + 1) % 16;
			}
			for (int i = 0; i < 15; i++) {
				for (int j = 0; j < 16; j++) {
					round_key[i] = (round_key[i] + B[i + 1][j]) % 256;
				}
			}
			keys.push_back(round_key);
			round_key.clear();
			iteration += 1;
		}
	}
}

SAFER_PLUS::SAFER_PLUS() {
	rounds = 8;
	key_lenght = 16;
}

void SAFER_PLUS::xor_vectors(std::vector<unsigned char> & first, std::vector<unsigned char>& second) {
	if (first.size() == second.size()) {
		for (int i = 0; i < 16; i++) {
			first[i] = first[i] ^ second[i];
		}
	}
	else {
		std::cout << "asd" << std::endl;
	}
}

void SAFER_PLUS::string_to_vector(const std::string& str, std::vector<unsigned char>& vect)
{
	for (int i = 0; i < str.length(); i++) {
		vect.push_back(str[i]);
	}
}

unsigned char SAFER_PLUS::cycle_shift(unsigned char byte) {
	return (byte << 3) | (byte >> (8 - 3));
}

void SAFER_PLUS::xor_add(std::vector<unsigned char>& data, std::vector<unsigned char>& key) {
	data[0] ^= key[0];
	data[3] ^= key[3];
	data[4] ^= key[4];
	data[7] ^= key[7];
	data[8] ^= key[8];
	data[11] ^= key[11];
	data[12] ^= key[12];
	data[15] ^= key[15];

	data[1] = (data[1] + key[1]);
	data[2] = (data[2] + key[2]);
	data[5] = (data[5] + key[5]);
	data[6] = (data[6] + key[6]);
	data[9] = (data[9] + key[9]);
	data[10] = (data[10] + key[10]);
	data[13] = (data[13] + key[13]);
	data[14] = (data[14] + key[14]);
}

void SAFER_PLUS::inv_xor_add(std::vector<unsigned char>& data, std::vector<unsigned char>& key) {
	data[0] ^= key[0];
	data[3] ^= key[3];
	data[4] ^= key[4];
	data[7] ^= key[7];
	data[8] ^= key[8];
	data[11] ^= key[11];
	data[12] ^= key[12];
	data[15] ^= key[15];

	data[1] = (data[1] - key[1]);
	data[2] = (data[2] - key[2]);
	data[5] = (data[5] - key[5]);
	data[6] = (data[6] - key[6]);
	data[9] = (data[9] - key[9]);
	data[10] = (data[10] - key[10]);
	data[13] = (data[13] - key[13]);
	data[14] = (data[14] - key[14]);
}

void SAFER_PLUS::nonlinear_lajer(std::vector<unsigned char> & data) {
	data[0] = POW45[data[0]];
	data[3] = POW45[data[3]];
	data[4] = POW45[data[4]];
	data[7] = POW45[data[7]];
	data[8] = POW45[data[8]];
	data[11] = POW45[data[11]];
	data[12] = POW45[data[12]];
	data[15] = POW45[data[15]];

	data[1] = LOG45[data[1]];
	data[2] = LOG45[data[2]];
	data[5] = LOG45[data[5]];
	data[6] = LOG45[data[6]];
	data[9] = LOG45[data[9]];
	data[10] = LOG45[data[10]];
	data[13] = LOG45[data[13]];
	data[14] = LOG45[data[14]];
}

void SAFER_PLUS::inv_nonlinear_lajer(std::vector<unsigned char>& data) {
	data[0] = LOG45[data[0]];
	data[3] = LOG45[data[3]];
	data[4] = LOG45[data[4]];
	data[7] = LOG45[data[7]];
	data[8] = LOG45[data[8]];
	data[11] = LOG45[data[11]];
	data[12] = LOG45[data[12]];
	data[15] = LOG45[data[15]];

	data[1] = POW45[data[1]];
	data[2] = POW45[data[2]];
	data[5] = POW45[data[5]];
	data[6] = POW45[data[6]];
	data[9] = POW45[data[9]];
	data[10] = POW45[data[10]];
	data[13] = POW45[data[13]];
	data[14] = POW45[data[14]];
}

void SAFER_PLUS::xor_add_reverse(std::vector<unsigned char>& data, std::vector<unsigned char>& key) {
	data[1] ^= key[1];
	data[2] ^= key[2];
	data[5] ^= key[5];
	data[6] ^= key[6];
	data[9] ^= key[9];
	data[10] ^= key[10];
	data[13] ^= key[13];
	data[14] ^= key[14];

	data[0] = (key[0] + data[0]);
	data[3] = (key[3] + data[3]);
	data[4] = (key[4] + data[4]);
	data[7] = (key[7] + data[7]);
	data[8] = (key[8] + data[8]);
	data[11] = (key[11] + data[11]);
	data[12] = (key[12] + data[12]);
	data[15] = (key[15] + data[15]);
}

void SAFER_PLUS::inv_xor_add_reverse(std::vector<unsigned char>& data, std::vector<unsigned char>& key) {
	data[1] ^= key[1];
	data[2] ^= key[2];
	data[5] ^= key[5];
	data[6] ^= key[6];
	data[9] ^= key[9];
	data[10] ^= key[10];
	data[13] ^= key[13];
	data[14] ^= key[14];

	data[0] = data[0] - key[0];
	data[3] = data[3] - key[3];
	data[4] = data[4] - key[4];
	data[7] = data[7] - key[7];
	data[8] = data[8] - key[8];
	data[11] = data[11] - key[11];
	data[12] = data[12] - key[12];
	data[15] = data[15] - key[15];
}

void SAFER_PLUS::linear_lajer(std::vector<unsigned char> & data) {
	std::vector<unsigned char> tmp(16,0);
	if (data.size() == 16) {
		for (int i = 0; i < 16; i++) {
			for (int j = 0; j < 16; j++) {
				tmp[i] += (M[i][j] * data[j]);////////////////////
			}
		}
		data = tmp;
	}
}

void SAFER_PLUS::inv_linear_lajer(std::vector<unsigned char> & data) {
	std::vector<unsigned char> tmp(16, 0);
	if (data.size() == 16) {
		for (int i = 0; i < 16; i++) {
			for (int j = 0; j < 16; j++) {
				tmp[i] += (_M[i][j] * data[j]);/////////////////////
			}
		}
		data = tmp;
	}
}

void getBits(const std::vector<unsigned char>& vect, std::vector<unsigned char>& bits_from_text) {
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


void SAFER_PLUS::encrypt_block(std::vector<unsigned char> & input_text, std::vector<unsigned char> key) {

	std::vector<unsigned char> text_before;
	getBits(input_text, text_before);

	if (key.size() == 16) {
		generate_keys(key);
		int iteration = 1;
		while (iteration-1 != rounds) {
			try {
				std::vector<unsigned char> round_key = keys[iteration * 2 - 2];
				xor_add(input_text, round_key);
				nonlinear_lajer(input_text);
				round_key = keys[iteration * 2 - 1];
				xor_add_reverse(input_text, round_key);
				linear_lajer(input_text);
				iteration += 1;

				std::vector<unsigned char> text_after;
				getBits(input_text, text_after);
				for (int i = 0; i < text_after.size(); i++) {
					if (text_after[i] == text_before[i]) {
						bitChangeFreq[i] += 1;
					}
				}
			}
			catch (int th) {
				
			}
		}
	}
	else {
		std::cout << "Key lenght != 16" << std::endl;
	}
	for (int i = 0; i < input_text.size() * 8; i++) {

	}
	for (std::map<int, int>::iterator it = bitChangeFreq.begin(); it != bitChangeFreq.end(); it++) {
		std::cout << it->second << std::endl;
	}
	std::cout << "------------------------" << std::endl;
	bitChangeFreq.clear();

}

void SAFER_PLUS::decrypt_block(std::vector<unsigned char>& input_text, std::vector<unsigned char> key) { 
	keys.clear();
	if (key.size() == 16) {
		generate_keys(key);
		int iteration = rounds;
		while (iteration != 0) {
			try {
				inv_linear_lajer(input_text);
				std::vector<unsigned char> round_key = keys[iteration * 2 - 1];
				inv_xor_add_reverse(input_text, round_key);
				round_key = keys[iteration * 2 - 2];
				inv_nonlinear_lajer(input_text);
				inv_xor_add(input_text, round_key);
				iteration -= 1;
			}
			catch (int th) {

			}
		}
	}
	else {
		std::cout << "Key lenght != 16" << std::endl;
	}
}

void SAFER_PLUS::get_text_blocks(std::string str, std::vector<std::vector<unsigned char>> & data_blocks) {
	std::vector<unsigned char> tmp;
	while (str.length() % 16 != 0)
		str += 1;
	for (int i = 0; i < str.length(); i++) {
		tmp.push_back(str[i]);
		if ((i + 1) % 16 == 0) {
			data_blocks.push_back(tmp);
			tmp.clear();
		}
	}
}

std::string SAFER_PLUS::encrypt(const std::string& data, const std::string& key) {
	std::vector<std::vector<unsigned char>> data_blocks;
	std::vector<unsigned char> first_key;
	get_text_blocks(data, data_blocks);
	for (int i = 0; i < 16; i++) {
		first_key.push_back(key[i]);
	}
	for (int i = 0; i < data_blocks.size(); i++) {
		encrypt_block(data_blocks[i], first_key);
	}
	std::string output = "";
	for (int i = 0; i < data_blocks.size(); i++) {
		for (int j = 0; j < data_blocks[i].size(); j++) {
			output += data_blocks[i][j];
		}
	}
	return output;
}

std::string SAFER_PLUS::decrypt(const std::string& data, const std::string& key) {
	std::vector<std::vector<unsigned char>> data_blocks;
	std::vector<unsigned char> first_key;
	get_text_blocks(data, data_blocks);
	for (int i = 0; i < 16; i++) {
		first_key.push_back(key[i]);
	}
	int counter = 0;
	for (int i = 0; i < data_blocks.size(); i++) {
		decrypt_block(data_blocks[i], first_key);
		counter += 1;
	}
	std::string output = "";
	for (int i = 0; i < data_blocks.size(); i++) {
		for (int j = 0; j < data_blocks[i].size(); j++) {
			output += data_blocks[i][j];
		}
	}
	restore_string(output);
	return output;
}

void SAFER_PLUS::restore_string(std::string& data) {
	std::string tmp = data;
	for (int i = data.length() - 1; i > 0; i--) {
		if (tmp[i] == 1)
			tmp.erase(i, 1);
		else {
			break;
		}
	}
	data = tmp;
}

void SAFER_PLUS::encrypt_image(const std::string& path, const std::string & key) {
	std::vector<unsigned char> data = image.bytes_from_image(path);
	std::string tmp = "";
	for (int i = 0; i < data.size(); i++) {
		tmp += data[i];
	}
	data.clear();
	tmp = encrypt(tmp, key);
	////
	//tmp[200] = 0;
	////
	for (int i = 0; i < tmp.length(); i++) {
		data.push_back(tmp[i]);
	}
	image.setDataBytes(data);
	image.bytes_to_image(path);
	data.clear();
	tmp = "";
}

void SAFER_PLUS::decrypt_image(const std::string & path, const std::string & key) {
	std::vector<unsigned char> data = image.bytes_from_image(path);
	std::string tmp = "";
	for (int i = 0; i < data.size(); i++) {
		tmp += data[i];
	}
	data.clear();
	tmp = decrypt(tmp, key);

	for (int i = 0; i < tmp.length(); i++) {
		data.push_back(tmp[i]);
	}
	image.setDataBytes(data);
	image.bytes_to_image(path);
	data.clear();
	tmp = "";
}


std::string SAFER_PLUS::ofb_encrypt(const std::string & data, const std::string & key, const std::string & IV)
{
	std::string output = "";
	std::vector<std::vector<unsigned char>> data_blocks;
	std::vector<unsigned char> tmp_iv;
	std::vector<unsigned char> first_key;

	get_text_blocks(data, data_blocks);
	string_to_vector(IV, tmp_iv);

	for (int i = 0; i < 16; i++) {
		first_key.push_back(key[i]);
	}

	for (int i = 0; i < data_blocks.size(); i++) {
		encrypt_block(tmp_iv, first_key);
		xor_vectors(data_blocks[i], tmp_iv);
	}

	for (int i = 0; i < data_blocks.size(); i++) {
		for (int j = 0; j < data_blocks[i].size(); j++) {
			output += data_blocks[i][j];
		}
	}
	return output;
}

std::string SAFER_PLUS::ofb_decrypt(const std::string& data, const std::string& key, const std::string & IV)
{
	std::string output = ofb_encrypt(data, key, IV);
    restore_string(output);
	return output;
}

void SAFER_PLUS::ofb_encrypt_image(const std::string& path, const std::string& key, const std::string& IV) {
	std::vector<unsigned char> data = image.bytes_from_image(path);
	std::string tmp = "";
	for (int i = 0; i < data.size(); i++) {
		tmp += data[i];
	}
	data.clear();
	tmp = ofb_encrypt(tmp, key, IV);
	//////------------------///////
	//	tmp[200] = 0;
	////---------------//////////
	for (int i = 0; i < tmp.length(); i++) {
		data.push_back(tmp[i]);
	}
	image.setDataBytes(data);
	image.bytes_to_image(path);
	data.clear();
	tmp = "";
}

void SAFER_PLUS::ofb_decrypt_image(const std::string& path, const std::string& key, const std::string& IV) {
	std::vector<unsigned char> data = image.bytes_from_image(path);
	std::string tmp = "";
	for (int i = 0; i < data.size(); i++) {
		tmp += data[i];
	}
	data.clear();
	tmp = ofb_decrypt(tmp, key, IV);
	for (int i = 0; i < tmp.length(); i++) {
		data.push_back(tmp[i]);
	}
	image.setDataBytes(data);
	image.bytes_to_image(path);
	data.clear();
	tmp = "";
}