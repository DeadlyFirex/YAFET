#include "core.h"

using namespace std;
using namespace CryptoPP;

using namespace core;

bool encryptFile(const std::string& inputFilePath, const std::string& outputFilePath, const std::string& key) {
    // Read the input file
    std::ifstream inputFile(inputFilePath, std::ios::binary);
    if (!inputFile.is_open()) {
        std::cerr << "Error opening input file: " << inputFilePath << std::endl;
        return false;
    }

    // Prepare the output file
    std::ofstream outputFile(outputFilePath, std::ios::binary);
    if (!outputFile.is_open()) {
        std::cerr << "Error opening output file: " << outputFilePath << std::endl;
        return false;
    }

    // Set up AES encryption
    CryptoPP::AES::Encryption aesEncryption((CryptoPP::byte*)key.data(), CryptoPP::AES::DEFAULT_KEYLENGTH);
    CryptoPP::CBC_Mode_ExternalCipher::Encryption cbcEncryption(aesEncryption, (CryptoPP::byte*)key.data());

    // Use Crypto++ filters for encryption
    CryptoPP::FileSource fileSource(inputFile, true,
                                    new CryptoPP::StreamTransformationFilter(cbcEncryption,
                                                                             new CryptoPP::FileSink(outputFile)
                                    )
    );

    return true;
}

bool decryptFile(const std::string& inputFilePath, const std::string& outputFilePath, const std::string& key) {
    // Read the input file
    std::ifstream inputFile(inputFilePath, std::ios::binary);
    if (!inputFile.is_open()) {
        std::cerr << "Error opening input file: " << inputFilePath << std::endl;
        return false;
    }

    // Prepare the output file
    std::ofstream outputFile(outputFilePath, std::ios::binary);
    if (!outputFile.is_open()) {
        std::cerr << "Error opening output file: " << outputFilePath << std::endl;
        return false;
    }

    // Set up AES encryption
    CryptoPP::AES::Encryption aesEncryption((CryptoPP::byte*)key.data(), CryptoPP::AES::DEFAULT_KEYLENGTH);
    CryptoPP::CBC_Mode_ExternalCipher::Decryption cbcDecryption(aesEncryption, (CryptoPP::byte*)key.data());

    // Use Crypto++ filters for encryption
    CryptoPP::FileSource fileSource(inputFile, true,
                                    new CryptoPP::StreamTransformationFilter(cbcDecryption,
                                                                             new CryptoPP::FileSink(outputFile)
                                    )
    );

    return true;
}
