//
// Created by edida on 2024/7/15.
//
#include <iostream>
#include <vector>
#include <cstring>
#include <sstream> // 包含这个头文件

std::vector<std::string> split(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

char** stringToCharArray(const std::vector<std::string>& strs) {
    size_t count = strs.size();
    char** array = new char*[count + 1]; // +1 for null terminator
    for (size_t i = 0; i < count; ++i) {
        array[i] = new char[strs[i].size() + 1]; // +1 for null terminator
        std::strcpy(array[i], strs[i].c_str());
    }
    array[count] = nullptr; // null terminator for the array
    return array;
}

// 注意：这个函数应该放在一个类中，但为了简化，我直接放在了全局作用域
char** split(const char* strs, char delimiter) {
    std::string s(strs);
    auto tokens = split(s, delimiter);
    return stringToCharArray(tokens);
}

// 调用者需要释放返回的char**数组及其指向的所有字符串
void freeSplitResult(char** array) {
    if (array) {
        while (*array) {
            delete[] *array++;
        }
        delete[] array;
    }
}

int main() {
    char strs[] = u8"我,是,中国,程序员";
    char** result = split(strs, ',');

    // 打印结果
    for (char** ptr = result; *ptr; ++ptr) {
        std::cout << *ptr << std::endl;
    }

    // 释放资源
    freeSplitResult(result);

    return 0;
}