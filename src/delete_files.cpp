#include "delete_files.hpp"

namespace fs = std::filesystem;

void deleteFilesInDirectory(const std::string &directory, bool force, bool recurse)
{
    try
    {
        for (const auto &entry : fs::directory_iterator(directory))
        {
            if (fs::is_regular_file(entry.path()))
            {
                if (force || (entry.path().extension() != ".exe" && entry.path().extension() != ".dll"))
                {
                    fs::remove(entry.path());
                    std::cout << "Deleted file: " << entry.path() << std::endl;
                }
            }
            else if (fs::is_directory(entry.path()) && recurse)
            {
                deleteFilesInDirectory(entry.path().string(), force, recurse);
                fs::remove(entry.path()); // Remove the directory after deleting its contents
                std::cout << "Deleted directory: " << entry.path() << std::endl;
            }
        }
        if (directory != "." && fs::is_empty(directory))
        {
            fs::remove(directory); // Remove the directory if it's empty
            std::cout << "Deleted empty directory: " << directory << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
