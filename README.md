# 🧠 Neural Network Forward Pass Library

A simplified neural network library implemented in **C++** for educational purposes as part of the Object-Oriented Programming course. Details in **BLG_252E___Exercise_3_v2.pdf** file.

This project demonstrates core **OOP principles**, such as **encapsulation**, **composition-aggregation-association has-a-relationships**, and **operator overloading**, through the implementation of a forward pass mechanism in neural networks.

---

## 📌 Features

- **Modular Class Design**
  - `Matrix`, `Activation`, `Layer`, and `Network` classes.
- **Operator Overloading**
  - `+`, `*`, and `[]` in `Matrix`.
  - `()` in `Activation`.
- **Has-a Relationships**
  - `Network` contains `Layer` objects.
  - `Layer` contains `Matrix` objects and references to `Activation` objects.
- **Simple API for Forward Pass**
  - No training—just data transformation.

---

## 🗂️ Components

### 🔢 Matrix
- Handles 2D floating-point data.
- Supports:
  - Element-wise addition (`+`)
  - Matrix multiplication (`*`)
  - Double indexing (`[][]`)
  - Pretty print (`print()`)

### 🧮 Activation
- Supports:
  - ReLU: `f(x) = max(0, x)`
  - Sigmoid: `f(x) = 1 / (1 + e^-x)`
- Callable via `operator()` for clean function-style syntax.

### 🧱 Layer
- Has:
  - A weights matrix
  - A bias matrix
  - A reference to an `Activation` function
- Transforms input using:  
  `output = activation(input * weights + bias)`

### 🌐 Network
- Manages an array of `Layer` objects.
- Performs forward propagation across all layers.

---

## 🧪 Example Usage

```cpp
#include "Matrix.h"
#include "Activation.h"
#include "Layer.h"
#include "Network.h"

int main() {
    Activation relu("relu");
    Activation sigmoid("sigmoid");

    Layer hiddenLayer(2, 3, relu);
    Layer outputLayer(3, 1, sigmoid);

    Network network(2);
    network.addLayer(&hiddenLayer);
    network.addLayer(&outputLayer);

    Matrix input(4, 2);  // Inputs: [0,0], [0,1], [1,0], [1,1]
    input[0][0] = 0.0f; input[0][1] = 0.0f;
    input[1][0] = 0.0f; input[1][1] = 1.0f;
    input[2][0] = 1.0f; input[2][1] = 0.0f;
    input[3][0] = 1.0f; input[3][1] = 1.0f;

    std::cout << "Input:\n";
    input.print();

    Matrix output = network.forward(input);

    std::cout << "Output:\n";
    output.print();

    return 0;
}
