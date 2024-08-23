//
// Created by user on 23.08.2024.
//

#include "ArgumentParser.h"
#include <iostream>
#include <algorithm>
#include <sstream>

ArgumentParser::ArgumentParser(int argc, char* argv[])
    : prefixes{"-", "--", "/"} {
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        std::string stripped = stripPrefix(arg);

        if (i + 1 < argc && prefixes.end() == std::find_if(prefixes.begin(), prefixes.end(),
            [&](const std::string& prefix) { return argv[i + 1] == prefix; })) {
            arguments[stripped] = argv[i + 1];
            ++i;
            } else {
                arguments[stripped] = "";
            }
    }
}

std::string ArgumentParser::stripPrefix(const std::string& arg) const {
    for (const auto& prefix : prefixes) {
        if (arg.substr(0, prefix.length()) == prefix) {
            return arg.substr(prefix.length());
        }
    }
    return arg;
}

std::string ArgumentParser::get(const std::string& key) const {
    auto it = arguments.find(key);
    if (it != arguments.end()) {
        return it->second;
    }
    return "";
}

bool ArgumentParser::has(const std::string& key) const {
    return arguments.find(key) != arguments.end();
}

void ArgumentParser::print() const {
    for (const auto& pair : arguments) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
}

std::string ArgumentParser::getAllAsString() const {
    std::ostringstream oss;
    if (arguments.empty()) {
        oss << "No arguments were parsed.";
    } else {
        oss << "Parsed arguments:\n";
        for (const auto& [key, value] : arguments) {
            oss << key << ": ";
            if (value.empty()) {
                oss << "<flag>";
            } else {
                oss << "\"" << value << "\"";
            }
            oss << "\n";
        }
    }
    return oss.str();
}