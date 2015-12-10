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

#ifndef SRC_OS_TEST_MOCK_PROCESS_H_
#define SRC_OS_TEST_MOCK_PROCESS_H_

#include "gmock/gmock.h"
#include "src/os/process.h"

namespace fsim {
namespace os {

class MockProcess : public Process {
 public:
  MOCK_METHOD1(SetPid,
      void(uint64_t pid));
  MOCK_CONST_METHOD0(GetPid,
      uint64_t());

  MOCK_METHOD1(DoAddThread, void(Thread *thread));
  void AddThread(std::unique_ptr<Thread> thread) override {
    DoAddThread(thread.get());
  }
};

}  // namespace os
}  // namespace fsim

#endif  // SRC_OS_TEST_MOCK_PROCESS_H_
