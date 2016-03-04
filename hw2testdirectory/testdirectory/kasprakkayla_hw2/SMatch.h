/****************************************************************
 * Header file for the string matching test.
 *
 * Author/copyright:  Duncan Buell
 * Date: 7 February 2016
 *
**/

#ifndef SMATCH_H
#define SMATCH_H

#include <iostream>
#include <vector>
#include <map>
using namespace std;

#include "../../Utilities/Scanner.h"
#include "../../Utilities/ScanLine.h"

class SMatch
{
public:
  SMatch();
  virtual ~SMatch();

  void findMatches();
  //void readLetterFreqs(Scanner& inScanner);
  void readPatterns(Scanner& inScanner);
  void readText(Scanner& inScanner);

  string toStringText();
  string toStringPatterns();

private:
  vector<string> theText;
  vector<string> thePatterns;
  map<int, string> freqMap;

};

#endif
