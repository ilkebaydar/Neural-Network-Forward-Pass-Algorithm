#ifndef OOP_HW3_NETWORK_H
#define OOP_HW3_NETWORK_H
#include "Layer.h"

class Network {
private:
    Layer** layers;
    int maxLayers;
    int layer_count;

public:
    Network(int maxLayers);
    ~Network();
    // Add a layer to the network
    bool addLayer(Layer* layer);
    // Forward pass through the network
    Matrix forward(const Matrix& input) const;
    // Get number of layers
    int getLayerCount() const { return layer_count; }
};

#endif //OOP_HW3_NETWORK_H
