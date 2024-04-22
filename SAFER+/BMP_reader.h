#ifndef BMP_READER_H
#define BMP_READER_H

#include <vector>
#include <fstream>
#include <string>
class BMP {
private:
	std::vector<unsigned char> header;
	std::vector<unsigned char> dataBytes;
public:
	std::vector<unsigned char> bytes_from_image(const std::string & path);
	void setDataBytes(const std::vector<unsigned char>& data);
	void bytes_to_image(const std::string & path);
	void clearAll();
};

#endif