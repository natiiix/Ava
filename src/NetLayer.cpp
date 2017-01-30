#include "h/NetLayer.hpp"

NetLayer::NetLayer(int neuronCount, int prevLayerNeuronCount)
{
    m_neurons.clear();

    for (int i = 0; i < neuronCount; ++i)
    {
        m_neurons.push_back(Neuron(prevLayerNeuronCount));
    }
}

void NetLayer::SetNeuronValues(std::vector<double> values)
{
    assert(m_neurons.size() == values.size());

    for (int i = 0; i < m_neurons.size(); i++)
    {
        m_neurons[i].SetValue(values[i]);
    }
}

void NetLayer::UpdateNeuronValues(std::vector<double> &prevLayerValues)
{
    for (int i = 0; i < m_neurons.size(); i++)
    {
        m_neurons[i].UpdateValue(prevLayerValues);
    }
}

std::vector<double> NetLayer::GetNeuronValues()
{
    std::vector<double> values;
    values.clear();

    for (int i = 0; i < m_neurons.size(); i++)
    {
        values.push_back(m_neurons[i].GetValue());
    }

    return values;
}