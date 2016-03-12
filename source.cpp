#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;
class Matrix{
public:
	Matrix(){
		lines = columns = 0;
		elements = nullptr;
	}
	Matrix(int _lines, int _columns){
		lines = _lines;
		columns = _columns;
		elements = new int*[lines];
		for (int i = 0; i < lines; i++){
			elements[i] = new int[columns];
			for (int j = 0; j < columns; j++){
				elements[i][j] = 0;
			}
		}
	}
	Matrix(const Matrix &matrix){
		lines = matrix.lines;
		columns = matrix.columns;
		elements = new int*[lines];
		for (int i = 0; i < lines; i++){
			elements[i] = new int[columns];
			for (int j = 0; j < columns; j++){
				elements[i][j] = matrix.elements[i][j];
			}
		}
	}
	void fill(char *filename){
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
	void fillRandom(){
		srand (time(NULL));
		for (int i = 0; i < lines; i++)
			for (int j = 0; j < columns; j++)
				elements[i][j] = rand() %100;
	}
	void print() const {
		for (int i = 0; i < lines; i++){
			for (int j = 0; j < columns; j++){
				cout << elements[i][j] << " ";
			}
			cout << "\n";
		}
	}
	int getLines() const{
		return lines;
	}
	int getColumns() const{
		return columns;
	}
	Matrix operator=(Matrix& second){
		if (this != &second) {
			Swap(*this, second);
		}
		return *this;
	}
	int* operator[](int index){
		return elements[index];
	}
	Matrix operator+(Matrix& m) const{
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
	Matrix operator*(Matrix &m) const{
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
	~Matrix(){
		for (int i = 0; i < lines; i++){
			delete [] elements[i];
		}
		delete [] elements;
	}
	friend void Swap(Matrix &first, Matrix &second);
private:
	int lines, columns;
	int **elements;
};
void Swap(Matrix &first, Matrix &second){
	swap(first.lines, second.lines);
	swap(first.columns, second.columns);
	swap(first.elements, second.elements);
}
int main(){
	Matrix h(3, 3);
	Matrix m(3, 3);
	h.fill("C:\\1\\1.txt");
	m.fill("C:\\1\\1.txt");
	(m+h).print();
	(m*h).print();
	system("pause");
	return 0;
}