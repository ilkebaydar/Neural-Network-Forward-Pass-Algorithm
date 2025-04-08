#include "../include/Activation.h"
#include <cmath>
#include <stdexcept>


Activation::Activation(const std::string& type) : type(type) {
    // Validate activation function type
    if (type != "relu" && type != "sigmoid") {
        throw std::invalid_argument("Unsupported activation function type");
    }
}

// ReLU activation
float Activation::relu(float x) const {
    return std::max(0.0f, x);
}

// Sigmoid activation
float Activation::sigmoid(float x) const {
    return 1.0f / (1.0f + std::exp(-x));
}

// Function call operator to apply the activation
float Activation::operator()(float x) const {
    if (type == "relu") {
        return relu(x);
    } else if (type == "sigmoid") {
        return sigmoid(x);
    }

    // This should never happen due to constructor validation
    throw std::runtime_error("Unknown activation function type");
}