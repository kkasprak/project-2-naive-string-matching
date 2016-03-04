#include "SMatch.h"
#include <map>

/******************************************************************************
 *3456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
 * Class 'SMatch' for testing string matching.
 *
 * Author: Duncan A. Buell
 * Date last modified: 17 January 2016
**/

/******************************************************************************
 * Constructor
**/
SMatch::SMatch()
{
}

/******************************************************************************
 * Destructor
**/
SMatch::~SMatch()
{
}

/******************************************************************************
 * General functions.
**/

/******************************************************************************
 * Function to find matches of patterns in the text.
**/
void SMatch::findMatches()
{

string pattern = "";
string fullText = toStringText();
int comps = 0;
float cost = 0.0;
char firstLetter = '\0';

map<char, int> freqMap;

/*
freqMap[' '] = ;
freqMap[1 = "#";
freqMap[2] = "$";
freqMap[1] = "%";
freqMap[90] = "*";
freqMap[2431] = "-";
freqMap[24] = "/";
freqMap[20] = "0";
freqMap[64] = "1";
freqMap[14] = "2";
freqMap[13] = "3";
freqMap[9] = "6";
freqMap[13] = "7";
freqMap[16] = "8";
freqMap[18] = "9";
freqMap[2] = "@";
freqMap[2] = "[";
freqMap[2] = "]";
freqMap[48170] = " ";
freqMap[138880] = " ";
freqMap[138880] = " ";
freqMap[138880] = " ";
freqMap[138880] = " ";
freqMap[138880] = " ";
*/
freqMap[' '] = 138880;
freqMap['#'] = 1;
freqMap['$'] = 2;
freqMap['%'] = 1;
freqMap['*'] = 90;
freqMap['-'] = 2431;
freqMap['/'] = 24;
freqMap['0'] = 20;
freqMap['1'] = 64;
freqMap['2'] = 14;
freqMap['3'] = 13;
freqMap['4'] = 9;
freqMap['5'] = 13;
freqMap['6'] = 16;
freqMap['7'] = 18;
freqMap['8'] = 2;
freqMap['9'] = 2;
freqMap['@'] = 2;
freqMap['a'] = 48170;
freqMap['b'] = 8422;
freqMap['c'] = 13899;
freqMap['d'] = 28046;
freqMap['e'] = 74837;
freqMap['f'] = 13564;
freqMap['g'] = 12548;
freqMap['h'] = 38974;
freqMap['i'] = 41019;
freqMap['j'] = 715;
freqMap['k'] = 4787;
freqMap['l'] = 22047;
freqMap['m'] = 15295;
freqMap['n'] = 42395;
freqMap['o'] = 46537;
freqMap['p'] = 9960;
freqMap['q'] = 666;
freqMap['r'] = 37210;
freqMap['s'] = 37588;
freqMap['t'] = 54051;
freqMap['u'] = 16738;
freqMap['v'] = 5203;
freqMap['w'] = 14121;
freqMap['x'] = 723;
freqMap['y'] = 12186;
freqMap['z'] = 215;





//i = patterncount for original pattern file
//j = iterating through full text file
//k = 

  //determine what the pattern is
  for (int i = 0; i < thePatterns.size(); i++)
  {
    pattern = thePatterns[i];
    //cout << "The pattern is: " << pattern << endl;
    //cout << "Pattern length is: " << pattern.length() << endl;
    //cout << "Text Length is: " << fullText.length() << endl;
    //cout << endl;
    comps = 0;

    for (int j = 0; j < fullText.length(); j++)
    {
      //if hit, test next char(i) in the pattern until it fails
      //if(pattern.at(j) == fullText.at(j))
     
      //cout << "in j for loop and j = " << j << endl;

        for(int k = 0; k < pattern.length(); k++)
        {

            //cout << "in k for loop and k = " << k << endl;
            if(j+k >= fullText.length())
            {
              break;
            }
            if(pattern.at(k) != fullText.at(j+k))
            {
                //cout << "Pattern at " << k << " is \"" << pattern.at(k) << "\"" << endl;
                //cout << "Text at j" << j << " + k" << k << " is \"" << fullText.at(j+k) <<  "\" ***" << endl;
                //cout << "Not a match so breaking" << endl;
                
                break;
            }
            else if(k == pattern.length()-1)
            {
                cout << "MATCH AT " << j << " " << pattern << endl;
                j = (j+pattern.length()-1);
                //comps = comps - pattern.length();

                //cout << "************************* NEW j is " << j << endl;
                break;
            }
            comps++;
            
            

            //cout << "COMPS " << comps << endl;

            //else
            //{
            //cout << "//Pattern at " << k << " is \"" << pattern.at(k) << "\"" << endl;
           // cout << "//Text at j" << j << " +k " << k << " is \"" << fullText.at(j+k) <<  "\" ***" << endl;
            //}
        }
    }
      cout << "COMPS for " << pattern << " " << comps << endl;

      firstLetter = pattern.at(0);
      cost = comps/float(freqMap[firstLetter]);
      cout << "COST of " << pattern << " " << cost << endl;

  }


//
}

/******************************************************************************
 * Function to read the letter frequencies and add to map for comparison.
*/
 
 /*
void SMatch::readLetterFreq(Scanner& inScanner)
{
  int key;
  string value;
  //map<int, string> freqMap;

  while (inScanner.hasNext())
  {
    inScanner >> value >> key;
    freqMap[key] = value;
  }
}
*/

/******************************************************************************
 * Function to read the patterns.
**/
void SMatch::readPatterns(Scanner& inScanner)
{
  while (inScanner.hasNext())
  {
    string input = inScanner.nextLine();
    this->thePatterns.push_back(input);
  }
}

/******************************************************************************
 * Function to read the text.
**/
void SMatch::readText(Scanner& inScanner)
{
  while (inScanner.hasNext())
  {
    string input = inScanner.nextLine();
    this->theText.push_back(input);
  }
}

/******************************************************************************
 * Function to 'toString' the 'vector' of patterns.
**/
string SMatch::toStringPatterns()
{
  string s = "";

  for(int i = 0; i < thePatterns.size(); i++)
  {
    s = s + " " + thePatterns.at(i) + "\n";
  }

  return s;
}


/******************************************************************************
 * Function to 'toString' the 'vector' of text.
**/
string SMatch::toStringText()
{
  string s = "";

  for(int i = 0; i < theText.size(); i++)
  {
    s = s + " " + theText.at(i);
  }
  return s;
}

