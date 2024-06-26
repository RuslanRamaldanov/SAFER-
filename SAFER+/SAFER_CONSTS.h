#ifndef SAFER_CONSTS_H
#define SAFER_CONSTS_H
const unsigned char M[16][16] = { {2, 2, 1, 1, 16, 8, 2, 1, 4, 2, 4, 2, 1, 1, 4, 4},
                         {1, 1,1, 1, 8, 4, 2, 1, 2, 1, 4, 2, 1, 1, 2, 2},
                         {1, 1, 4, 4, 2, 1, 4, 2, 4, 2, 16, 8, 2, 2, 1, 1},
                         {1, 1, 2, 2, 2, 1, 2, 1, 4, 2, 8, 4, 1, 1, 1, 1},
                         {4, 4, 2, 1, 4, 2,4, 2, 16, 8, 1, 1, 1, 1, 2, 2},
                         {2, 2, 2, 1, 2, 1, 4, 2, 8, 4, 1, 1, 1, 1, 1, 1},
                         {1, 1, 4, 2, 4, 2, 16, 8, 2, 1, 2, 2, 4, 4, 1, 1},
                         {1, 1, 2, 1, 4, 2, 8, 4, 2, 1, 1, 1, 2, 2, 1, 1},
                         {2, 1, 16, 8, 1, 1, 2, 2, 1, 1, 4, 4, 4, 2, 4, 2},
                         {2, 1, 8, 4, 1, 1, 1, 1, 1, 1, 2, 2, 4, 2, 2, 1},
                         {4, 2, 4, 2, 4, 4, 1, 1, 2, 2, 1, 1, 16, 8, 2, 1},
                         {2, 1, 4, 2, 2, 2, 1, 1, 1, 1, 1, 1, 8, 4, 2, 1},
                         {4, 2, 2, 2, 1, 1, 4, 4, 1, 1, 4, 2, 2, 1, 16, 8},
                         {4, 2, 1, 1, 1, 1, 2, 2, 1, 1, 2, 1, 2, 1, 8, 4},
                         {16, 8, 1, 1, 2, 2, 1, 1, 4, 4, 2, 1, 4, 2, 4, 2},
                         {8, 4, 1, 1, 1, 1, 1, 1, 2, 2, 2, 1, 2, 1, 4, 2}};

const char _M[16][16] = { {2, -2, 1, -2, 1, -1, 4, -8, 2, -4, 1, -1, 1, -2, 1, -1},
                          {-4, 4, -2, 4, -2, 2, -8, 16, -2, 4, -1, 1, -1, 2, -1, 1},
                          {1, -2, 1, -1, 2, -4, 1, -1, 1, -1, 1, -2, 2, -2, 4, -8},
                          {-2, 4, -2, 2, -2, 4, -1, 1, -1, 1, -1, 2, -4, 4, -8, 16},
                          {1, -1, 2, -4, 1, -1, 1, -2, 1, -2, 1, -1, 4, -8, 2, -2},
                          {-1, 1, -2, 4, -1, 1, -1, 2, -2, 4, -2, 2, -8, 16, -4, 4},
                          {2, -4, 1, -1, 1, -2, 1, -1, 2, -2, 4, -8, 1, -1, 1, -2},
                          {-2, 4, -1, 1, -1, 2, -1, 1, -4, 4, -8, 16, -2, 2, -2, 4},
                          {1, -1, 1, -2, 1, -1, 2, -4, 4, -8, 2, -2, 1, -2, 1, -1},
                          {-1, 1, -1, 2, -1, 1, -2, 4, -8, 16, -4, 4, -2, 4, -2, 2},
                          {1, -2, 1, -1, 4, -8, 2, -2, 1, -1, 1, -2, 1, -1, 2, -4},
                          {-1, 2, -1, 1, -8, 16, -4, 4, -2, 2, -2, 4, -1, 1, -2, 4},
                          {4, -8, 2, -2, 1, -2, 1, -1, 1, -2, 1, -1, 2, -4, 1, -1},
                          {-8, 16, -4, 4, -2, 4, -2, 2, -1, 2, -1, 1, -2, 4, -1, 1},
                          {1, -1, 4, -8, 2, -2, 1, -2, 1, -1, 2, -4, 1, -1, 1, -2},
                          {-2, 2, -8, 16, -4, 4, -2, 4, -1, 1, -2, 4, -1, 1, -1, 2}};

