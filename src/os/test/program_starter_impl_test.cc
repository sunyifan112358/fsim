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

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "src/os/program_starter_impl.h"
#include "src/os/test/mock_operating_system.h"
#include "src/os/test/mock_program_loader.h"
#include "src/os/test/mock_process_factory.h"
#include "src/os/test/mock_thread_factory.h"
#include "src/os/test/mock_process.h"
#include "src/os/test/mock_thread.h"

namespace {

using fsim::os::ProgramStarterImpl;
using fsim::os::MockOperatingSystem;
using fsim::os::MockProgramLoader;
using fsim::os::MockProcessFactory;
using fsim::os::MockThreadFactory;
using fsim::os::MockProcess;
using fsim::os::MockThread;
using ::testing::StrEq;
using ::testing::Return;
using ::testing::Pointee;
using ::testing::ByMove;
using ::testing::_;
using ::testing::Invoke;

TEST(ProgramStarter, Start) {
  MockOperatingSystem operating_system;
  MockProgramLoader program_loader;
  MockProcessFactory process_factory;
  MockThreadFactory thread_factory;
  std::string command = "exec -args";

  EXPECT_CALL(program_loader, Load(StrEq(command)))
    .Times(1);

  EXPECT_CALL(operating_system, DoAddProcess(_))
    .Times(1);

  EXPECT_CALL(process_factory, Produce())
    .WillOnce(Invoke([]() {
      auto process = std::unique_ptr<MockProcess>(new MockProcess());
      EXPECT_CALL(*process.get(), DoAddThread(_)).
        Times(1);
      return std::move(process);
    }));
  EXPECT_CALL(thread_factory, Produce())
    .WillOnce(Invoke([]() {
      auto thread = std::unique_ptr<MockThread>(new MockThread());
      return std::move(thread);
    }));

  ProgramStarterImpl program_starter(&operating_system,
                                     &program_loader,
                                     &process_factory,
                                     &thread_factory);
  program_starter.Start(command);
}

}  // namespace
