#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "Matrix.hpp"
#include <stdexcept>

 using namespace std;


 namespace zich{
     /** check if the matrix have same dimentions **/
     void check_same_dimentions(int a_col, int a_row, int b_col, int b_row){
         if(a_col != b_col || a_row != b_row){
            throw invalid_argument("different dimentions");
         }
     }

    // int & Matrix::operator()(int colum, int row){
    //     return this->matrix.at(colum).at(row);
    // }
     //*******Overloading 6-arithmetic operators*****//
     Matrix Matrix::operator+(const Matrix &other){
         check_same_dimentions(this->get_col(), this->get_row(), other.num_of_colums , other.num_of_rows);
         vector<double> sum_matrix;
         for (int row = 0; row < other.num_of_rows; row++)
         {
             for (int col = 0; col < other.num_of_colums; col++)
             {
                 sum_matrix.push_back(this->matrix.at(row).at(col)+
                                      other.matrix.at(row).at(col));
             }   
         }
        return Matrix(sum_matrix , get_col(), get_row()); 
     }

     Matrix Matrix::operator+()const{   //onari
        vector<double> plus_matrix;
        for (int row = 0; row < get_row(); row++)
        {
            for (int col = 0; col < get_col(); col++)
            {
                plus_matrix.push_back(this->matrix.at(row).at(col));
            }
        }
        return Matrix(plus_matrix , get_col() , get_row());   
    }

    Matrix& Matrix::operator+=(const Matrix &other){
        check_same_dimentions(this->get_col(), this->get_row(), other.num_of_colums , other.num_of_rows);
        for (int row = 0; row < other.num_of_rows; row++)
        {
            for (int col = 0; col < other.num_of_colums; col++)
            {
                this->matrix.at(row).at(col) = (this->matrix.at(row).at(col)+
                                                other.matrix.at(row).at(col));
             }   
         }
         return *this;
    } 
    
    Matrix Matrix::operator-(const Matrix &other){
        check_same_dimentions(this->get_col(), this->get_row(), other.num_of_colums , other.num_of_rows);
        vector<double> sub_matrix;
        for (int row = 0; row < other.num_of_rows; row++)
        {
            for (int col = 0; col < other.num_of_colums; col++)
            {
                sub_matrix.push_back(this->matrix.at(row).at(col)-
                                      other.matrix.at(row).at(col));
            }   
         }
        return Matrix(sub_matrix , get_col(), get_row()); 
     }
 
    Matrix Matrix::operator-()const{   //oneri 
        vector<double> minus_matrix;
        for (int row = 0; row < get_row(); row++)
        {
            for (int col = 0; col < get_col(); col++)
            {
                minus_matrix.push_back(-this->matrix.at(row).at(col));
            }
        }
        return Matrix(minus_matrix , get_col() , get_row());   
    }

    Matrix& Matrix::operator-=(const Matrix &other){
        check_same_dimentions(this->get_col(), this->get_row(), other.num_of_colums , other.num_of_rows);
        for (int row = 0; row < other.num_of_rows; row++)
        {
            for (int col = 0; col < other.num_of_colums; col++)
            {
                this->matrix.at(row).at(col) = (this->matrix.at(row).at(col)-
                                                other.matrix.at(row).at(col));
             }   
         }
         return *this;
    } 

//*******Overloading 6-booleans operators*********//
    bool Matrix::operator>(const Matrix &other)const {
        check_same_dimentions(this->get_col(), this->get_row(), other.num_of_colums , other.num_of_rows);
        double mat_a_sum = 0, mat_b_sum = 0;
        bool flag = 1;
        for (int row = 0; row < get_row(); row++)
        {
            for (int col = 0; col < get_col(); col++)
            {
                mat_a_sum += this->matrix.at(row).at(col);
                mat_b_sum += other.matrix.at(row).at(col);
            }
            mat_a_sum > mat_b_sum ? flag = 1:flag = 0;
        }
        return flag;
    }

    bool Matrix::operator>=(const Matrix &other)const {
            check_same_dimentions(this->get_col(), this->get_row(), other.num_of_colums , other.num_of_rows);
        double mat_a_sum = 0, mat_b_sum = 0;
        bool flag = 1;
        for (int row = 0; row < get_row(); row++)
        {
            for (int col = 0; col < get_col(); col++)
            {
                mat_a_sum += this->matrix.at(row).at(col);
                mat_b_sum += other.matrix.at(row).at(col);
            }
            mat_a_sum >= mat_b_sum ? flag = 1:flag = 0;
        }
        return flag;
    }

    bool Matrix::operator<(const Matrix &other)const{
        check_same_dimentions(this->get_col(), this->get_row(), other.num_of_colums , other.num_of_rows);
        double mat_a_sum = 0, mat_b_sum = 0;
        bool flag = 1;
        for (int row = 0; row < get_row(); row++)
        {
            for (int col = 0; col < get_col(); col++)
            {
                mat_a_sum += this->matrix.at(row).at(col);
                mat_b_sum += other.matrix.at(row).at(col);
            }
            mat_a_sum < mat_b_sum ? flag = 1:flag = 0;
        }
        return flag;
    }

    bool Matrix::operator<=(const Matrix &other)const{
        check_same_dimentions(this->get_col(), this->get_row(), other.num_of_colums , other.num_of_rows);
        double mat_a_sum = 0, mat_b_sum = 0;
        bool flag = 1;
        for (int row = 0; row < get_row(); row++)
        {
            for (int col = 0; col < get_col(); col++)
            {
                mat_a_sum += this->matrix.at(row).at(col);
                mat_b_sum += other.matrix.at(row).at(col);
            }
            mat_a_sum <= mat_b_sum ? flag = 1:flag = 0;
        }
        return flag;
    }

    bool Matrix::operator==(const Matrix &other)const{
        check_same_dimentions(this->get_col(), this->get_row(), other.num_of_colums , other.num_of_rows);
        for (int row = 0; row < get_row(); row++)
        {
            for (int col = 0; col < get_col(); col++)
            {
                if (this->matrix.at(row).at(col) != other.matrix.at(row).at(col))return 0;
            }
        }
        return 1;
    }

    bool Matrix::operator!=(const Matrix &other)const {
        check_same_dimentions(this->get_col(), this->get_row(), other.num_of_colums , other.num_of_rows);
        for (int row = 0; row < get_row(); row++)
        {
            for (int col = 0; col < get_col(); col++)
            {
                if (this->matrix.at(row).at(col) != other.matrix.at(row).at(col))return 1;
            }
        }
        return 0;
    } 

//**********Overloading 2-Increament operators*****//
     Matrix & Matrix::operator++(){
        for (int row = 0; row < get_row(); row++)
            {
            for (int col = 0; col < get_col(); col++)
            {
                this->matrix.at(row).at(col)++;
            }
            } 
            return *this;  
       } 

    Matrix & Matrix::operator--(){
        for (int row = 0; row < get_row(); row++)
            {
            for (int col = 0; col < get_col(); col++)
            {
                this->matrix.at(row).at(col)--;
            }
            } 
            return *this;  
       } 

//********Overloading 3-Multiplication operators****//
    Matrix Matrix::operator*(Matrix &other){
         check_same_dimentions(this->get_col(), this->get_row(), other.num_of_colums , other.num_of_rows);
         vector<double> mult_matrix;
         for (int row = 0; row < other.num_of_rows; row++)
         {
             for (int col = 0; col < other.num_of_colums; col++)
             {
                 mult_matrix.push_back(this->matrix.at(row).at(col)*
                                      other.matrix.at(row).at(col));
             }   
         }
        return Matrix(mult_matrix , get_col(), get_row()); 
     }

    Matrix operator*(const double mul, Matrix &other) {
        vector<double> mult_mat;
        for (int row = 0; row < other.get_col(); row++)
        {
            for (int col = 0; col < other.get_col(); col++)
            {
                mult_mat.push_back(other.matrix.at(row).at(col) * mul);
            }
        }   
        return Matrix{mult_mat,3,3};
    }
 
    Matrix& Matrix::operator*=(const Matrix &other){
        for (int row = 0; row < other.num_of_rows; row++)
        {
            for (int col = 0; col < other.num_of_colums; col++)
            {
                this->matrix.at(row).at(col) = (this->matrix.at(row).at(col)*
                                                other.matrix.at(row).at(col));
             }   
         }
         return *this;
    } 
    
    Matrix& Matrix::operator*=(double mul){
        for (int row = 0; row < get_row(); row++)
        {
            for (int col = 0; col < get_col(); col++)
            {
                this->matrix.at(row).at(col) = (this->matrix.at(row).at(col)*
                                                mul);
             }   
         }
         return *this;
    } 
    
//*******input and output operators********//
ostream &operator<<(ostream& out, const Matrix &matrix){
    string answer;
    for (int row = 0; row < matrix.num_of_rows; row++)
    {
        for (int col = 0; col < matrix.num_of_colums; col++)
        {
            answer += to_string(matrix.matrix.at(row).at(col));
        }
        answer += '\n';   
    }
    return out << answer;
}

istream &operator>>(istream& in , Matrix &matrix){
    return in;
    }
 }

