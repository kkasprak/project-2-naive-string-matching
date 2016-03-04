#include "Main.h"
#include <map>

/****************************************************************
 * Main program for Homework 2.
 *
 * Author/copyright:  Duncan Buell. All rights reserved.
 * Date: 7 February 2016
 *
**/

static const string TAG = "Main: ";

/*********************************************************************
**/
int main(int argc, char *argv[])
{
  double timeNew = 0.0;
  string dataFileName = "";
  string patternFileName = "";
  string timeString = "";

  Scanner inScanner;

  SMatch stringmatch;

  Utils::CheckArgs(2, argc, argv, "datafilename patternfilename");
  dataFileName = static_cast<string>(argv[1]);
  patternFileName = static_cast<string>(argv[2]);

  cout << TAG << "Beginning execution\n";

  cout << TAG << "datafile  '" << dataFileName << "'\n";

  timeString = Utils::timecall("beginning", timeNew);
  cout << timeString << endl;

  inScanner.openFile(dataFileName);
  stringmatch.readText(inScanner);
  inScanner.close();
  //cout << stringmatch.toStringText() << endl;

  inScanner.openFile(patternFileName);
  stringmatch.readPatterns(inScanner);
  inScanner.close();
  //cout << stringmatch.toStringText() << endl;
  //cout << stringmatch.toStringPatterns() << endl;
  stringmatch.findMatches();

  //stringmatch.readLetterFreq(letterfrequencies);
/*
  inScanner.openFile(letterfrequencies.txt);
  stringmatch.readLetterFreq(inScanner);
  inScanner.close();
  */

  cout << TAG << "Ending execution\n";

  timeString = Utils::timecall("ending", timeNew);
  cout << timeString << endl;

  return 0;
}


