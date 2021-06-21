#ifndef morse_code_HPP_
#define morse_code_HPP_

#include <string>
#include <unordered_map>
#include<vector>
#include<iostream>
#include <algorithm>

class MorseCode{


    public:

    const std::string morse[26] = {
                             ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--",
                            "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
                        };
    const std::string alphabet[26] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};


    std::vector<std::string> decode(const std::string& code )const{

    std::string::size_type prev_pos = 0, pos = 0;
    std::string encoded_text;
    std::vector<std::string> temporary;

    while ((pos = code.find(" ", pos)) != std::string::npos){
        std::string coded_text(code.substr(prev_pos, pos - prev_pos));
        temporary.push_back(coded_text);
        prev_pos = ++pos;
    }
        return temporary;
}
//function to convert to upper case 
    std::string  toUpperCase(std::string& str){
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}

//function that do the decode to morse
/**@param a vector of morse code,
 * @return a string of alphabet 
 * this is the second part of decode process
 * */ 
    std::string MorseDecode(std::vector<std::string> tab){
        std::string output;
        for (size_t i = 0; i < tab.size(); i++){ 
            for (size_t j = 0; j < 26; j++){
    //^^^^ we iterate in each vector the one who contain the morse symbols and the vector 
    //the vector which is the output of the first phase of decode procedure
            if (tab[i]== morse[j])
    // ^^^^^ here we search for the indice of the symbole and the corresponding is the phonetic alphabet  
            output += alphabet[j]; 
        } 
        }   
        return output;
    
}  
 

//a map that tie up morse symboles and alphabet
/**@param a letter of char type
 * @return return a morse symbol which correspond to this char
 * it's the first phase of the encode process
*/
    std::string encode(const char letter)const {
    const std::unordered_map<char, std::string> encodings_Morse {
         {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."},
         {'E', "."}, {'F', "..-."}, {'G', "--."}, {'H', "...."}, {'I', ".."},
                     {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."},
         {'M', "--"}, {'N', "-."},
         {'O', "---"},
         {'P', ".--."}, {'Q', "--.-"},
         {'R', ".-."},{'S', "..."}, {'T', "-"},{'U', "..-"},{'V', "...-"}, {'W', ".--"},
         {'X', "-..-"},{'Y', "-.--"}, {'Z', "--.."}
      };
    
    return encodings_Morse.find(toupper(letter))->second;
    }
//function to convert a string to morse code
/**@param a string 
 * @return return a  string of morse code separated with spaces
 * this is the second phase of the encode process
*/

       std::string encode_string (const std::string& word ){
        std::string code;
        for(size_t    j=0; j < word.length(); j++){
            char letter = word[j];
            code.append(encode(letter)+" ");
        }
        return code;
    }
};

#endif