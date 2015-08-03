#pragma once
//

//  psTestCaseProgramRunner.hpp
//
//  Created by Nick Hathaway on 2015/08/03.
//  Copyright (c) 2015 Nick Hathaway. All rights reserved.
//

#include "psTestCaseProgramSetUp.hpp"

namespace psTestCase {

class psTestCaseProgramRunner : public bib::progutils::programRunner {
 public:
  psTestCaseProgramRunner();
  
  static int hellowWorld(std::map<std::string, std::string> inputCommands);
  static int testingCmdPool(std::map<std::string, std::string> inputCommands);

};
} // namespace psTestCase
