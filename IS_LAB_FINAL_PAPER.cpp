#include <iostream>
#include <iomanip>
#include <vector>
#include <array>
#include <cstring>
#include <cstdint>

using namespace std;

// Define uint8_t as unsigned char if it is not defined
#ifndef uint8_t
typedef unsigned char uint8_t;
#endif

// AES S-box
const uint8_t S_BOX[16][16] = {
    {0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76},
    {0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0},
    {0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15},
    {0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75},
    {0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84},
    {0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf},
    {0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8},
    {0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2},
    {0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73},
    {0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb},
    {0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79},
    {0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08},
    {0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a},
    {0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e},
    {0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf},
    {0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16}
};
const uint8_t INV_S_BOX[16][16] = {
    {0x52, 0x09, 0x6a, 0xd5, 0x30, 0x36, 0xa5, 0x38, 0xbf, 0x40, 0xa3, 0x9e, 0x81, 0xf3, 0xd7, 0xfb},
    {0x7c, 0xe3, 0x39, 0x82, 0x9b, 0x2f, 0xff, 0x87, 0x34, 0x8e, 0x43, 0x44, 0xc4, 0x9c, 0x54, 0x7b},
    {0x94, 0x32, 0xa6, 0xc2, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x7a, 0x11, 0x42, 0x10, 0x24, 0x8e},
    {0x8a, 0x43, 0x39, 0x9b, 0x2e, 0x27, 0xfb, 0xd0, 0x8b, 0x80, 0x84, 0x0b, 0x2f, 0x19, 0x56, 0x45},
    {0x1b, 0x34, 0x92, 0x3e, 0x72, 0x3d, 0x16, 0x78, 0x00, 0x07, 0xa2, 0x81, 0xb3, 0x92, 0xc9, 0x97},
    {0x5e, 0x63, 0x01, 0x84, 0x1b, 0x77, 0x6a, 0x11, 0x44, 0x45, 0x29, 0xe9, 0x9d, 0x0c, 0x70, 0xe7},
    {0xc3, 0x2b, 0x3d, 0x72, 0x71, 0xf5, 0x78, 0x43, 0x44, 0x06, 0x93, 0x31, 0xd3, 0xa3, 0x36, 0x8b},
    {0x6c, 0x23, 0x4d, 0x35, 0x37, 0x5c, 0xa5, 0x88, 0x5f, 0x0e, 0xa0, 0x4e, 0x51, 0x16, 0x58, 0x4a},
    {0x7d, 0x73, 0x4c, 0x56, 0x0f, 0xe8, 0x6d, 0x89, 0x6e, 0x80, 0x7a, 0x1e, 0xa8, 0x5b, 0x51, 0x9f},
    {0x1f, 0x1d, 0x97, 0x3c, 0x9f, 0xa8, 0x6b, 0x72, 0x4b, 0x5d, 0xd1, 0x21, 0x66, 0x8b, 0x7f, 0x75},
    {0x94, 0xc8, 0x77, 0x45, 0x01, 0x0b, 0x77, 0xf6, 0x08, 0x89, 0x0a, 0x71, 0x06, 0x8d, 0x9a, 0x0f}
};

// AES Rcon
const uint8_t RCON[10] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1B, 0x36};

// Function Prototypes
void KeyExpansion(const uint8_t* key, uint8_t roundKeys[11][4][4]);
void SubBytes(uint8_t state[4][4], const uint8_t S[16][16]);
void ShiftRows(uint8_t state[4][4]);
void InvShiftRows(uint8_t state[4][4]);
void MixColumns(uint8_t state[4][4]);
void InvMixColumns(uint8_t state[4][4]);
void AddRoundKey(uint8_t state[4][4], uint8_t roundKey[4][4]);
void PrintState(uint8_t state[4][4]);
void AES_Encrypt(uint8_t plaintext[16], uint8_t key[16], uint8_t ciphertext[16]);
void AES_Decrypt(uint8_t ciphertext[16], uint8_t key[16], uint8_t plaintext[16]);

uint8_t gf_mul(uint8_t x, uint8_t y) {
    if (y == 0x02) {
        return (x << 1) ^ (0x11B & -(x >> 7));
    } else if (y == 0x03) {
        return gf_mul(x, 0x02) ^ x;
    }
    return x;
}

