#include <iostream>
#include "../include/Matrix.h"
#include "../include/Activation.h"
#include "../include/Layer.h"
#include "../include/Network.h"

using std::cout;
using std::endl;

int main() {
    // Create activation functions
    Activation relu{"relu"};
    Activation sigmoid{"sigmoid"};

    // Create a simple neural network for XOR problem
    // Input layer: 2 neurons
    // Hidden layer: 3 neurons with ReLU activation
    // Output layer: 1 neuron with Sigmoid activation

    // Create layers
    Layer hiddenLayer{2, 3, relu};
    Layer outputLayer{3, 1, sigmoid};

    // Create network with a maximum of 2 layers and add layers
    Network network{2};
    network.addLayer(&hiddenLayer);
    network.addLayer(&outputLayer);

    cout << "Neural Network with " << network.getLayerCount() << " layers created." << endl;

    // Create input data for XOR problem
    // [0,0], [0,1], [1,0], [1,1]
    Matrix input{4, 2};
    input[0][0] = 0.0f; input[0][1] = 0.0f;
    input[1][0] = 0.0f; input[1][1] = 1.0f;
    input[2][0] = 1.0f; input[2][1] = 0.0f;
    input[3][0] = 1.0f; input[3][1] = 1.0f;

    cout << "Input data: " <<endl;
    input.print();

    // Forward pass through the network
    Matrix output = network.forward(input);

    cout << "Network output: " <<endl;
    output.print();

   cout << "Note: Since weights are randomly initialized, the output won't match XOR truth table yet." << endl;
   cout << "Training would be needed to adjust weights for correct predictions." << endl;

    return 0;
}