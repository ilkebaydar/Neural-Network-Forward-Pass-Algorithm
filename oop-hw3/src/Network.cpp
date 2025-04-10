#include "../include/Network.h"
#include <stdexcept>

Network::Network(int maxLayers) : maxLayers(maxLayers), layer_count(0) {
    layers = new Layer*[maxLayers];
}

Network::~Network() {
    delete[] layers;
}


bool Network::addLayer(Layer* layer) {
    if (layer_count < maxLayers) {
        layers[layer_count++] = layer;
        return true;
    } else return false;
}

Matrix Network::forward(const Matrix& input) const {
    // If network contains no layers, return input unchanged
    if (layer_count == 0) {
        return input;
    }

    // Process through first layer
    Matrix current_output = layers[0]->forward(input);

    // Process through remaining layers sequentially
    for (int i = 1; i < layer_count; i++) {
        current_output = layers[i]->forward(current_output);
    }
    return current_output;
}
