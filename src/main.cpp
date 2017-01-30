#include <vector>
#include <iostream>

#include "h/misc.hpp"
#include "h/NeuralNet.hpp"

int main(int argc, char *argv[])
{
    writeLine("Ava has started.");

    std::vector<double> inputData;
    inputData.clear();

    inputData.push_back(1.0);
    inputData.push_back(1.0);

    std::vector<int> structure;
    structure.clear();

    structure.push_back(inputData.size());
    structure.push_back(3);
    structure.push_back(1);

    NeuralNet net(structure);
    net.SetInput(inputData);

    net.UpdateLayers();

    std::cout << net.GetOutput().size() << std::endl;
    std::cout << net.GetOutput().front() << std::endl;
    std::cout << net.GetOutput().back() << std::endl;

    pause();
    return 0;
}
