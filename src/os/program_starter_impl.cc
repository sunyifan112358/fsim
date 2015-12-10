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

#include "src/os/program_starter_impl.h"
#include <string>

namespace fsim {
namespace os {

ProgramStarterImpl::ProgramStarterImpl(
    OperatingSystem *operating_system,
    ProgramLoader *program_loader,
    ProcessFactory *process_factory,
    ThreadFactory *thread_factory) :
    operating_system_(operating_system),
    program_loader_(program_loader),
    process_factory_(process_factory),
    thread_factory_(thread_factory) {
}

ProgramStarterImpl::~ProgramStarterImpl() {
}

void ProgramStarterImpl::Start(const std::string& command) {
  std::unique_ptr<Program> program = program_loader_->Load(command);
  std::unique_ptr<Process> process = process_factory_->Produce();
  std::unique_ptr<Thread> thread = thread_factory_->Produce();
  process->AddThread(std::move(thread));
  operating_system_->AddProcess(std::move(process));
}

}  // namespace os
}  // namespace fsim
