#pragma once
#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <map>

using namespace std;

namespace zich
{
    class Matrix
    {   
    private:
        int num_of_rows;
        int num_of_colums;

    public:
        std::map<int, std::map<int, int>> matrix;
        int get_row() const { return num_of_rows; }
        int get_col() const { return num_of_colums; }
        Matrix(vector<double> other, int other_rows, int other_colums)
        {
            if (other.size() != other_rows*other_colums)
            {
                __throw_invalid_argument("can't to initilize the matrix");
            }
            if ( other_colums < 0 || other_rows < 0){
                __throw_invalid_argument("bad input");
            }
            
            this->num_of_rows = other_rows;
            this->num_of_colums = other_colums;
            int counter = 0 ;
            for (int row = 0; row < this->num_of_rows; row++)
            {
                for (int col = 0; col < this->num_of_colums; col++)
                {
                    this->matrix[row][col] = other.at((double)col+row*this->num_of_colums);
                    counter++;
                }
            }
        }
        //~Matrix();

        /**
         * @brief Overloading 6-arithmetic operators
         * the functions get arguments with const because they don't modified!
         * Matrix functions:the Matrix functions return a matrix by value and we need to build matrix with this values
         * we don't return the matrix by reference because the memory destroyed when the function end
         * Matrix& functions: the functions returns a matrix by refernce .
         */
        // binary operator 
        Matrix operator+(const Matrix &other); 
        Matrix operator-(const Matrix &other); 
        Matrix& operator+=(const Matrix &other); 
        Matrix& operator-=(const Matrix &other); 
        // onari operator
        Matrix operator+() const;
        Matrix operator-() const; 
        /**
         * @brief 
         */
        bool operator>(const Matrix &other) const;
        bool operator>=(const Matrix &other)const;
        bool operator<(const Matrix &other)const;
        bool operator<=(const Matrix &other)const;
        //bool operator==(const Matrix &other)const;
        friend bool operator==(Matrix const &curr ,Matrix const &other);
        friend bool operator!=(Matrix const &curr , Matrix const &other);

        //int & operator()(int colum, int row);
        /**
         * @brief Increament operators
         */
        Matrix & operator++();
        Matrix operator++(int)
        {
            Matrix temp(*this);
            ++(*this);
            return temp;
        }
        Matrix & operator--();
        Matrix operator--(int){//after - by value because firstly i return the value and after that reduce by 1
            Matrix temp(*this);
            --(*this);
            return temp;
        }
        

        /**
         * @brief matrixs Multiplication
         */
        Matrix operator*(const Matrix &other);
        friend Matrix operator*(const double mul,Matrix &other);
        Matrix& operator*=(const Matrix &other);
        Matrix operator*(const double mul)const;
        Matrix& operator*=(const double mul);
    
        // Matrix operator*(double scalar);
        /**
         * @brief input and output operators
         */
        friend ostream &operator<<(ostream &out, const Matrix &matrix);
        friend istream &operator>>(istream &in, Matrix &matrix);
    };
}