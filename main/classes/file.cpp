#include "file.h"

using namespace core;

FileManager::FileManager() {
    this->files = std::vector<File>();
}

File::File(std::string & path) {
    this->path = path;
}