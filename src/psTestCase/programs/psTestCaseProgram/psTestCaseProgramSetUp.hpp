#pragma once
//

//  psTestCaseProgramSetUp.hpp
//
//  Created by Nick Hathaway on 2015/08/03.
//  Copyright (c) 2015 Nick Hathaway. All rights reserved.
//
#include <bibcpp.h>
#include "psTestCase/common.h"

namespace psTestCase {

class psTestCaseProgramSetUp : public bib::progutils::programSetUp {

 public:
    using programSetUp::programSetUp; //include programSetUp's constructors
};
} // namespace psTestCase
