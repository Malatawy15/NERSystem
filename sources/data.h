/*
 * data.h
 *
 *  Created on: Jun 11, 2015
 *      Author: malatawy15
 */

#ifndef DATA_H_
#define DATA_H_

#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/tokenizer.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace boost::numeric::ublas;
using namespace std;

typedef boost::tokenizer< boost::char_separator<char> > t_tokenizer;

template <typename CALLABLE, class T>
matrix<T> apply_elementwise(const CALLABLE& func, const matrix<T>& mat)
{
   matrix<T> result(mat.size1(), mat.size2());
   std::transform(mat.data().begin(), mat.data().end(), result.data().begin(), func);
   return result;
}


inline int count_lines(string file_name) {
	std::ifstream f(file_name);
	std::string line;
	int i = 0;
	for (; std::getline(f, line); ++i);
	f.close();
	return i - 1;
}

template <class T = string>
class Data {
public:
	Data(string file_name, char* delimiter = " ,\n") {
		int num_rows = count_lines(file_name), num_cols = 0;
		ifstream file(file_name, ifstream::in);
		boost::char_separator<char> sep(delimiter);
		char str[1000000];
		file.getline(str, sizeof(str));
		t_tokenizer tokens(string(str), sep);
		for (t_tokenizer::iterator beg = tokens.begin(); beg != tokens.end(); ++beg) {
			printf("COL: %s\n", (*beg).c_str());
			column_titles_.push_back(*beg);
			num_cols++;
		}
		printf("==============================\n");
		input_ = matrix<T>(num_rows, num_cols - 1);
		output_ = matrix<T>(num_rows, 1);
		T inp;
		int i = 0;
		while(file>>inp) {
			input_(i, 0) = inp;
			int j = 0;
			while(j++ < num_cols-2) {
				file>>inp;
				input_(i, j) = inp;
			}
			file>>inp;
			output_(i, 0) = inp;
			i++;
		}
		cout<<input_<<endl;
		cout<<output_<<endl;
		file.close();
	}
	matrix<T> input() {return input_;};
	matrix<T> output() {return output_;};
	matrix<T> column_titles() {return column_titles_;};
private:
	matrix<T> input_;
	matrix<T> output_;
	std::vector<string> column_titles_;
	bool is_number(string num) {
		try {
			double number = stod(num);
			return true;
		} catch (exception& e) {
			cout<<e.what()<<endl;
			return false;
		}
	}
};

#endif /* DATA_H_ */
