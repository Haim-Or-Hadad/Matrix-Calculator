/**
 * @file Test.cpp
 * @author Haim Or Hadad
 * @brief 
 * @version 0.1
 * @date 2022-04-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "doctest.h"
#include "Matrix.hpp"

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>

using namespace zich;
using namespace std;
/**
 * @brief matrices for tests 
 */
///////------matrix 3*3-------//////////
Matrix zero_matrix{{0 ,0 ,0 ,
                    0 ,0 ,0 ,
                    0 ,0 ,0} ,3 ,3};
///////------matrix 3*3-------//////////
Matrix matrix1{{1 ,0 ,0 ,
                0 ,1 ,0 ,
                0 ,0 ,1 } ,3 ,3}; 
///////------matrix 3*3-------//////////
Matrix matrix2{{3 ,0 ,0 ,
                0 ,3 ,0 ,
                0 ,0 ,3 },3 ,3};
///////------matrix 2*2-------//////////
Matrix matrix7{{7 , 8 ,
                6 , 10} ,2 ,2};
///////------matrix 2*2-------//////////
Matrix matrix8{{6 , 7 ,
                5 , 9} ,2 ,2};
///////------matrix 3*3-------//////////
Matrix matrix2_1{{2 ,0 ,0,
                  0 ,2 ,0,
                  0 ,0 ,2}, 3, 3};
///////------matrix 1*3-------//////////
Matrix matrix4{{1 ,2 ,3},1 ,3};
///////------matrix 3*3-------//////////
Matrix matrix5{{4 ,0 ,0 ,
                0 ,4 ,0 ,
                0 ,0 ,4} ,3 ,3};
///////------matrix 2*3-------//////////
Matrix matrix_mul1{{1,2,3,
                    4,5,6},2,3};
///////------matrix 2*3-------//////////
Matrix matrix_mul2{{7,8,9,
                    10,11,12},3,2};
///////------matrix 2*2-------//////////
Matrix matrix_ans{{58,64,
                   139,154},2,2};
///////------matrix 2*2-------//////////
Matrix mat_for_scalar{{1,2,
                       3,4},2,2};
///////------matrix 2*2-------//////////
Matrix ans_of_scalar{{-2,-4,
                      -6,-8},2,2};
/** tests **/
TEST_CASE("arithmetic operators"){
    SUBCASE("Corrects Addition and subtraction of two matrix "){
        CHECK_EQ((matrix1 + matrix2) == matrix5, true); // '+'
        CHECK_EQ((matrix5 + zero_matrix) == matrix5, true); //'-'
        CHECK_EQ((matrix2 - matrix1) == matrix2_1, true  );
        CHECK_EQ((matrix2 - zero_matrix) == matrix2, true );
        CHECK_EQ((zero_matrix + zero_matrix) == zero_matrix, true );
    }
    SUBCASE("Correction of '-=' , +="){
        matrix2 -=matrix1; // '-='
        CHECK_EQ(matrix2 == matrix2_1 , true ); // '-='
        matrix1 += matrix1; //'+='
        CHECK_EQ(matrix2 == matrix1 , true); // '+='
        matrix2 += matrix1; //reset
        matrix1 -= matrix1; //reset
    }
    SUBCASE("ONERIS"){
        CHECK_NOTHROW(+matrix1); // '+()'
        CHECK_EQ(matrix1 == (+matrix1), true );
        CHECK_NOTHROW(-matrix2);// '-()'
    }
}

TEST_CASE("booleans operators"){
    SUBCASE("All CASES"){
        CHECK_EQ(matrix8 < matrix7, true); //'<'
        CHECK_EQ(matrix2_1 > zero_matrix, true);// '>'
        CHECK_EQ(matrix8 <= matrix7, true); //'<='
        CHECK_EQ(matrix2_1 >= zero_matrix, true);// '>='
        CHECK_EQ(matrix1 != zero_matrix, true);//'!='
        CHECK_EQ(matrix1 != matrix8, true );//'!='
    }
}
TEST_CASE("Increament operators"){  
        CHECK_NOTHROW(--zero_matrix);
        CHECK_EQ((--matrix7) == matrix8 , true); // '--'
        ++matrix7;
        CHECK_EQ((++matrix7) == matrix8 , true); // '++'
}
TEST_CASE("Multiply Matrices"){
        SUBCASE("two matrix - '*"){
        CHECK_EQ(zero_matrix * zero_matrix == zero_matrix , true);
        CHECK_EQ(zero_matrix * matrix1 == zero_matrix , true);
        CHECK_THROWS(matrix1 * matrix7);
        CHECK_EQ(matrix_mul1 * matrix_mul2 == matrix_ans, true);
    }
    SUBCASE("scalar"){
        CHECK_EQ(3*zero_matrix == zero_matrix , true);
        CHECK_EQ((-2)*mat_for_scalar == ans_of_scalar, true);
    }
    SUBCASE(" '*=' of matrix and scalar"){
        mat_for_scalar *= -2;
        CHECK_EQ(mat_for_scalar == ans_of_scalar , true);
        mat_for_scalar *= zero_matrix;
        CHECK_EQ( mat_for_scalar == zero_matrix , true);
        }
}
