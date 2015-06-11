/*
 * data.h
 *
 *  Created on: Jun 11, 2015
 *      Author: malatawy15
 */

#ifndef DATA_H_
#define DATA_H_

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/tokenizer.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace boost::numeric::ublas;
using namespace std;

typedef boost::tokenizer< boost::char_separator<char> > t_tokenizer;

template <class T>
class Data {
public:
	Data(string file_name, char* delimiter = " ,\n") {
		ifstream file(file_name, ifstream::in);
		boost::char_separator<char> sep(delimiter);
		char str[1000000];
		file.getline(str, sizeof(str));
		t_tokenizer tokens(string(str), sep);
		int num_cols = 0;
		for (t_tokenizer::iterator beg = tokens.begin(); beg != tokens.end(); ++beg) {
			printf("TOK: %s\n", (*beg).c_str());
			column_titles_.push_back(*beg);
			num_cols++;
		}
		printf("==============================\n");
		while(file>>str) {
			//input()
			int j = num_cols-2;
			while(j-- --> 0) {

			}
			printf("%s\n", str);
		}
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
