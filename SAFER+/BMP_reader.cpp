#include "BMP_reader.h"
#include <iostream>
#include <string>

std::vector<unsigned char> BMP::bytes_from_image(const std::string & path) {
	std::ifstream inputFile(path, std::ios::binary);
	if (!inputFile) {
		std::cout << "Cant open file" << std::endl;
		return dataBytes;
	}
	const size_t headerSize = 54;
	header.resize(headerSize);
	inputFile.read(reinterpret_cast<char*>(header.data()), headerSize);

	inputFile.seekg(0, std::ios::end);
	const size_t fileSize = inputFile.tellg();
	const size_t dataSize = fileSize - headerSize;
	
	dataBytes.resize(dataSize);
	inputFile.seekg(headerSize);
	inputFile.read(reinterpret_cast<char*>(dataBytes.data()), dataSize);
	inputFile.close();
	return dataBytes;
}

void BMP::bytes_to_image(const std::string& path) {
	std::vector<unsigned char> combine(header);
	combine.insert(combine.end(), dataBytes.begin(), dataBytes.end());
	std::ofstream file(path, std::ios::binary);
	if (file) {
		file.write(reinterpret_cast<char*>(combine.data()), combine.size());
		file.close();
	}
	dataBytes.clear();
	header.clear();
	file.close();
}

void BMP::clearAll()
{
	dataBytes.clear();
	header.clear();
}

void BMP::setDataBytes(const std::vector<unsigned char>& data) {
	dataBytes.clear();
	for (int i = 0; i < data.size(); i++) {
		dataBytes.push_back(data[i]);
	}
}