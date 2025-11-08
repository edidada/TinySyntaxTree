#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <filesystem>
#include "analyse.h"
#include "globals.h"

// Uncomment for GB2312 support on Windows
/*
#include <windows.h>
std::string toUtf8(const std::string& gbkStr) {
    int len = MultiByteToWideChar(CP_ACP, 0, gbkStr.c_str(), -1, nullptr, 0);
    std::vector<wchar_t> wide(len);
    MultiByteToWideChar(CP_ACP, 0, gbkStr.c_str(), -1, wide.data(), len);
    int utf8Len = WideCharToMultiByte(CP_UTF8, 0, wide.data(), -1, nullptr, 0, nullptr, nullptr);
    std::vector<char> utf8(utf8Len);
    WideCharToMultiByte(CP_UTF8, 0, wide.data(), -1, utf8.data(), utf8Len, nullptr, nullptr);
    return std::string(utf8.data());
}
*/

// Load input file content (replaces on_pushButton_6_clicked)
std::string loadInputFile(const std::string& filePath) {
    std::ifstream inputFile(filePath);
    if (!inputFile) {
        std::cerr << "Error: Cannot open input file " << filePath << ". Check path or if file is in use.\n";
        std::exit(1);
    }
    std::stringstream buffer;
    buffer << inputFile.rdbuf();
    inputFile.close();
    // For GB2312 support, uncomment and use:
    // return toUtf8(buffer.str());
    return buffer.str();
}

// Save content to output file (replaces on_pushButton_7_clicked)
void saveOutputFile(const std::string& filePath, const std::string& content) {
    if (content.empty()) {
        std::cerr << "Error: Content is empty, nothing to save.\n";
        return;
    }
    std::ofstream outputFile(filePath);
    if (!outputFile) {
        std::cerr << "Error: Cannot open output file " << filePath << ".\n";
        return;
    }
    outputFile << content;
    outputFile.close();
    std::cout << "Output saved to " << filePath << ".\n";
}

// Process Tiny code using temporary file and AnalyzeCode (replaces on_pushButton_8_clicked)
void processTinyCode(const std::string& sourceCode, const std::string& outputPath) {
    if (sourceCode.empty()) {
        std::cerr << "Error: Source code is empty.\n";
        std::exit(1);
    }

    // Clear previous file handle
    if (source != nullptr) {
        fclose(source);
        source = nullptr;
    }

    // Create temporary file using std::filesystem
    std::filesystem::path tempPath = std::filesystem::temp_directory_path() / "tiny_temp.tny";
    {
        std::ofstream tempFile(tempPath);
        if (!tempFile) {
            std::cerr << "Error: Cannot create temporary file " << tempPath << ".\n";
            std::exit(1);
        }
        tempFile << sourceCode;
        tempFile.close();
    }

    // Open temporary file for AnalyzeCode
    source = fopen(tempPath.string().c_str(), "r");
    if (!source) {
        std::cerr << "Error: Cannot open temporary file " << tempPath << ".\n";
        std::filesystem::remove(tempPath);
        std::exit(1);
    }

    // Reset globals
    lineno = 0;
    Error = false;
    debugMsg.clear();

    // Call AnalyzeCode (assuming it returns void* instead of QTreeWidgetItem*)
    void* parseTree = AnalyzeCode();
    if (Error) {
        std::cerr << "Syntax error in program. Debug message:\n" << debugMsg << '\n';
        fclose(source);
        source = nullptr;
        std::filesystem::remove(tempPath);
        if (!outputPath.empty()) {
            saveOutputFile(outputPath, debugMsg);
        } else {
            std::cout << debugMsg << '\n';
        }
        return;
    }

    // Output parse tree (simplified, as structure is unknown)
    if (parseTree) {
        std::string result = debugMsg.empty() ? "Parse tree generated (structure not displayed in console mode)" : debugMsg;
        if (!outputPath.empty()) {
            saveOutputFile(outputPath, result);
        } else {
            std::cout << result << '\n';
        }
    } else {
        std::cerr << "Error: No parse tree generated.\n";
    }

    // Clean up
    fclose(source);
    source = nullptr;
    std::filesystem::remove(tempPath);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file> [output_file]\n";
        return 1;
    }

    std::string inputFilePath = argv[1];
    std::string outputFilePath = (argc > 2) ? argv[2] : "";

    // Load input file
    std::string sourceCode = loadInputFile(inputFilePath);

    // Process Tiny code
    processTinyCode(sourceCode, outputFilePath);

    return 0;
}