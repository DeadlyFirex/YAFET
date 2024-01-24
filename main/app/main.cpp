#include <iostream>
#include "core.h"

int main() {
    std::string encryptionKey = "0123456789abcdef";

    // Input and output file paths
    std::string inputFilePath = "example.txt";
    std::string encryptedOutputFilePath = "example_encrypted.txt";
    std::string decryptedOutputFilePath = "example_decrypted.txt";

    // Encrypt the file
    encryptFile(inputFilePath, encryptedOutputFilePath, encryptionKey);
    decryptFile(encryptedOutputFilePath, decryptedOutputFilePath, encryptionKey);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
