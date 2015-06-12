/*
 * max_entropy_classifier.h
 *
 *  Created on: Jun 10, 2015
 *      Author: malatawy15
 */

#ifndef NERYOUTUBE_MAX_ENTROPY_CLASSIFIER_H_
#define NERYOUTUBE_MAX_ENTROPY_CLASSIFIER_H_

#include "data.h"

#include <boost/range/detail/any_iterator.hpp>
#include <map>
#include <math.h>

using boost::range_detail::any_iterator;

template <class T>
class MaxEntropyClassifier {
public:
	MaxEntropyClassifier(Data<T> data);
	T classify(matrix_row<T> input);
private:
	class Node {
	public:
		Node(int col);
		Node(T out);
	private:
		int col_index_;
		map<T, Node*> children_;
		bool is_final_;
		T output_;
	};
	void build_classifier(Data<T> data);

	template <typename IterType>
	double calculate_entropy(IterType it) {
		double entropy = 0.0;
		for (auto i : it) {
			entropy += (i * log2(i));
		}
		return entropy * -1;
	}

	template <typename IterType>
	double calculate_expected_entropy(IterType it) {

	}

	template <typename IterType>
	double calculate_information_gain(IterType it);

};

#endif /* NERYOUTUBE_MAX_ENTROPY_CLASSIFIER_H_ */
