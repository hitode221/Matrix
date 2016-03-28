#include <time.h>
#include "matrix.h"
using namespace std;
	
Matrix :: Matrix(int _lines, int _columns) : elements(new int *[_lines]), lines(_lines), columns(_columns) {
	for (int i = 0; i < lines; i++){
		elements[i] = new int[columns];
		for (int j = 0; j < columns; j++){
			elements[i][j] = 0;
		}
	}
}
Matrix :: Matrix(const Matrix &matrix) : elements(new int *[matrix.lines]), lines(matrix.lines), columns(matrix.columns) {
	for (int i = 0; i < lines; i++){
		elements[i] = new int[columns];
		for (int j = 0; j < columns; j++){
			elements[i][j] = matrix.elements[i][j];
		}
	}
}
void Matrix :: swapMatrix(Matrix &second){
	swap(lines, second.lines);
	swap(columns, second.columns);
	swap(elements, second.elements);
}
void Matrix :: fill(char *filename){
	fstream file(filename);
	if (!file.is_open()){
		cout << "Error opening file";
		return;
	}
	for (int i = 0; i < lines; i++){
		for (int j = 0; j < columns; j++){
			file >> elements[i][j];
		}
	}
}
void Matrix :: fillRandom(){
	srand (time(NULL));
	for (int i = 0; i < lines; i++)
		for (int j = 0; j < columns; j++)
			elements[i][j] = rand() %100;
}
void Matrix :: print() const {
	for (int i = 0; i < lines; i++){
		for (int j = 0; j < columns; j++){
			cout << elements[i][j] << " ";
		}
		cout << "\n";
	}
}
int Matrix :: getLines() const{
		return lines;
}
int Matrix :: getColumns() const{
		return columns;
}
Matrix& Matrix :: operator=(const Matrix& second){
	if (this != &second) {
		Matrix(second).swapMatrix(*this);
	}
	return *this;
}
int* Matrix :: operator[] (int index) const{
	return elements[index];
}
Matrix Matrix :: operator+(const Matrix& m) const{
	if (columns != m.columns || lines != m.lines){ 
		throw invalid_argument("Matrix cannot be added");
	}
	Matrix temp(lines, columns);
	for (int i = 0; i < lines; i++){
		for (int j = 0; j < columns; j++){
			temp[i][j] = elements[i][j] + m[i][j];
		}
	}
	return temp;
}
Matrix Matrix :: operator*(const Matrix &m) const{
	if (columns != m.lines){
		throw invalid_argument("Matrix cannot be multiplicated");
	}
	Matrix result(lines, m.columns);
	for (int i = 0; i < lines; i++){
		for (int j = 0; j < m.columns; j++){
			result[i][j] = 0;
			for (int k = 0; k < m.lines; k++){
				result[i][j] += elements[i][k] * m[k][j];
			}
		}
	}
	return result;
}
Matrix :: ~Matrix(){
	for (int i = 0; i < lines; i++){
		delete [] elements[i];
	}
	delete [] elements;
}
