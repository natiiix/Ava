#include "h/Neuron.hpp"

#include <iostream>

Neuron::Neuron(int prevLayerNeuronCount)
{
    double RAND_MAX_HALF = (double)RAND_MAX / 2.0;
    for (int i = 0; i < prevLayerNeuronCount; i++)
    {
        m_connectionWeights.push_back(((double)rand() - RAND_MAX_HALF) / RAND_MAX_HALF);
        std::cout << i << " " << m_connectionWeights.back() << std::endl;
    }
}

void Neuron::SetValue(double value)
{
    m_value = value;
}

void Neuron::UpdateValue(std::vector<double> &prevLayerValues)
{
    // an extra weight of the bias neuron is being stored
    assert(m_connectionWeights.size() == prevLayerValues.size() + 1);

    double sum = 0.0;

    for (int i = 0; i < prevLayerValues.size(); i++)
    {
        sum += prevLayerValues[i] * m_connectionWeights[i];
    }

    // let's not forget to count in the bias neuron
    sum += 1.0 * m_connectionWeights.back();

    m_value = sum;
}

double Neuron::GetValue()
{
    return m_value;
}