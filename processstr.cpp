#include <iostream>
#include <string>
#include <vector>
using namespace std;
std::vector<std::string> WordsToVector(std::string str);
std::vector<std::string> WordsToVector(std::string str)
{
    std::vector<std::string> v1;
    std::string substr;
    bool findfirstone;
    findfirstone = false;
    substr.clear();
    //for (std::string::iterator it = str.begin(); it != str.end(); ++it)
    for (auto it = str.begin(); it != str.end(); ++it)
    {
        if ((*it == ' ') && (findfirstone == false))  continue; //skip space at header 
        else if ((*it == '?') || (*it == '!') || (*it == '.') || (*it == ',') || (*it == ' '))
        {   //find a splitter charactor
            v1.push_back(substr);  //save the previous string
            substr.clear();
            findfirstone = false; //reset flag
        }
        else 
        {
            findfirstone = true;
            substr.push_back(*it);//save char to string 
        }
    }
    if(findfirstone == true) 
        v1.push_back(substr);  //save the previous string, no punction at the end
    return v1;
}
int main(int argc, char** argv)
{
    std::vector<std::string> v2;
    cout << "CMakeProjectTest Test"<<std::endl;
    std::string phrase="It was the best time, It was the worst of time, It was the age of time!";
    v2 = WordsToVector(phrase);
    for (auto it = std::begin(v2); it != std::end(v2); ++it)
        std::cout << *it << std::endl;
}
