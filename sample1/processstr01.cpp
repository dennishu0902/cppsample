#include <iostream>
#include <string>
#include <vector>
using namespace std;
std::vector<std::string> WordsToVector(std::string str);
// remove the punction from str
std::string removepunction(std::string str)
{
    std::string substr;
    int i;
    char ch;
    substr.clear();
    //for (std::string::iterator it = str.begin(); it != str.end(); ++it)
    for (i=0; i< str.size(); i++)
    {
        ch = str[i]; 
        switch(ch)
        {
            case '!':
            case '?':
            case '.':
            case ',':
               break ; //skip punction
            default :
              substr.push_back(ch);   
        }
    }
    return substr;
}
// split str to word, the interval sysmbol is ' '
std::vector<std::string> split(std::string str)
{
    std::vector<std::string> v1;
    std::string substr;
    int i;
    char ch;
    bool b_startwithnonspace;
    substr.clear();
    b_startwithnonspace = false;
    //for (std::string::iterator it = str.begin(); it != str.end(); ++it)
    for (i=0; i< str.size(); i++)
    {
        ch = str[i];
        if(ch==' ') 
         {
            if(b_startwithnonspace ==false) continue;
            else
            {
             v1.push_back(substr);
             b_startwithnonspace = false;
             substr.clear();
            }
         }
         else
         {
            /* code */
            b_startwithnonspace = true;
            substr.push_back(ch);
         }
    }
    if(b_startwithnonspace == true)  v1.push_back(substr); // if the last one, not end of space
    return v1;
}
std::vector<std::string> WordsToVector(std::string str)
{
    std::vector<std::string> v1;
    std::string strnopunction;
    strnopunction = removepunction(str);
    v1 = split(strnopunction);
    return v1;
}
int main(int argc, char** argv)
{
    std::vector<std::string> v2;
    cout << "CMakeProjectTest Test"<<std::endl;
    std::string phrase="It was the best time, It was the worst of time, It was the age of time!";
    std::string phrase1="Hello";
    std::string phrase2="Hello World";
    v2 = WordsToVector(phrase);
    for (auto it = std::begin(v2); it != std::end(v2); ++it)
        std::cout << *it << std::endl;
    v2 = WordsToVector(phrase1);
    for (auto it = std::begin(v2); it != std::end(v2); ++it)
        std::cout << *it << std::endl;
    v2 = WordsToVector(phrase2);
    for (auto it = std::begin(v2); it != std::end(v2); ++it)
        std::cout << *it << std::endl;        

}
