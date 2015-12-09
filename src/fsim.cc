/*
* Copyright (c) 2015 Yifan Sun
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*/

#include <memory>
#include "src/simulation/simulation.h"
#include "src/simulation/simulation_impl.h"
#include "src/platform/platform_builder.h"

std::unique_ptr<fsim::simulation::Simulation> CreateSimulation() {
  using fsim::simulation::Simulation;
  using fsim::simulation::SimulationImpl;

  auto simulation = std::unique_ptr<Simulation>(
      new SimulationImpl(nullptr, nullptr, nullptr));
  return simulation;
}

int main(int argc, char *argv[]) {
  auto simulation = CreateSimulation();
  simulation->Run();
  return 0;
}
