
#include <iostream>
#include <string> 
#include <vector>
#include <cctype>
#include <stdexcept>

using namespace std;
//refernece link ASCII table
// https://www.sciencebuddies.org/science-fair-projects/references/ascii-table
//This function takes in a string (word) and returns the result of making all characters in that word lowercase.
std::string StringToLower(const std::string& word);
//This function takes in a lowercase character (c) and returns true if it’s a valid character in the Hawaiian language, false otherwise.
//a, e, i, o, u, p, k, h, l, m, n, and  '
bool IsValidCharacter(const char& c);
//This function takes in a lowercase string (word) and returns true if every character in word is a valid character in the Hawaiian language, false otherwise.
bool IsValidWord(const std::string& word);
//This function takes in two lowercase characters (v1 and v2) and returns true if the sequence v1 v2 is a vowel group according to the rules above, false otherwise.
//ai ae ao au ei eu iu oi ou ui
bool IsVowelGroup(const char& v1, const char& v2);
//a e i o u
bool IsVowel(const char& v);
//This function takes in a lowercase character (c) and returns true if c is a consonant, false otherwise.
//p, k, h, l, m, n Pronounced like the English versions.
//w — start of word /after the letter 'a' Either pronounced as a w or a v sound. We shall pronounce it as a w sound
//w — after ‘i’ or ‘e’ Pronounced as a v sound.
//w — after ‘u’ or ‘o’ Pronounced as a w sound.
bool IsConsonant(const char& c);
//
char ConsonantPronunciation(const char& c, const char& prev='\0');
std::string VowelGroupPronunciation(const char& v1, const char& v2);
std::string SingleVowelPronunciation(const char& v);
std::string ProcessCharacter(const char& prev, const char& curr, const char& next);
std::string Pronunciation(const std::string& word);
std::string GetPronunciation(const std::string& hawaiian_word);
std::string GetPronunciation(const std::string& hawaiian_word)
{
    std::string hawaiian_word_lower, strpron;
    hawaiian_word_lower = StringToLower(hawaiian_word);
    if(IsValidWord(hawaiian_word_lower))
    {
       strpron = Pronunciation(hawaiian_word_lower);
    }
    else
       throw invalid_argument("Invalid words exception?");
    return strpron;
}
bool IsValidWord(const std::string& word)
{
    int i=0;
    if(word.size()==0) return false;
    for(i=0; i< word.size(); i++)
    {
        if(IsValidCharacter(word[i])==false) return false;
    }
    return true;
}
//a, e, i, o, u, p, k, h, l, m, n, and  '
bool IsValidCharacter(const char& c)
{   
    int i;
    std::string validch="aeioupkhlmn'";
    for(i=0;i<validch.size();i++)
    {
        if(c == validch[i]) return true;
    }
    return false; 
}
//a e i o u
bool IsVowel(const char& v)
{
    int i;
    std::string validvowel="aeiou";
    for(i=0;i<validvowel.size();i++)
    {
        if(v == validvowel[i]) return true;
    }
    return false; 
}
//ai ae ao au ei eu iu oi ou ui
bool IsVowelGroup(const char& v1, const char& v2)
{
    int i;
    std::string validvowelgrp="aiaeaoaueieuiuoiouui";
    for(i=0;i<validvowelgrp.size();i=i+2)
    {
        if((v1 == validvowelgrp[i]) && (v2 == validvowelgrp[i+1])) return true;
    }
    return false; 
}
///p, k, h, l, m, n, w
bool IsConsonant(const char& c)
{
    int i;
    std::string validvowel="pkhlmnw";
    for(i=0;i<validvowel.size();i++)
    {
        if(c == validvowel[i]) return true;
    }
    return false; 
}
std::string StringToLower(const std::string& word)
{
    int i;
    std::string lowerstr;
    for(i=0; i< word.size();i++)
    {
       /*  write a tolower code or call tolower 
        if(word[i]>='A' && word[i] <='Z') 
           lowerstr.push_back((word[i] - 'A') + 'a');
        else
           lowerstr.push_back(word[i]); */
       lowerstr.push_back(std::tolower(word[i]));     
    }
    return lowerstr;
}
////p, k, h, l, m, n Pronounced like the English versions.
//w — start of word /after the letter 'a' Either pronounced as a w or a v sound. We shall pronounce it as a w sound
//w — after ‘i’ or ‘e’ Pronounced as a v sound.
//w — after ‘u’ or ‘o’ Pronounced as a w sound.
char ConsonantPronunciation(const char& c, const char& prev)
{
    if(c!='w') return c;
    if((prev=='\0') || (prev=='a')) return 'w';
    if((prev=='i') || (prev=='e'))  return 'v';
    if((prev=='u') || (prev=='o'))  return 'w';
}
std::string VowelGroupPronunciation(const char& v1, const char& v2)
{
    int i;
    std::string str1;
    std::string validvowelgrp="aiaeaoaueieuiuoiouui";
    std::string  Vowgrp[]={"eye","eye","ow","ow","ay","eh-oo","ew","oy","ow","ooey"};
    for(i=0; i< validvowelgrp.size();i=i+2)
    {
        if((v1==validvowelgrp[i]) && (v1==validvowelgrp[i+1]))
           { str1 =  Vowgrp[i/2]; break;}
    }
    return str1;
}
std::string SingleVowelPronunciation(const char& v)
{ // a -> ah, e-> eh, i-> ee, o->oh u->oo
  std::string str1;
  switch(v)
  {
    case 'a' : str1 = "ah"; break;
    case 'e' : str1 = "eh"; break;
    case 'i' : str1 = "ee"; break;
    case 'o' : str1 = "oh"; break;
    case 'u' : str1 = "oo"; break;
    default:   str1 = "";
  }
  return str1;
}
std::string Pronunciation(const std::string& word)
{
    int i;
    char prev='\0';
    std::string strpron;
    for(i=0;i<word.size();)
    {
        if(IsVowelGroup(word[i],word[i+1]))
        {
          strpron.append(VowelGroupPronunciation(word[i],word[i+1]));
          if( (i+2) < word.size()) 
            { if(word[i+2] != '\'') strpron.append(1,'-');}
          prev = word[i+1];
          i = i+2;
        }
        else if(IsVowel(word[i]))
        {
          strpron.append(SingleVowelPronunciation(word[i]));
          if( (i+1) < word.size()) 
            { if(word[i+1] != '\'') strpron.append(1,'-');}
          prev = word[i];
          i = i+1;  
        }
        else if(IsConsonant(word[i]))
        {
          strpron.append(1,ConsonantPronunciation(word[i],prev));
          prev = word[i];
          i = i+1;    
        }
        else if(word[i] == '\'')
        {
           strpron.append(1,'\'');
           prev = '\0';
           i = i + 1;
        }
        else 
          std::cout << "exception" << std::endl;
    }    
    return strpron;
}

int main()
{
    std::string  str1="humuhumunukunukuapua'a";
    std::string  str2;
    try{
        str2 = GetPronunciation(str1);
        std::cout << "Pronunciation" << std::endl;
        std::cout << str2 << std::endl;
    }
    catch (const std::invalid_argument& ia) {
	  std::cerr << "Invalid argument: " << ia.what() << '\n';
  }
}
