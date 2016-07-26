# NNVC++

This is a simple implementation of an Artificial Neural Network in C++ (specifically Visual C++). It supports multiple hidden layers for training deep networks as well as a set of different activation/transfer functions.

It is inspired by [David Miller's sample](http://www.millermattson.com/dave/?p=54) but is quite a lot more readable, as classes have been divided into separate files. Moreover, this implementation offers a few more options for customization of the network. It also accepts command-line arguments for quickly running the network on a sample dataset.

While a variety of different activation functions can be used (e.g., sigmoid, tanh, binary step, softsign, etc.), there is no support for applying a separate function only for the output layer. To improve this program, one could make it possible to apply a function such as the softmax function only for the output neurons.

## Usage

Start by cloning the repository and build it by your favorite C++ compiler. Only standard C++11 features have been used so you can use any modern compiler. You could also just [download a pre-built release](https://github.com/sebastianbk/NeuralNetworkVisualCpp/releases/) if you are on Windows.

You need to split up your dataset into two files: one with the input values and one with the target output values. The files need to be ANSI encoded on Windows. Here is an example of what the input file could look like:

	5 1 1 1 2 1 3 1 1
	5 4 4 5 7 10 3 2 1
	3 1 1 1 2 2 3 1 1
	6 8 8 1 3 4 3 7 1
	4 1 1 3 2 1 3 1 1
	8 10 10 8 7 10 9 7 1
	1 1 1 1 2 10 3 1 1
	2 1 2 1 2 1 3 1 1
	2 1 1 1 2 1 1 1 5
	4 2 1 1 2 1 2 1 1

And here is a snippet of a sample target output file:

	1 0
	1 0
	1 0
	1 0
	1 0
	0 1
	1 0
	1 0
	1 0
	1 0

You also need to decide whether you want to apply the sigmoid function (`sig`) or the hyperbolic tangent function (`tanh`) for activation. If you are interested in using other activation functions you can just go ahead and implement them in the `Functions` namespace.

Finally, you need to specify the topology of the network. You need at least one hidden layer but you could have more. As an example, here's the format that specifies a topology with 9 input neurons, 7 hidden neurons and 2 output neurons:

	9 7 2

Now, execute the program with the following parameters:

	NeuralNetworkVisualCpp.exe <path_to_input.txt> <path_to_target_output.txt> <activation-function> <topology>

Example:

	NeuralNetworkVisualCpp.exe C:\Temp\input.txt C:\Temp\format.txt sig 9 7 2

This will execute the program and start training the network by incrementally applying the backpropogation algorithm.

## Todo List

Some of the things I am thinking of implementing include:

* More activation functions.
* Being able to export the network weights.
* Being able to import weights and simple apply them to a new network for making predictions.
* Allowing for applying a separate activation function for the output layer.
* Decreasing the memory footprint.

Since this is mostly an educational project for myself I do not have any timeline for the implementation of these ideas.

## Sample Data Source to Test the Program

I have previously [implemented a Neural Network in C#](https://github.com/sebastianbk/BreastCancerNeuralNetwork) and used it for training a model based on the Wisconsin Breast Cancer Diagnostic dataset. The dataset has been formatted specifically for this program and can be found in the files `sample_input.txt` and `sample_target.txt`.

Created by researchers at the University of Wisconsin, the features in the data set are computed from a digitized image of a fine needle aspirate (FNA) of a breast mass. They describe characteristics of the cell nuclei present in the image.

In this example, the data set has been slightly re-formatted. The sample files do not include the ID number of each observation. Moreover, the original class variable has been re-encoded in the following manner:

	2 => 1 0
	4 => 0 1

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
