#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include <cstdlib>

void writeLines(const std::string& filePath) {
    int fd1 = open(filePath.c_str(), O_CREAT | O_RDWR, 0644);
    if (fd1 == -1) {
        std::cerr << "cant open" << strerror(errno) << std::endl;
        exit(EXIT_FAILURE);
    }

    int fd2 = dup(fd1);
    if (fd2 == -1) {
        std::cerr << "cant open" << strerror(errno) << std::endl;
        close(fd1);
        exit(EXIT_FAILURE);
    }

    const char* line1 = "first line\n";
    ssize_t written = write(fd1, line1, strlen(line1));
    if (written == -1) {
        std::cerr << "cant write" << strerror(errno) << std::endl;
        close(fd1);
        close(fd2);
        exit(EXIT_FAILURE);
    }

    const char* line2 = "second line\n";
    written = write(fd2, line2, strlen(line2));
    if (written == -1) {
        std::cerr << "cant write" << strerror(errno) << std::endl;
        close(fd1);
        close(fd2);
        exit(EXIT_FAILURE);
    }

    close(fd1);
    close(fd2);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "./manual-append <file_path>" << std::endl;
        return EXIT_FAILURE;
    }

    std::string filePath = argv[1];
    writeLines(filePath);

    std::cout << "written" << filePath << std::endl;
    return EXIT_SUCCESS;
}