#include "delete_files.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <directory> [-f/--force] [-r/--recurse]" << std::endl;
        return 1;
    }

    std::string directory = argv[1];
    bool force = false;
    bool recurse = false;

    // Check if the force and recurse flags are provided
    for (int i = 2; i < argc; ++i)
    {
        std::string arg = argv[i];
        if (arg == "-f" || arg == "--force")
        {
            force = true;
        }
        else if (arg == "-r" || arg == "--recurse")
        {
            recurse = true;
        }
    }

    deleteFilesInDirectory(directory, force, recurse);

    return 0;
}
