#pragma once

#include <cstdlib>
#include <cassert>
#include <vector>

class Neuron
{
public:
  Neuron(int prevLayerNeuronCount);
  void SetValue(double value);
  void UpdateValue(std::vector<double> &prevLayerValues);
  double GetValue();

private:
  double m_value;
  std::vector<double> m_connectionWeights;
};