// Key Expansion
// Key Expansion
void KeyExpansion(const uint8_t* key, uint8_t roundKeys[11][4][4]) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            roundKeys[0][i][j] = key[i + 4 * j];
        }
    }

    for (int round = 1; round < 11; ++round) {
        uint8_t temp[4];
        for (int i = 0; i < 4; ++i) {
            temp[i] = roundKeys[round - 1][i][3];
        }

        // Rotate and SubBytes
        uint8_t last = temp[0];
        for (int i = 0; i < 3; ++i) {
            temp[i] = temp[i + 1];
        }
        temp[3] = last;

        for (int i = 0; i < 4; ++i) {
            uint8_t row = temp[i] >> 4;
            uint8_t col = temp[i] & 0x0F;
            temp[i] = S_BOX[row][col];
        }

        temp[0] ^= RCON[round - 1];

        for (int i = 0; i < 4; ++i) {
            roundKeys[round][i][0] = roundKeys[round - 1][i][0] ^ temp[i];
        }
        for (int col = 1; col < 4; ++col) {
            for (int i = 0; i < 4; ++i) {
                roundKeys[round][i][col] = roundKeys[round][i][col - 1] ^ roundKeys[round - 1][i][col];
            }
        }
    }
}


// SubBytes
void SubBytes(uint8_t state[4][4], const uint8_t S[16][16]) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            uint8_t row = state[i][j] >> 4;
            uint8_t col = state[i][j] & 0x0F;
            state[i][j] = S[row][col];
        }
    }
}

// AddRoundKey
void AddRoundKey(uint8_t state[4][4], uint8_t roundKey[4][4]) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            state[i][j] ^= roundKey[i][j];
        }
    }
}

// ShiftRows
void ShiftRows(uint8_t state[4][4]) {
    uint8_t temp;
    for (int i = 1; i < 4; ++i) {
        for (int j = 0; j < i; ++j) {
            temp = state[i][0];
            for (int k = 0; k < 3; ++k) {
                state[i][k] = state[i][k + 1];
            }
            state[i][3] = temp;
        }
    }
}

// InvShiftRows
void InvShiftRows(uint8_t state[4][4]) {
    uint8_t temp;
    for (int i = 1; i < 4; ++i) {
        for (int j = 0; j < i; ++j) {
            temp = state[i][3];
            for (int k = 3; k > 0; --k) {
                state[i][k] = state[i][k - 1];
            }
            state[i][0] = temp;
        }
    }
}

// MixColumns (AES)
void MixColumns(uint8_t state[4][4]) {
    uint8_t temp[4];
    for (int i = 0; i < 4; ++i) {
        temp[0] = state[0][i];
        temp[1] = state[1][i];
        temp[2] = state[2][i];
        temp[3] = state[3][i];

        state[0][i] = (gf_mul(temp[0], 0x02) ^ gf_mul(temp[1], 0x03) ^ temp[2] ^ temp[3]);
        state[1][i] = (temp[0] ^ gf_mul(temp[1], 0x02) ^ gf_mul(temp[2], 0x03) ^ temp[3]);
        state[2][i] = (temp[0] ^ temp[1] ^ gf_mul(temp[2], 0x02) ^ gf_mul(temp[3], 0x03));
        state[3][i] = (gf_mul(temp[0], 0x03) ^ temp[1] ^ temp[2] ^ gf_mul(temp[3], 0x02));
    }
}

// InvMixColumns (AES)
void InvMixColumns(uint8_t state[4][4]) {
    uint8_t temp[4];
    for (int i = 0; i < 4; ++i) {
        temp[0] = state[0][i];
        temp[1] = state[1][i];
        temp[2] = state[2][i];
        temp[3] = state[3][i];

        state[0][i] = (gf_mul(temp[0], 0x0E) ^ gf_mul(temp[1], 0x0B) ^ gf_mul(temp[2], 0x0D) ^ gf_mul(temp[3], 0x09));
        state[1][i] = (gf_mul(temp[0], 0x09) ^ gf_mul(temp[1], 0x0E) ^ gf_mul(temp[2], 0x0B) ^ gf_mul(temp[3], 0x0D));
        state[2][i] = (gf_mul(temp[0], 0x0D) ^ gf_mul(temp[1], 0x09) ^ gf_mul(temp[2], 0x0E) ^ gf_mul(temp[3], 0x0B));
        state[3][i] = (gf_mul(temp[0], 0x0B) ^ gf_mul(temp[1], 0x0D) ^ gf_mul(temp[2], 0x09) ^ gf_mul(temp[3], 0x0E));
    }
}

