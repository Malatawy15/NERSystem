/*
 * main.cc
 *
 *  Created on: Jun 11, 2015
 *      Author: malatawy15
 */

#include "sources/data.h"
#include "sources/max_entropy_classifier.h"

#include <stdio.h>
#include <Python.h>

int main() {
	Data<string> data("training_set.txt");
	Py_Initialize();
	PyRun_SimpleString("from time import time,ctime\n"
						"print 'Today is',ctime(time())\n");
	Py_Finalize();
	//MaxEntropyClassifier<Data<string> > mec();
}
