#include <iostream>
#include <CLI/CLI.hpp>

#include "core.h"
#include "constants.h"

int main(int argc, char** argv) {
    CLI::App app{yafetInfo};

    std::string input;
    std::string output;
    std::string key;

    app.add_flag_function("--version,-v", [&](int count) {
        std::cout << core::yafetInfo;
        exit(0);
    }, "Show the version of the application");

    CLI::App* encryptFile = app.add_subcommand("encrypt-file", "Encrypt a file");
    encryptFile->add_option("input", input, "Specify the input file")->required();
    encryptFile->add_option("output", output, "Specify the output file")->required();
    encryptFile->add_option("key", key, "Specify the key to use")->required();

    CLI::App* decryptFile = app.add_subcommand("decrypt-file", "Decrypt a file");
    decryptFile->add_option("input", input, "Specify the input file")->required();
    decryptFile->add_option("output", output, "Specify the output file")->required();
    decryptFile->add_option("key", key, "Specify the key to use")->required();

    CLI11_PARSE(app, argc, argv);

    if (encryptFile->parsed()) {
        std::ifstream inputFile = getIFileStream(input.c_str());
        std::ofstream outputFile = getOFileStream(output.c_str());

        encryptFileAes(inputFile, outputFile, key);
    } else if (decryptFile->parsed()) {
        std::ifstream inputFile = getIFileStream(input.c_str());
        std::ofstream outputFile = getOFileStream(output.c_str());

        decryptFileAes(inputFile, outputFile, key);
    }

    return 0;
}