// AES Encryption
void AES_Encrypt(uint8_t plaintext[16], uint8_t key[16], uint8_t ciphertext[16]) {
    uint8_t state[4][4];
    uint8_t roundKeys[11][4][4];

    KeyExpansion(key, roundKeys);

    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            state[i][j] = plaintext[i + 4 * j];
    AddRoundKey(state, roundKeys[0]);

    for (int round = 1; round < 10; ++round) {
        SubBytes(state, S_BOX);
        ShiftRows(state);
        MixColumns(state);
        AddRoundKey(state, roundKeys[round]);
    }

    SubBytes(state, S_BOX);
    ShiftRows(state);
    AddRoundKey(state, roundKeys[10]);

    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            ciphertext[i + 4 * j] = state[i][j];
}

// AES Decryption
void AES_Decrypt(uint8_t ciphertext[16], uint8_t key[16], uint8_t plaintext[16]) {
    uint8_t state[4][4];
    uint8_t roundKeys[11][4][4];

    KeyExpansion(key, roundKeys);

    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            state[i][j] = ciphertext[i + 4 * j];
    AddRoundKey(state, roundKeys[10]);

    for (int round = 9; round > 0; --round) {
        InvShiftRows(state);
        SubBytes(state, INV_S_BOX);
        AddRoundKey(state, roundKeys[round]);
        InvMixColumns(state);
    }

    InvShiftRows(state);
    SubBytes(state, INV_S_BOX);
    AddRoundKey(state, roundKeys[0]);

    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            plaintext[i + 4 * j] = state[i][j];
}

// Main
int main() {
    // Test Case 1: "ConfidentialMsg" as plaintext
    uint8_t key[16] = {
        0x45, 0x6e, 0x63, 0x72, 0x79, 0x70, 0x74, 0x41,
        0x45, 0x53, 0x4b, 0x65, 0x79, 0x31, 0x32, 0x33
    };
    uint8_t plaintext[16] = {
        0x43, 0x6f, 0x6e, 0x66, 0x69, 0x64, 0x65, 0x6e,
        0x74, 0x69, 0x61, 0x6c, 0x4d, 0x73, 0x67, 0x00
    };
    uint8_t ciphertext[16];
    uint8_t decryptedtext[16];

    AES_Encrypt(plaintext, key, ciphertext);
    AES_Decrypt(ciphertext, key, decryptedtext);

    // Output ciphertext as hex
    cout << "Ciphertext: ";
    for (int i = 0; i < 16; ++i) {
        cout << hex << setw(2) << setfill('0') << (int)ciphertext[i] << " ";
    }
    cout << endl;

    // Output decrypted text as hex
    cout << "Decrypted text (hex): ";
    for (int i = 0; i < 16; ++i) {
        cout << hex << setw(2) << setfill('0') << (int)decryptedtext[i] << " ";
    }
    cout << endl;

    // Repeat for "EncryptAESKey12"
    uint8_t key2[16] = {
        0x45, 0x6e, 0x63, 0x72, 0x79, 0x70, 0x74, 0x41,
        0x45, 0x53, 0x4b, 0x65, 0x79, 0x31, 0x32, 0x33
    };
    uint8_t plaintext2[16] = {
        0x45, 0x6e, 0x63, 0x72, 0x79, 0x70, 0x74, 0x41,
        0x45, 0x53, 0x4b, 0x65, 0x79, 0x31, 0x32, 0x33
    };
    uint8_t ciphertext2[16];
    uint8_t decryptedtext2[16];

    AES_Encrypt(plaintext2, key2, ciphertext2);
    AES_Decrypt(ciphertext2, key2, decryptedtext2);

    // Output ciphertext as hex
    cout << "Ciphertext: ";
    for (int i = 0; i < 16; ++i) {
        cout << hex << setw(2) << setfill('0') << (int)ciphertext2[i] << " ";
    }
    cout << endl;

    // Output decrypted text as hex
    cout << "Decrypted text (hex): ";
    for (int i = 0; i < 16; ++i) {
        cout << hex << setw(2) << setfill('0') << (int)decryptedtext2[i] << " ";
    }
    cout << endl;

    return 0;
}
