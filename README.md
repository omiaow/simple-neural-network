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
### _result:_
If we run the `simple-neural-network.cpp` program, we will get next outputs:
```
output values after trainings
0.00722608
0.00496353
0.992815
0.98955

output value of new input [1, 0, 0]
0.999947
```
First four numbers are the trained output values.\
As you may see, `0.00722608` and `0.00496353` are close to zero.\
While `0.992815` and `0.98955` are close to one.\
This means that we have trained our neurons for the expected outputs in the table [0] [0] [1] [1].\

Now, the last number shows the result of our task.\
`0.999947` is close to one, the output of `input-5` will be one.

### _solution:_
input name | inputs | outputs
---------- | ------ | -------
input-5 | [1, 0, 0] | [1]

----------------------------------------------------------------------
## program
To read the code, you need to understand some mathematical operations as: __sigmoid__, __derivative of sigmoid__, __dot product__, __matrix transpose__, etc.\
If you know them, you can follow the [simple-neural-network.cpp code](https://github.com/omiaow/simple-neural-network/blob/main/simple-neural-network.cpp) reading the comments above.

## Thank you for attention!
