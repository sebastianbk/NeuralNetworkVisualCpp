# NNVC++

This is a simple implementation of an Artificial Neural Network in C++ (specifically Visual C++). It supports multiple hidden layers for training deep networks as well as a set of different activation/transfer functions.

It is inspired by [David Miller's sample](http://www.millermattson.com/dave/?p=54) but is quite a lot more readable, as classes have been divided into separate files. Moreover, this implementation offers a few more options for customization of the network. It also accepts command-line arguments for quickly running the network on a sample dataset.

While a variety of different activation functions can be used (e.g., sigmoid, tanh, binary step, softsign, etc.), there is no support for applying a separate function only for the output layer. To improve this program, one could make it possible to apply a function such as the softmax function only for the output neurons.

## Sample Data Source

I have previously [implemented a Neural Network in C#](https://github.com/sebastianbk/BreastCancerNeuralNetwork) and used it for training a model based on the Wisconsin Breast Cancer Diagnostic dataset. The dataset has been formatted specifically for this program and can be found in the files `sample_input.txt` and `sample_target.txt`.

Created by researchers at the University of Wisconsin, the features in the data set are computed from a digitized image of a fine needle aspirate (FNA) of a breast mass. They describe characteristics of the cell nuclei present in the image.

In this example, the data set has been slightly re-formatted. The sample files do not include the ID number of each observation. Moreover, the original class variable has been re-encoded in the following manner:

	2 => 1,0
	4 => 0,1

The original dataset can be found here: http://archive.ics.uci.edu/ml/datasets/Breast+Cancer+Wisconsin+%28Diagnostic%29

a) Creators: 

	Dr. William H. Wolberg, General Surgery Dept., University of
	Wisconsin,  Clinical Sciences Center, Madison, WI 53792
	wolberg@eagle.surgery.wisc.edu

	W. Nick Street, Computer Sciences Dept., University of
	Wisconsin, 1210 West Dayton St., Madison, WI 53706
	street@cs.wisc.edu  608-262-6619

	Olvi L. Mangasarian, Computer Sciences Dept., University of
	Wisconsin, 1210 West Dayton St., Madison, WI 53706
	olvi@cs.wisc.edu 

b) Donor: Nick Street

c) Date: November 1995
