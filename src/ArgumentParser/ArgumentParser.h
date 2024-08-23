//
// Created by user on 23.08.2024.
//

#ifndef ARGUMENTPARSER_H
#define ARGUMENTPARSER_H



#pragma once

#include <map>
#include <string>
#include <vector>

class ArgumentParser {
private:
    std::map<std::string, std::string> arguments;
    std::vector<std::string> prefixes;

    std::string stripPrefix(const std::string& arg) const;

public:
    ArgumentParser(int argc, char* argv[]);

    std::string get(const std::string& key) const;
    bool has(const std::string& key) const;
    void print() const;
    std::string getAllAsString() const;
};



#endif //ARGUMENTPARSER_H
