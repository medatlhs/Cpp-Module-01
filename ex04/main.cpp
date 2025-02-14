#include <iostream>
#include <fstream>

std::string ft_replace(int startPos, int len, std::string line, std::string str)
{
    int copiedChars = 0;
    for (int i = 0; i < str.length() ;i++, startPos++, copiedChars++)
        line[startPos] = str[i];
    if (copiedChars < len)
        line.erase(startPos, len - copiedChars);
    return (line);
}

std::string checkReplace(std::string s1, std::string s2, std::string line)
{
    for (int i = 0; i < line.length(); i++)
    {
        int k = 0;
        int startPos = -1;
        int endPos = -1;

        if (line[i] == s1[k])
        {
            startPos = i;
            for (k = 0; s1[k] == line[i] && i < line.length(); k++, i++) { }
            if (s1[k] == '\0')
            {
                endPos = i;
                line = ft_replace(startPos, endPos - startPos, line, s2);
                i = startPos + s2.length() - 1;
            }
        }
    }
    return line;
}

int main(int argc, char *argv[])
{
    if (argc != 4) {
        std::cout << "Wrong number of arguments!\n";
        return 1;
    }
    
    std::fstream infile;
    std::fstream outfile;
    std::string  outfileName = argv[1];

    infile.open(argv[1], std::ios::in);
    if (!infile.is_open())
        std::cout << "Error opening infile\n";

    outfile.open(outfileName.append(".replace.txt"), std::ios::out | std::ios::trunc);
    if (!outfile.is_open())
        std::cout << "Error opening outfile\n";

    std::string  line;
    while (getline(infile, line)) {
        std::string newLine = checkReplace(argv[2], argv[3], line);
        newLine += "\n"; 
        outfile << newLine;
    }    
    return 0;
}