//  int main(){
//     cout << "****test to addition of two matrix: operator '+'" << endl;
//     vector<double> a = {1,0,0,0,1,0,0,0,1};
//     vector<double> b = {2,0,0,0,2,0,0,0,2};
//     vector<double> mistake_add = {2,0,0};
//     zich::Matrix a_{a,3,3};
//     zich::Matrix b_{b,3,3};
//     zich::Matrix mist{mistake_add,1,3};
//     cout << (a_+b_) << endl;
//     //cout << (a_ + mist) << endl;
//     cout << "******* test to oneri addition : operator (+)" << endl;
//     cout << +a_ << endl;
//     cout << a_ << endl;
//     cout << "******* test to addition : operator (+=)" << endl;
//     a_ += a_;
//     cout << a_ <<endl;
//     cout << "******* test to sub : operator '-'" << endl;
//     cout << a_ - b_ << endl;
//     cout << "******* test to oneri minus : operator (-)" << endl;
//     cout << (-b_) << endl;
//     cout << "******* test to addition : operator (-=)" << endl;
//     cout << a_ << endl;
//     b_ -= a_;
//     cout << b_ <<endl;
//     cout << "******* test to operator (>)" << endl;
//     zich::Matrix c_{b,3,3};
//     cout << b_ << endl;
//     cout << c_ << endl;
//     cout << (c_ > b_) << endl;
//     cout << "******* test to operator (>)" << endl;
//     cout << (a_ >= b_) << endl;
//     cout << "******* test to operator (==)" << endl;
//     cout << c_ << endl;
//     cout << a_ << endl;
//     cout << (a_ == c_) << endl;
//     cout << "******* test to operator (scalar * matrix)" << endl;
//     cout << (3 * a_) << endl;
//     cout << "******* test to operator (*=)" << endl;
//     cout << c_ << endl;
//     cout << a_ << endl;
//     a_ *= c_;
//     cout << a_ << endl;
//     cout << "******* test to operator (*=scalar)" << endl;
//     a_ *= 3;
//     cout << a_ <<endl;
//     cout << "******* test to operator (-- and ++)" << endl;
//     cout << c_ << endl;
//     ++c_;
//     cout << c_ <<endl;
//     --c_;
//     cout << c_ <<endl;
//  }