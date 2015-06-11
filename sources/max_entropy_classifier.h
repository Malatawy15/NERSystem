/*
 * max_entropy_classifier.h
 *
 *  Created on: Jun 10, 2015
 *      Author: malatawy15
 */

#ifndef NERYOUTUBE_MAX_ENTROPY_CLASSIFIER_H_
#define NERYOUTUBE_MAX_ENTROPY_CLASSIFIER_H_

#include "data.h"

template <class T = Data<class T1> >
class MaxEntropyClassifier {
public:
	MaxEntropyClassifier(T data);
};



#endif /* NERYOUTUBE_MAX_ENTROPY_CLASSIFIER_H_ */
