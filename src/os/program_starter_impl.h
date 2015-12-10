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

#ifndef SRC_OS_PROGRAM_STARTER_IMPL_H_
#define SRC_OS_PROGRAM_STARTER_IMPL_H_

#include <string>
#include "src/os/program_starter.h"
#include "src/os/operating_system.h"
#include "src/os/process.h"
#include "src/os/thread.h"
#include "src/os/process_factory.h"
#include "src/os/thread_factory.h"
#include "src/os/program_loader.h"

namespace fsim {
namespace os {

class ProgramStarterImpl : public ProgramStarter {
 public:
  ProgramStarterImpl(OperatingSystem *operating_system,
                     ProgramLoader *program_loader,
                     ProcessFactory *program_factory,
                     ThreadFactory *thread_factory);
  virtual ~ProgramStarterImpl();
  void Start(const std::string& command) override;

 private:
  OperatingSystem *operating_system_;
  ProgramLoader *program_loader_;
  ProcessFactory *process_factory_;
  ThreadFactory *thread_factory_;
  std::unique_ptr<Process> process_;
  std::unique_ptr<Thread> thread_;
};

}  // namespace os
}  // namespace fsim

#endif  // SRC_OS_PROGRAM_STARTER_IMPL_H_
