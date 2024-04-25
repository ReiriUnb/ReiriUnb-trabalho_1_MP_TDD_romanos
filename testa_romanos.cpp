#define CATCH_CONFIG_MAIN 
#include "catch.hpp"
#include "romanos.hpp"

// Este é um caso de teste para algarismos romanos unicos
TEST_CASE( "Numeros romanos - algarismos únicos", "[romanos]" ) {
    // Estes são os testes para cada algarismo romano unico
    REQUIRE( romanos_para_decimal("I") == 1 );
    REQUIRE( romanos_para_decimal("V") == 5 );
    REQUIRE( romanos_para_decimal("X") == 10 );
    REQUIRE( romanos_para_decimal("L") == 50 );
    REQUIRE( romanos_para_decimal("C") == 100 );
    REQUIRE( romanos_para_decimal("D") == 500 );
    REQUIRE( romanos_para_decimal("M") == 1000 );
}

// Este é um caso de teste para algarismos romanos invalidos
TEST_CASE( "Numeros romanos - algarismos inválidos", "[romanos]" ) {
    // Estes são os testes para algarismos invalidos
    REQUIRE( romanos_para_decimal("G") == -1 );
    REQUIRE( romanos_para_decimal("i") == -1 );
}

// Este é um caso de teste para multiplos algarismos romanos
TEST_CASE( "Numeros romanos - múltiplos algarismos", "[romanos]" ) {
    // Estes são os testes para nun romanos com multiplos algarismos
    REQUIRE( romanos_para_decimal("II") == 2 );
    REQUIRE( romanos_para_decimal("IV") == 4 );
    REQUIRE( romanos_para_decimal("IX") == 9 );
    REQUIRE( romanos_para_decimal("LVIII") == 58 );
    REQUIRE( romanos_para_decimal("MCMXCIV") == 1994 );
}

// Este é um caso de teste para num romanos mais complexos
TEST_CASE( "Numeros romanos - casos complexos", "[romanos]" ) {
    REQUIRE( romanos_para_decimal("XL") == 40 );
    REQUIRE( romanos_para_decimal("XC") == 90 );
    REQUIRE( romanos_para_decimal("CD") == 400 );
    REQUIRE( romanos_para_decimal("CM") == 900 );
    REQUIRE( romanos_para_decimal("MMMCMXCIX") == 3999 );
}

// Este é um caso de teste para alguns casos inválidos
TEST_CASE( "Numeros romanos - casos inválidos", "[romanos]" ) {
    REQUIRE( romanos_para_decimal("IC") == -1 );  // I antes de C é invalido
    REQUIRE( romanos_para_decimal("IM") == -1 );  // I antes de M é invalido
    REQUIRE( romanos_para_decimal("XD") == -1 );  // X antes de D é invalido
    REQUIRE( romanos_para_decimal("XM") == -1 );  // X antes de M é invalido
}
