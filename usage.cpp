int main ()
{
#if 0
    // Creating a string from const char*
    static_string <16> str1 = "hello";
    static_string <16> str2 = "world";
    
    // Concatenating strings
    static_string <32> str3 = str1 + " " + str2;
    
    // Print out the result
    std::printf ( "> %s\n", str3.c_str() );
    
    // Accessing an element using subscript operator[]
    std::printf ( "> %c \n", str1[0] );

    str1[0] = 'W';

    std::printf ( "> %s\n", str1.c_str() );
#endif

// AI - generated tests, do not treat too seriously.
////////////////////////////////////////////////////////////////////////////////
    // Creating strings from const char*
    std::printf ("Creating strings from const char* \n");
    static_string <16> str1 = "hello";
    static_string <16> str2 = "world";

    std::printf("> %s\n", str1.c_str());
    std::printf("> %s\n", str2.c_str());

    // Concatenating strings
    std::printf ("Concatenating strings \n");
    static_string <64> str3 = str1 + static_string <1>(" ") + str2;

    std::printf("> %s\n", str3.c_str());

    // Concatenating a string with a string
    std::printf ("Concatenating string & string \n");
    static_string <32> str4 = str1 + str2;

    std::printf("> %s\n", str4.c_str());

    // Concatenating multiple literals
    std::printf ("Concatenating string & string \n");
    static_string <32> str5 = static_string<6> ("hello") + str1;

    std::printf("> %s\n", str5.c_str());

    // Accessing an element using subscript operator[]
    std::printf ("Access an element using operator[]\n");
    std::printf("> %c\n", str1[0]);

    str1[0] = 'W';
    std::printf("> %s\n", str1.c_str());

    static_string <16> cmp0 = "echo";
    static_string <32> cmp1 = "echo_bravo";

    std::printf("THESE SHOULD NOT BE EQUAL > %d\n", (cmp0 == cmp1));

    static_string <16> cmp2 = "echo";
    static_string <32> cmp3 = "echo";

    std::printf("THESE SHOULD BE EQUAL > %d\n", (cmp2 == cmp3));
#if 0

    // Const access
    const static_string <16> str6 = "constant";

    std::printf("> %s\n", str6.c_str());
    std::printf("> %c\n", str6[0]);

    // uint8_t tests
    uint8_t value8 = 42;

    static_string <16> str7 = value8;

    std::printf("> uint8_t: %s\n", str7.c_str());

    // Several uint8_t values
    uint8_t a = 1;
    uint8_t b = 127;
    uint8_t c = 255;

    static_string <16> str8 = a;
    static_string <16> str9 = b;
    static_string <16> str10 = c;

    std::printf("> %s\n", str8.c_str());
    std::printf("> %s\n", str9.c_str());
    std::printf("> %s\n", str10.c_str());

    // Concatenation involving uint8_t
    static_string <32> str11 = "value=" + str7;

    std::printf("> %s\n", str11.c_str());
#endif
    return 0;
}
