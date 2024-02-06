#pragma once

#include <string>
#include <iostream>
#include <filesystem>
#include <vector>
#include <algorithm>

void deleteFilesInDirectory(const std::string &directory, bool force, bool recurse);