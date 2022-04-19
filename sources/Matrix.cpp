#include <stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>
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
     /** check if the matrices can multiply **/
    void check_can_multiply(int col , int row){
        if ( col != row){
            throw invalid_argument("matrices can't multiply ");
        }
    }
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
 
    Matrix Matrix::operator-()const{   //onari 
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
        double mat_a_sum = 0;
        double mat_b_sum = 0;
        bool flag = true;
        for (int row = 0; row < get_row(); row++)
        {
            for (int col = 0; col < get_col(); col++)
            {
                mat_a_sum += this->matrix.at(row).at(col);
                mat_b_sum += other.matrix.at(row).at(col);
            }
            mat_a_sum > mat_b_sum ? flag = true:flag = false;
        }
        return flag;
    }

    bool Matrix::operator>=(const Matrix &other)const {
            check_same_dimentions(this->get_col(), this->get_row(), other.num_of_colums , other.num_of_rows);
        double mat_a_sum = 0;
        double mat_b_sum = 0;
        bool flag = true;
        for (int row = 0; row < get_row(); row++)
        {
            for (int col = 0; col < get_col(); col++)
            {
                mat_a_sum += this->matrix.at(row).at(col);
                mat_b_sum += other.matrix.at(row).at(col);
            }
            mat_a_sum >= mat_b_sum ? flag = true:flag = false;
        }
        return flag;
    }

    bool Matrix::operator<(const Matrix &other)const{
        check_same_dimentions(this->get_col(), this->get_row(), other.num_of_colums , other.num_of_rows);
        double mat_a_sum = 0;
        double mat_b_sum = 0;
        bool flag = true;
        for (int row = 0; row < get_row(); row++)
        {
            for (int col = 0; col < get_col(); col++)
            {
                mat_a_sum += this->matrix.at(row).at(col);
                mat_b_sum += other.matrix.at(row).at(col);
            }
            mat_a_sum < mat_b_sum ? flag = true:flag = false;
        }
        return flag;
    }

    bool Matrix::operator<=(const Matrix &other)const{
        check_same_dimentions(this->get_col(), this->get_row(), other.num_of_colums , other.num_of_rows);
        double mat_a_sum = 0;
        double mat_b_sum = 0;
        bool flag = true;
        for (int row = 0; row < get_row(); row++)
        {
            for (int col = 0; col < get_col(); col++)
            {
                mat_a_sum += this->matrix.at(row).at(col);
                mat_b_sum += other.matrix.at(row).at(col);
            }
            mat_a_sum <= mat_b_sum ? flag = true:flag = false;
        }
        return flag;
    }

    bool operator==(Matrix const &curr , Matrix const &other){
        check_same_dimentions(curr.get_col(), curr.get_row(), other.get_col() , other.get_row());
        for (int row = 0; row < curr.get_row(); row++)
        {
            for (int col = 0; col < curr.get_col(); col++)
            {
                if (curr.matrix.at(row).at(col) != other.matrix.at(row).at(col))
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool operator!=(const Matrix &curr , const Matrix &other) {
        //check_same_dimentions(this->get_col(), this->get_row(), other.num_of_colums , other.num_of_rows);
        return !(curr == other);
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
    Matrix Matrix::operator*(const Matrix &other){
         check_can_multiply(this->get_col() , other.num_of_rows);
         vector<double> mult_matrix;
         int new_col = this->get_row();
         int new_row = other.get_col();
         //mult_matrix.resize(new_col * new_row);
         int sum =0;
         for (int row = 0; row < this->get_row(); row++)
             {
            for (int col = 0; col < other.get_col(); col++)
            {
                 for (int e = 0; e < other.get_row(); e++)
                 {
                     sum += (this->matrix.at(row).at(e)) * (other.matrix.at(e).at(col));
                 }
                 mult_matrix.push_back(sum);
                 sum = 0; 
             }             
              }    
        return Matrix(mult_matrix , new_col, new_row); 
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
        return Matrix(mult_mat,other.get_col(),other.get_col());
    }
 
    Matrix& Matrix::operator*=(const Matrix &other){
         check_can_multiply(this->get_col() , other.num_of_rows);
        *this = *this * other;
         return *this;
    } 
        Matrix Matrix::operator*(const double mul)const{
        vector<double> mult_mat;
        for (int row = 0; row < this->get_row(); row++)
        {
            for (int col = 0; col < this->get_col(); col++)
            {
                mult_mat.push_back(this->matrix.at(row).at(col) * mul);
            }
        }   
        return Matrix(mult_mat,this->get_row(),this->get_col());
    }
    Matrix& Matrix::operator*=(const double mul){
            *this=*this*mul;
        return *this;
        }

   
//*******input and output operators********//
    ostream &operator<<(ostream &out, const Matrix& matrix){
        for (int i = 0; i < matrix.get_row(); i++)
        {
            out <<"[";
            for (int j = 0; j < matrix.get_col(); j++)
            {
               out << matrix.matrix.at(i).at(j);
               if (j!=matrix.num_of_colums-1)
               {
                    out <<" ";
               }
            }
            out <<"]";

            if (i!=matrix.num_of_rows-1)
            {
                out << "\n";
            }
        } 
        return out ;
    }
istream &operator>>(istream &in, Matrix &matrix){
    string text;
    string current_line;
    string vector;
    int num_of_row = 0;
    string mat;
    std::vector<double> vec;
     while(getline(in,current_line)){
            text+=current_line;
        }
    for (uint i = 0; i < text.size()-1; i++)
    {
        if((text.at(i) == '[' && text.at(i+1) == ' ')|| (text.at(i) == '[' && text.at(i+1) == ',')){
            __throw_invalid_argument("error");
        }
        if(text.at(i) == ']' && text.at(i+1) != ','){
            __throw_invalid_argument("error");
        }
        if(text.at(i) == ',' && text.at(i+1) != ' '){
            __throw_invalid_argument("error");
        }
        if (text.at(i) == '['){
            num_of_row++;
        }
        if (isdigit(text.at(i)) != 0 || text.at(i) == ' ' || text.at(i) == ',')
        {
            mat += text.at(i);
        }
    }
        string current_num;
        int num_of_col = 0;
        int counter = 0;
        //bool flag = true;
        for (uint i =0; i<mat.length(); i++){
            counter++;
            // if (mat.at(i) == ',' && flag ){
            //     num_of_col = counter;
            //     flag = false;
            // }
            
            if (isdigit(mat.at(i)) != 0)
            {
                current_num += mat.at(i);
            }
            if((mat.at(i) == ' ') || i == mat.length()-1)
            {
                vec.push_back(stod(current_num));
                current_num.clear();
            }

        }
    matrix = Matrix{vec,3,4};
    return in;
 
}
 }
//  int main(){
//     zich::Matrix mat1{{1,1,1,1,0,0,0,0,1},3,3};
//     istringstream is7{"[1 1 1 1], [1 1 1 1], [1 1 1 1]\n"};
//     is7 >> mat1;
//     cout << "****test to addition of two matrix: operator '+'" << endl;
//     vector<double> mistake_add = {2,0,0};
//     zich::Matrix a_{{1,2,3,4,5,6,7,8,9},3,3};
//     zich::Matrix b_{{9,8,7,6,5,4,3,2,1},3,3};
//     zich::Matrix mist{mistake_add,1,3};
//     cout << (a_+b_) << endl;
//     //cout << (a_ + mist) << endl;
//     cout << "******* test to oneri addition : operator (+)" << endl;
//     cout << +a_ << endl;
//     cout << a_ << endl;
//     cout << "******* test to addition : operator (+=)" << endl;
//     a_ = {{5,5,5,5,5,5,5,5,5},3,3};
//     cout << a_ << endl;
//     a_ += a_;
//     cout << "a_ += a_ = " <<endl;
//     cout << a_ << endl;
//     b_ = {{2,2,2,1,1,1,3,3,3},3,3};
//     a_ += b_;
//     cout << a_ << endl;
//     cout << "******* test to sub : operator '-'" << endl;
//     cout << a_ - b_ << endl;
//     cout << a_ - a_ << endl;
//     cout << "******* test to onari minus : operator (-)" << endl;
//     cout << (-b_) << endl;
//     cout << "******* test to addition : operator (-=)" << endl;
//     cout << a_ << endl;
//     b_ -= a_;
//     cout << b_ <<endl;
//     b_ -= b_;
//     cout << b_ << endl;
//     cout << "******* test to operator (>)" << endl;
//     zich::Matrix c_{{1,1,1,1,1,1,1,1,1},3,3};
//     cout << b_ << endl;
//     cout << c_ << endl;
//     cout << (c_ > b_) << endl;
//     cout << "******* test to operator (>=)" << endl;
//     cout << (a_ >= b_) << endl;
//     cout << "******* test to operator (==)" << endl;
//     cout << c_ << endl;
//     cout << a_ << endl;
//     cout << (a_ == c_) << endl;
//     cout << "******* test to operator (scalar * matrix)" << endl;
//     cout << a_ << endl;
//     cout << (3 * a_) << endl;
//     cout << "******* test to operator (*=)" << endl;
//     zich::Matrix k{{1,2,3,4,5,6},2,3};
//     zich::Matrix t{{7,8,9,10,11,12},3,2};
//     cout << k << endl;
//     cout << t << endl;
//     k *= t;
//     cout << k << endl;
//     cout << "******* test to operator (*=scalar)" << endl;
//     a_ *= 3;
//     cout << a_ <<endl;
//     cout << "******* test to operator (-- and ++)" << endl;
//     cout << c_ << endl;
//     ++c_;
//     cout << c_ <<endl;
//     --c_;
//     cout << c_ <<endl;
//     c_++;
//     cout << c_ << endl;
//     c_--;
//     cout << c_ <<endl;
//     cout << "*******88 test (*)**********"<<endl;
//         zich::Matrix rr_{{1,2,3,4,5,6},2,3};
//         zich::Matrix ss_{{7,8,9,10,11,12},3,2};
//     cout << rr_ << endl;
//     cout << ss_ << endl;
//     cout << rr_ * ss_ << endl;
//     zich::Matrix mat_identity_3{{1,0,0,0,1,0,0,0,1},3,3};
//     cout << mat_identity_3 * mat_identity_3 << endl;
//     vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
//     zich::Matrix mat_1{identity,3,3};
//     cout << mat_1*4 <<endl;
//     cout << mat_1*7 <<endl;
//     zich::Matrix niss{{1,2,3,4,5,6,7,8,9},3,3};
//     cout << niss * 4 << endl;
//     std::vector<double> arr_e= {4, 0, 0, 0, 4, 0, 0, 0, 4, 0, 0, 0};
//  }
 