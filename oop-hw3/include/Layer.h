#ifndef OOP_HW3_LAYER_H
#define OOP_HW3_LAYER_H

#include "Activation.h"
#include "Matrix.h"


class Layer{
private:
    Matrix weights;
    Matrix biases;
    const Activation& activation;
    int inputSize;
    int outputSize;

public:
    Layer(int inputSize, int outputSize, const Activation& activation);
    Matrix forward(const Matrix& input) const;
    void initializeWeights();
    int getInputSize() const { return inputSize;}
    int getOutputSize() const{ return outputSize;}
    const Activation& getActivation() const {return activation;}

};

#endif //OOP_HW3_LAYER_H
