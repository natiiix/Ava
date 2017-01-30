#include "h/NeuralNet.hpp"

NeuralNet::NeuralNet(std::vector<int> structure)
{
    m_layers.clear();

    for (int i = 0; i < structure.size(); i++)
    {
        // input layer doesn't have any previous layer
        // bias neuron needs to be counted in
        int prevLayerNeuronCount = (i > 0 ? structure[i - 1] + 1 : 0);
        m_layers.push_back(NetLayer(structure[i], prevLayerNeuronCount));
    }
}

void NeuralNet::SetInput(std::vector<double> inputData)
{
    m_layers.front().SetNeuronValues(inputData);
}

void NeuralNet::UpdateLayers()
{
    // input layer isn't being updated
    for (int i = 1; i < m_layers.size(); i++)
    {
        std::vector<double> prevLayerNeuronValues = m_layers[i - 1].GetNeuronValues();
        m_layers[i].UpdateNeuronValues(prevLayerNeuronValues);
    }
}

std::vector<double> NeuralNet::GetOutput()
{
    return m_layers.back().GetNeuronValues();
}