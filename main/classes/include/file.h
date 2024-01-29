#include <vector>
#include <string>
#include <ctime>
#include <algorithm.h>

namespace core {

    class File {
    private:
        std::string path;
        std::size_t size;
        std::time_t createdAt;
        std::time_t modifiedAt;
        std::string fileType;
        std::string owner;
        core::Algorithm algorithm;

    public:
        bool encrypted = false;
        char version[6] = YAFET_VERSION;

        explicit File(std::string & path);
    };

    class FileManager {
    private:
        std::vector<File> files;

    public:
        FileManager();
        void addFile(File & file);
        void removeFile(File & file);
        void encryptAll();
        void decryptAll();
        void archiveTo(std::string & path, Algorithm algorithm);
        void extractTo(std::string & path, Algorithm algorithm);
    };

}
