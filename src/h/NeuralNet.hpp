#pragma once

#include <vector>

#include "NetLayer.hpp"

class NeuralNet
{
public:
  NeuralNet(std::vector<int> structure);
  void SetInput(std::vector<double> inputData);
  void UpdateLayers();
  std::vector<double> GetOutput();

private:
  std::vector<NetLayer> m_layers;
};