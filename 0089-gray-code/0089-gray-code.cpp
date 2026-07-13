class Solution {
public:
    // Generate n-bit Gray code as strings
    static std::vector<std::string> generate(int n) {
        if (n == 1) {
            return {"0", "1"};
        }

        std::vector<std::string> prevGrayCode = generate(n - 1);
        std::vector<std::string> currentGrayCode;

        // Prepend 0 to the original sequence
        for (int i = 0; i < static_cast<int>(prevGrayCode.size()); ++i) {
            currentGrayCode.push_back("0" + prevGrayCode[i]);
        }

        // Prepend 1 to the mirrored sequence
        for (int i = static_cast<int>(prevGrayCode.size()) - 1; i >= 0; --i) {
            currentGrayCode.push_back("1" + prevGrayCode[i]);
        }

        return currentGrayCode;
    }

    // Convert binary string to integer
    static int binaryStringToInt(const std::string& str) {
        const int n = static_cast<int>(str.size());
        int decimal = 0;

        for (int i = 0; i < n; ++i) {
            if (str[i] == '1') {
                decimal += (1 << (n - i - 1));
            }
        }

        return decimal;
    }

    // Generate Gray code as integers
    static std::vector<int> grayCode(int n) {
        std::vector<std::string> grayCodeStr = generate(n);
        std::vector<int> result;

        for (const auto& code : grayCodeStr) {
            int convertedCode = binaryStringToInt(code);
            result.push_back(convertedCode);
        }

        return result;
    }
};