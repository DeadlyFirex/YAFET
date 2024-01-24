#include "file.h"

#include <cryptopp/cryptlib.h>
#include <cryptopp/files.h>
#include <cryptopp/aes.h>
#include <cryptopp/modes.h>
#include <cryptopp/filters.h>

using namespace core;

bool encryptFile(const std::string& inputFilePath, const std::string& outputFilePath, const std::string& key);
bool decryptFile(const std::string& inputFilePath, const std::string& outputFilePath, const std::string& key);
