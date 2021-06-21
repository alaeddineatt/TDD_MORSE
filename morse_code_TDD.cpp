#include "gmock/gmock.h"
#include "morse_code.hpp"

using namespace ::testing;

class morse_code_process:public Test{
    public:
    MorseCode morse_code;
    std::string come_on;
    std::vector<std::string> get_it;
};

TEST_F(morse_code_process, EncodeAChar) {
   ASSERT_THAT(morse_code.encode('A'), Eq(".-")); 
   ASSERT_THAT(morse_code.encode('Z'), Eq("--..")); 
   ASSERT_THAT(morse_code.encode('a'), Eq(".-")); 
}
TEST_F(morse_code_process,EncodeString){
    ASSERT_THAT(morse_code.encode_string("AB"), Eq(".- -... "));
}


TEST_F(morse_code_process, DecodeMorseTest) {
    get_it = morse_code.decode(".... . .-.. .-.. --- .-- --- .-. .-.. -.. ");
    

    ASSERT_THAT(get_it[2], Eq(".-.."));
    come_on = morse_code.MorseDecode(get_it);
    if(come_on  )
    ASSERT_THAT(morse_code.MorseDecode(get_it), Eq("HelloWorld"));
    
}

