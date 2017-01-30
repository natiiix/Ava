#pragma once

#include <vector>
#include <cassert>

#include "Neuron.hpp"

class NetLayer
{
public:
  NetLayer(int neuronCount, int prevLayerNeuronCount);
  void SetNeuronValues(std::vector<double> values);
  void UpdateNeuronValues(std::vector<double> &prevLayerValues);
  std::vector<double> GetNeuronValues();

private:
  std::vector<Neuron> m_neurons;
};