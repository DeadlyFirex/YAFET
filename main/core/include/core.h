#include "file.h"

#include <cryptopp/cryptlib.h>
#include <cryptopp/files.h>
#include <cryptopp/aes.h>
#include <cryptopp/blowfish.h>
#include <cryptopp/modes.h>
#include <cryptopp/filters.h>

using namespace core;

std::ifstream getIFileStream(const char * inputFilePath);
std::ofstream getOFileStream(const char * inputFilePath);
bool encryptFileAes(std::ifstream& inputFile, std::ofstream& outputFile, const std::string& key);
bool decryptFileAes(std::ifstream& inputFile, std::ofstream& outputFile, const std::string& key);
