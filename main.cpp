#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream file;

void tokenization()
{
    string token;
    string text;
    int line = 1;

    while (getline(file, text))
    {
        cout << "Line " << line << ": " << text << endl;

        int i = 0;

        while (i < text.length())
        {
            if (text[i] == ' ' || text[i] == '\t')
            {
                i++;
                continue;
            }

            token = "";

            if ((text[i] >= 'A' && text[i] <= 'Z') ||
                (text[i] >= 'a' && text[i] <= 'z') ||
                text[i] == '_' ||
                (text[i] >= '0' && text[i] <= '9'))
            {
                while (i < text.length() &&
                      ((text[i] >= 'A' && text[i] <= 'Z') ||
                       (text[i] >= 'a' && text[i] <= 'z') ||
                       (text[i] >= '0' && text[i] <= '9') ||
                       text[i] == '_'))
                {
                    token += text[i];
                    i++;
                }

                if (token == "int" || token == "float" ||
                    token == "double" || token == "char" ||
                    token == "if" || token == "else" ||
                    token == "while" || token == "for" ||
                    token == "do" || token == "return" ||
                    token == "void" || token == "bool" ||
                    token == "long" || token == "short" ||
                    token == "switch" || token == "case" ||
                    token == "break" || token == "continue" ||
                    token == "const")
                {
                    cout << token << " -> Keyword" << endl;
                }
                else if (token[0] >= '0' && token[0] <= '9')
                {
                    bool number = true;

                    for (int j = 0; j < token.length(); j++)
                    {
                        if (token[j] < '0' || token[j] > '9')
                            number = false;
                    }

                    if (number)
                        cout << token << " -> Number" << endl;
                    else
                        cout << token << " -> Invalid Identifier" << endl;
                }
                else
                {
                    cout << token << " -> Valid Identifier" << endl;
                }
            }

            else if (text[i] == '=' || text[i] == '+' ||
                     text[i] == '-' || text[i] == '*' ||
                     text[i] == '/' || text[i] == '%' ||
                     text[i] == '>' || text[i] == '<' ||
                     text[i] == '!' || text[i] == '&' ||
                     text[i] == '|')
            {
                token += text[i];
                i++;

                if (i < text.length() &&
                    (text[i] == '=' ||
                     (token == "+" && text[i] == '+') ||
                     (token == "-" && text[i] == '-') ||
                     (token == "&" && text[i] == '&') ||
                     (token == "|" && text[i] == '|')))
                {
                    token += text[i];
                    i++;
                }

                cout << token << " -> Operator" << endl;
            }

            else
            {
                token += text[i];
                i++;

                if (token == ";" || token == "," ||
                    token == "." || token == ":" ||
                    token == "(" || token == ")" ||
                    token == "{" || token == "}" ||
                    token == "[" || token == "]")
                {
                    cout << token << " -> Punctuation" << endl;
                }
                else
                {
                    cout << token << " -> Unknown Token" << endl;
                }
            }
        }

        cout << endl;
        line++;
    }

    file.close();
}

int main()
{
    string token1;
    ifstream MyReadFile("token1.txt");

    while (getline(MyReadFile, token1))
    {
        cout << token1 << endl;
    }

    MyReadFile.close();

    file.open("token1.txt");

    if (!file.is_open())
    {
        cout << "File not found!" << endl;
     }

    cout << endl;
    cout << "Token Identification Start" << endl << endl;

    tokenization();

    return 0;
}
