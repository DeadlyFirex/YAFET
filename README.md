## YAFET
> Yet-another-file-encryption-tool, a lightweight and crossplatform C++ utility designed encrypt data.

![GitHub release](https://img.shields.io/github/v/release/DeadlyFirex/YAFET)
![CMake cross-platform](https://github.com/DeadlyFirex/PingTool/actions/workflows/cmake-multi-platform.yml/badge.svg)
![wakatime](https://wakatime.com/badge/user/a56c956d-565b-4ddd-a43e-fb7d155c4232/project/e919eb0d-9447-46a2-a32f-107ff8f939c4.svg)
![GitHub License](https://img.shields.io/github/license/DeadlyFirex/YAFET)
![GitHub last commit (branch)](https://img.shields.io/github/last-commit/DeadlyFirex/YAFET/main)
![GitHub repo size](https://img.shields.io/github/repo-size/DeadlyFirex/YAFET)

YAFET is a lightweight and efficient encryption utility built on top of C++23. \
This project aims to demonstrate modern encryption and threading capabilities.

Currently, the project supports;
- Windows (x86/x64) MSVC
- Linux (x86/x64) GCC
- Linux ARM (aarch64) GCC

## Features
- Lightweight and efficient.
- Modern C++23 implementation.
- Simple command system.
- Argument parsing.
- Cross-platform
- Modern encryption.
- Easy to use command system.

## Installation
You can download the latest release from the [releases](https://github.com/DeadlyFirex/PingTool/releases/latest) 
page. \ If you wish to compile the project yourself, you can do so by following the instructions below.

## Compiling
The project relies on CMake to build and compile the project. \
Ensure you have at least CMake `3.27` installed, then clone the project using `--recursive-submodules`.

```bash
$ git clone --recursive-submodules https://github.com/DeadlyFirex/YAFET.git
```

After doing so, you can compile the project using CMake. \
```bash
$ cmake -DCMAKE_BUILD_TYPE=Release -S . -B build/
$ cmake --build build/ --config Release
```

## Usage
To use the project, you can run the executable with the `--help` flag to see the available commands. \
```bash
$ ./yafet --help
```

Simple encryption of a file can be done using the `encrypt` command. \
```bash
$ ./yafet encrypt-file <input_file> <output_file> <key>
```

Simple decryption of a file can be done using the `decrypt` command. \
```bash
$ ./yafet decrypt-file <input_file> <output_file> <key>
```

## Description
YAFET makes use of the Crypto++ library to handle encryption. \
It accepts sub-commands and their positional arguments to handle tasks.

## Configuration
Not supported yet.

## Details
For more information, see the [wiki](https://github.com/DeadlyFirex/YAFET/wiki)

## Dependencies
Credits go to these awesome projects for making this possible!
- [cryptopp](https://github.com/weidai11/cryptopp)
- [cryptopp-cmake](https://github.com/abdes/cryptopp-cmake)
- [CLI11](https://github.com/CLIUtils/CLI11)