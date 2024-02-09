#include <algorithm> // std::reverse 사용
#include <cctype>    // std::toupper 사용
#include <iostream>
#include <string>

std::string decodeMessage(const std::string &input)
{
    std::string result;
    for (size_t i = 0; i < input.length(); ++i)
    {
        if ((input[i] >= 'a' && input[i] <= 'z') || input[i] == '_')
        {
            if (input[i] == '_')
            {
                result += ' ';
            }
            else
            {
                result += std::toupper(input[i]);
            }
        }
    }
    std::reverse(result.begin(), result.end());
    return result;
}

int main()
{
    std::string input;
    std::getline(std::cin, input);

    std::string decodedMessage = decodeMessage(input);
    std::cout << decodedMessage << std::endl;
    return 0;
}