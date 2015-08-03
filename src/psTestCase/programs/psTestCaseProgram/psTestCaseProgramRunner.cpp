
//  psTestCaseProgramRunner.cpp
//
//  Created by Nick Hathaway on 2015/08/03.
//  Copyright (c) 2015 Nick Hathaway. All rights reserved.
//

    
#include "psTestCaseProgramRunner.hpp"
    
    //
namespace psTestCase {

psTestCaseProgramRunner::psTestCaseProgramRunner()
    : bib::progutils::programRunner({addFunc("hellowWorld", hellowWorld, false),
	addFunc("testingCmdPool", testingCmdPool, false)},
                    "psTestCase") {}
                    
int psTestCaseProgramRunner::hellowWorld(std::map<std::string, std::string> inputCommands) {
  psTestCaseProgramSetUp setUp(inputCommands);
  std::string name = "World";
  setUp.setOption(name, "--name", "Someone's Name");
  setUp.finishSetUp(std::cout);
  std::cout << "From psTestCaseProgram hellowWorld, Hello " << name << "!" << std::endl;
  return 0;
}


int psTestCaseProgramRunner::testingCmdPool(std::map<std::string, std::string> inputCommands){
  bib::progutils::programSetUp setUp(inputCommands);
  uint32_t numThreads = 2;
  setUp.setOption(numThreads, "--numThreads", "Number of threads to use", true);
  std::string logFilename = "log.txt";
  setUp.setOption(logFilename, "--log", "Name of a log file", true);
  bool debug = false;
  bool verbose = false;
  bool overWrite = false;
  bool append = false;
  bool exitOnFailure = false;
  setUp.setOption(debug, "--debug", "debug");
  setUp.setOption(verbose, "--verbose", "verbose");
  setUp.setOption(overWrite, "--overWrite", "over write file");
  setUp.setOption(append, "--append", "append file");
  setUp.setOption(exitOnFailure, "--exitOnFailure", "exit On Failure to open file");
  uint32_t sleepLowerBound = 0;
  uint32_t sleepUpperBound = 10;
  setUp.setOption(sleepLowerBound, "--sleepLowerBound", "sleep Lower Bound");
  setUp.setOption(sleepUpperBound, "--sleepUpperBound", "sleep Upper Bound");
  setUp.finishSetUp(std::cout);
  std::ofstream logfile;
  bib::files::openTextFile(logfile, logFilename,".txt",overWrite, append, exitOnFailure );
  bib::randomGenerator gen;
  std::vector<std::string> allCmds;
  for(const auto & pos : iter::range(10)){
  	allCmds.emplace_back("echo " + estd::to_string(pos) + " && sleep " + estd::to_string(gen.unifRand(sleepLowerBound,sleepUpperBound)));
  }
  auto allRunOutputs = bib::sys::runCmdsThreaded(allCmds, numThreads, verbose, debug);
  Json::Value outJson;
  for(const auto & out : allRunOutputs){
  	outJson.append(out.toJson());
  }
  logfile << outJson << std::endl;
  return 0;
}
                    
} // namespace psTestCase