const unsigned char POW45[256] = { 0x01, 0x2d, 0xe2, 0x93, 0xbe, 0x45, 0x15, 0xae, 0x78, 0x03, 0x87, 0xa4, 0xb8, 0x38, 0xcf, 0x3f,
                                        0x08, 0x67, 0x09, 0x94, 0xeb, 0x26, 0xa8, 0x6b, 0xbd, 0x18, 0x34, 0x1b, 0xbb, 0xbf, 0x72, 0xf7,
                                        0x40, 0x35, 0x48, 0x9c, 0x51, 0x2f, 0x3b, 0x55, 0xe3, 0xc0, 0x9f, 0xd8, 0xd3, 0xf3, 0x8d, 0xb1,
                                        0xff, 0xa7, 0x3e, 0xdc, 0x86, 0x77, 0xd7, 0xa6, 0x11, 0xfb, 0xf4, 0xba, 0x92, 0x91, 0x64, 0x83,
                                        0xf1, 0x33, 0xef, 0xda, 0x2c, 0xb5, 0xb2, 0x2b, 0x88, 0xd1, 0x99, 0xcb, 0x8c, 0x84, 0x1d, 0x14,
                                        0x81, 0x97, 0x71, 0xca, 0x5f, 0xa3, 0x8b, 0x57, 0x3c, 0x82, 0xc4, 0x52, 0x5c, 0x1c, 0xe8, 0xa0,
                                        0x04, 0xb4, 0x85, 0x4a, 0xf6, 0x13, 0x54, 0xb6, 0xdf, 0x0c, 0x1a, 0x8e, 0xde, 0xe0, 0x39, 0xfc,
                                        0x20, 0x9b, 0x24, 0x4e, 0xa9, 0x98, 0x9e, 0xab, 0xf2, 0x60, 0xd0, 0x6c, 0xea, 0xfa, 0xc7, 0xd9,
                                        0x00, 0xd4, 0x1f, 0x6e, 0x43, 0xbc, 0xec, 0x53, 0x89, 0xfe, 0x7a, 0x5d, 0x49, 0xc9, 0x32, 0xc2,
                                        0xf9, 0x9a, 0xf8, 0x6d, 0x16, 0xdb, 0x59, 0x96, 0x44, 0xe9, 0xcd, 0xe6, 0x46, 0x42, 0x8f, 0x0a,
                                        0xc1, 0xcc, 0xb9, 0x65, 0xb0, 0xd2, 0xc6, 0xac, 0x1e, 0x41, 0x62, 0x29, 0x2e, 0x0e, 0x74, 0x50,
                                        0x02, 0x5a, 0xc3, 0x25, 0x7b, 0x8a, 0x2a, 0x5b, 0xf0, 0x06, 0x0d, 0x47, 0x6f, 0x70, 0x9d, 0x7e,
                                        0x10, 0xce, 0x12, 0x27, 0xd5, 0x4c, 0x4f, 0xd6, 0x79, 0x30, 0x68, 0x36, 0x75, 0x7d, 0xe4, 0xed,
                                        0x80, 0x6a, 0x90, 0x37, 0xa2, 0x5e, 0x76, 0xaa, 0xc5, 0x7f, 0x3d, 0xaf, 0xa5, 0xe5, 0x19, 0x61,
                                        0xfd, 0x4d, 0x7c, 0xb7, 0x0b, 0xee, 0xad, 0x4b, 0x22, 0xf5, 0xe7, 0x73, 0x23, 0x21, 0xc8, 0x05,
                                        0xe1, 0x66, 0xdd, 0xb3, 0x58, 0x69, 0x63, 0x56, 0x0f, 0xa1, 0x31, 0x95, 0x17, 0x07, 0x3a, 0x28};

