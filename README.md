# Implementation of neural network from scratch in C++
## perceptron

![illustration of our perceptron](https://github.com/omiaow/simple-neural-network/blob/main/figure.png)

In our case, the activation function is Sigmoid: `f(x) = 1 / (1 + exp(-x))`.\
By this function, we will check and train the weights (synaptics).

## Our goal is to understand how the neural network works in practice
### _example:_
Let us have a list of inputs and their outputs.

input name | inputs | outputs
---------- | ------ | -------
input-1 | [0, 0, 1] | [0]
input-2 | [0, 1, 1] | [0]
input-3 | [1, 1, 1] | [1]
input-4 | [1, 0, 1] | [1]


Now, the question is what will be the out of new `input-5`.

input name | inputs | outputs
---------- | ------ | -------
input-5 | [1, 0, 0] | ?       

----------------------------------------------------------------------