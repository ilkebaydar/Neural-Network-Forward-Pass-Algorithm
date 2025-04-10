#ifndef OOP_HW3_ACTIVATION_H
#define OOP_HW3_ACTIVATION_H

#include <string>

class Activation {
private:
    std::string type;

public:
    // Constructor
    Activation(const std::string& type);

    // Function call operator to apply the activation function
    float operator()(float x) const;

    // Activation function implementations
    static float relu(float x);
    static float sigmoid(float x);

    // Getter for type
    std::string getType() const { return type; }
};
#endif //OOP_HW3_ACTIVATION_H
