#include "../include/Layer.h"
#include <cstdlib>
#include <ctime>
#include <stdexcept>

Layer:: Layer(int inputSize, int outputSize, const Activation& activation)
    : weights(inputSize,outputSize),
      biases(1, outputSize),
      activation(activation),
      inputSize(inputSize),
      outputSize(outputSize){

    initializeWeights();
}

Matrix Layer::forward(const Matrix &input) const {
    if(input.getCols() !=inputSize) {
        throw std::invalid_argument("Input dimensions do not match");
    }
    Matrix weighted = input * weights;
    Matrix result(weighted.getRows(), weighted.getCols());

    for(int i=0; i<weighted.getRows(); i++){
        for(int j=0; j<weighted.getCols(); j++){
            float value = weighted[i][j] + biases[0][j];
            result[i][j] = activation(value);
        }
    }
    return result;
}

void Layer:: initializeWeights(){
    static bool seeded = false;
    if (!seeded) {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        seeded=true;
    }
    for (int i = 0; i < inputSize; i++) {
        for (int j = 0; j < outputSize; j++) {
            // Generate small random number between -0.5 and 0.5
            weights[i][j] = (static_cast<float>(rand()) / RAND_MAX) - 0.5f;
        }
    }

    // Initialize biases to 0
    for (int j = 0; j < outputSize; j++) {
        biases[0][j] = 0.0f;
    }
}