const unsigned char LOG45[256] = { 0x80, 0x00, 0xb0, 0x09, 0x60, 0xef, 0xb9, 0xfd, 0x10, 0x12, 0x9f, 0xe4, 0x69, 0xba, 0xad, 0xf8,
                                        0xc0, 0x38, 0xc2, 0x65, 0x4f, 0x06, 0x94, 0xfc, 0x19, 0xde, 0x6a, 0x1b, 0x5d, 0x4e, 0xa8, 0x82,
                                        0x70, 0xed, 0xe8, 0xec, 0x72, 0xb3, 0x15, 0xc3, 0xff, 0xab, 0xb6, 0x47, 0x44, 0x01, 0xac, 0x25,
                                        0xc9, 0xfa, 0x8e, 0x41, 0x1a, 0x21, 0xcb, 0xd3, 0x0d, 0x6e, 0xfe, 0x26, 0x58, 0xda, 0x32, 0x0f,
                                        0x20, 0xa9, 0x9d, 0x84, 0x98, 0x05, 0x9c, 0xbb, 0x22, 0x8c, 0x63, 0xe7, 0xc5, 0xe1, 0x73, 0xc6,
                                        0xaf, 0x24, 0x5b, 0x87, 0x66, 0x27, 0xf7, 0x57, 0xf4, 0x96, 0xb1, 0xb7, 0x5c, 0x8b, 0xd5, 0x54,
                                        0x79, 0xdf, 0xaa, 0xf6, 0x3e, 0xa3, 0xf1, 0x11, 0xca, 0xf5, 0xd1, 0x17, 0x7b, 0x93, 0x83, 0xbc,
                                        0xbd, 0x52, 0x1e, 0xeb, 0xae, 0xcc, 0xd6, 0x35, 0x08, 0xc8, 0x8a, 0xb4, 0xe2, 0xcd, 0xbf, 0xd9,
                                        0xd0, 0x50, 0x59, 0x3f, 0x4d, 0x62, 0x34, 0x0a, 0x48, 0x88, 0xb5, 0x56, 0x4c, 0x2e, 0x6b, 0x9e,
                                        0xd2, 0x3d, 0x3c, 0x03, 0x13, 0xfb, 0x97, 0x51, 0x75, 0x4a, 0x91, 0x71, 0x23, 0xbe, 0x76, 0x2a,
                                        0x5f, 0xf9, 0xd4, 0x55, 0x0b, 0xdc, 0x37, 0x31, 0x16, 0x74, 0xd7, 0x77, 0xa7, 0xe6, 0x07, 0xdb,
                                        0xa4, 0x2f, 0x46, 0xf3, 0x61, 0x45, 0x67, 0xe3, 0x0c, 0xa2, 0x3b, 0x1c, 0x85, 0x18, 0x04, 0x1d,
                                        0x29, 0xa0, 0x8f, 0xb2, 0x5a, 0xd8, 0xa6, 0x7e, 0xee, 0x8d, 0x53, 0x4b, 0xa1, 0x9a, 0xc1, 0x0e,
                                        0x7a, 0x49, 0xa5, 0x2c, 0x81, 0xc4, 0xc7, 0x36, 0x2b, 0x7f, 0x43, 0x95, 0x33, 0xf2, 0x6c, 0x68,
                                        0x6d, 0xf0, 0x02, 0x28, 0xce, 0xdd, 0x9b, 0xea, 0x5e, 0x99, 0x7c, 0x14, 0x86, 0xcf, 0xe5, 0x42,
                                        0xb8, 0x40, 0x78, 0x2d, 0x3a, 0xe9, 0x64, 0x1f, 0x92, 0x90, 0x7d, 0x39, 0x6f, 0xe0, 0x89, 0x30};

const unsigned char B[16][16] = {{70,151,177,186,163,183,16,10,197,55,179,201,90,40,172,100},
                                {171,170,198,103,149,88,13,248,154,246,110,102,220,5,61},
                                {195,216,137,106,233,54,73,67,191,235,212,150,155,104,160},
                                {87,146,31,213,113,92,187,34,193,190,123,188,153,99,148},
                                {97,184,52,50,25,253,251,23,64,230,81,29,65,68,143},
                                {4,128,222,231,49,214,127,1,162,247,57,218,111,35,202},
                                {208,28,209,48,62,18,161,205,15,224,168,175,130,89,44 },
                                { 173,178,239,194,135,206,117,6,19,2,144,79,46,114,51 },
                                { 141,207,169,129,226,196,39,47,108,122,159,82,225,21,56 },
                                { 32,66,199,8,228,9,85,94,140,20,118,96,255,223,215 },
                                { 11,33,0,26,249,166,185,232,158,98,76,217,145,80,210 },
                                { 180,7,132,234,91,164,200,14,203,72,105,75,78,156,53 },
                                { 77,84,229,37,60,12,74,139,63,204,167,219,107,174,244 },
                                { 243,124,109,157,181,38,116,242,147,83,176,240,17,237,131 },
                                { 3,22,115,59,30,142,112,189,134,27,71,126,36,86,241 },
                                { 70,151,177,186,163,183,16,10,197,55,179,201,90,40,172 }};

#endif // !SAFER_CONSTS_H