#include "core.h"

using namespace std;
using namespace CryptoPP;

using namespace core;

std::ifstream getIFileStream(const char * inputFilePath) {
    std::ifstream inputFile(inputFilePath, std::ios::binary);
    if (!inputFile.is_open()) {
        throw std::runtime_error("Failure to open input file");
    }
    return inputFile;
}

std::ofstream getOFileStream(const char * inputFilePath) {
    std::ofstream outputFile(inputFilePath, std::ios::binary);
    if (!outputFile.is_open()) {
        throw std::runtime_error("Failure to open output file");
    }
    return outputFile;
}

bool encryptFileAes(std::ifstream& inputFile, std::ofstream& outputFile, const std::string& key) {
    CryptoPP::AES::Encryption aesEncryption((CryptoPP::byte*)key.data(), CryptoPP::AES::DEFAULT_KEYLENGTH);
    CryptoPP::ECB_Mode_ExternalCipher::Encryption ecbEncryption(aesEncryption, (CryptoPP::byte*)key.data());

    CryptoPP::FileSource fileSource(
            inputFile,true,
            new CryptoPP::StreamTransformationFilter(
                    ecbEncryption,
                    new CryptoPP::FileSink(outputFile)
            )
    );

    return true;
}

bool decryptFileAes(std::ifstream& inputFile, std::ofstream& outputFile, const std::string& key) {
    CryptoPP::AES::Decryption aesDecryption((CryptoPP::byte*)key.data(), CryptoPP::AES::DEFAULT_KEYLENGTH);
    CryptoPP::ECB_Mode_ExternalCipher::Decryption ecbDecryption(aesDecryption, (CryptoPP::byte*)key.data());

    CryptoPP::FileSource fileSource(
            inputFile, true,
            new CryptoPP::StreamTransformationFilter(
                    ecbDecryption,
                    new CryptoPP::FileSink(outputFile)
            )
    );

    return true;
}

bool encryptFileBlowfish(std::ifstream& inputFile, std::ofstream& outputFile, const std::string& key) {
    CryptoPP::Blowfish::Encryption blowfishEncryption((CryptoPP::byte*)key.data(), CryptoPP::Blowfish::DEFAULT_KEYLENGTH);
    CryptoPP::ECB_Mode_ExternalCipher::Encryption ecbEncryption(blowfishEncryption, (CryptoPP::byte*)key.data());

    CryptoPP::FileSource fileSource(
            inputFile,true,
            new CryptoPP::StreamTransformationFilter(
                    ecbEncryption,
                    new CryptoPP::FileSink(outputFile)
            )
    );
    return true;
}

bool decryptFileBlowfish(std::ifstream& inputFile, std::ofstream& outputFile, const std::string& key) {
    CryptoPP::Blowfish::Decryption blowfishDecryption((CryptoPP::byte*)key.data(), CryptoPP::Blowfish::DEFAULT_KEYLENGTH);
    CryptoPP::ECB_Mode_ExternalCipher::Decryption ecbDecryption(blowfishDecryption, (CryptoPP::byte*)key.data());

    CryptoPP::FileSource fileSource(
            inputFile, true,
            new CryptoPP::StreamTransformationFilter(
                    ecbDecryption,
                    new CryptoPP::FileSink(outputFile)
            )
    );

    return true;
}


