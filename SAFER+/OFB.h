#ifndef OFB_H
#define OFB_H

#include "SAFER.h"

class OFB {
private:
    SAFER_PLUS * algo;
    std::string const_IV;
    uint8_t blocksize;
    std::string pkcs5(const std::string& data, const unsigned int& blocksize);
    std::string xor_strings(const std::string& str1, const std::string& str2);


//}

public:
    OFB(SAFER_PLUS* instance, const std::string& iv = "");
    std::string encrypt(const std::string& data);
    std::string decrypt(const std::string& data);
};

#endif