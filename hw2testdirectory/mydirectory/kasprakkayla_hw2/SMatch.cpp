#include "SMatch.h"
#include <map>

/******************************************************************************
 *3456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
 * Class 'SMatch' for testing string matching.
 *
 * The primary entry point for this class is intended to be the function
 * 'findMatches', which will search a larger text for the given strings.
 *
 * Author: Duncan A. Buell
 * Modified by: Kayla Kasprak
 * Date last modified: 3 March 2016
 *
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
 * This searches the text to find matches of patterns and prints a "MATCH"
 * statement when a match is found. It also computes the cost of this naive
 * string matching algorithm by dividing the number of comparisons past the
 * first letter of the pattern divided by the total number that pattern is
 * found in the text. 
 *
 * Implementation of the algorithm:
 * We first initialize a string 'pattern' to be an empty string.
 * We then create a new string 'fullText' and call the 'toStringText'
 * function. This function converts the text, which was already read in 
 * using the scanner in 'readText', to one long string.
 * The int variable 'comps' is initialized to 0.
 * The float variable 'cost' is initialized to 0.0. Float is necessary
 * because it will be used in division and the result will need to be stored
 * as a decimal number.
 * The char variable 'firstLetter' is initialized to "\0" because at this
 * point we do not know what the first letter will be.
 * 
 * We are given a table of letter frequencies that represent the number of
 * times each letter is found in the full text being read. These key, value
 * pairs are put into a map named 'freqMap' and will be used after the
 * stringMatching is complete to compute the cost of the algorithm. 
 * 
 * The outermost 'for' loop using 'i' determines what the pattern is. 
 * That is, it takes the first phrase or pattern to be searched. 
 * 'thePatterns.size()' would equal the number of total patterns to be 
 * searched. We store the pattern we will currently be looking for in 
 * the variable 'pattern'.
 *
 * The next 'for' loop using 'j' starts iterating through each character 
 * of the text and will continue until the end of the text has been
 * reached.
 * 
 * Another nested 'for' loop using 'k' indicates that for each character 
 * of the text, we will do a comparison for each character of the pattern 
 * as long as there
 * is a match.
 *
 * If index 'j' + index 'k' is greather than the length of the text, out
 * of bounds; exit loop.
 * 
 * If 'j' and 'k' are not matches, the pattern is not a match to the text,
 * so break out of loop and continue.
 *
 * Else, if all of the above conditions have been passed and the length of k
 * is equal to the pattern text, then we have reached the end of the 
 * pattern and it is a match. Is is necessary to use 'pattern().length-1'
 * because a three letter word ('yes' for example) would return a length of
 * 3, but the last letter occurs at index 2. The variable 'k' is
 * representative of the index.
 *    Print out a 'MATCH' statement.
 *    Set 'j' equal to j + pattenlength()-1 so we continue the character
 *    comparisons after the end of the pattern in the text.
 *
 * If none of these 'if' or 'else if' statements are reached, increment
 * variable 'comp' to indicate that an additional comparison has been made.
 * 
 * After all 'for' loops have completed (that is, 'j' has reached the end of
 * the text), print out the number of extra comparisons done for this
 * particular pattern.
 *
 * Lastly, get the first letter of the pattern and use this as the key to
 * call the value of that key in the freqMap created at the beginning of the
 * function. The cost of the algorithm is found by dividing the number of
 * extra comparisons (stored in 'comp') by the number of times that letter
 * appears in the text (value taken from the mapFreq map).
 * 
 * The cost of the searches are as follows:
 * COST of a background of 1.06975
 * COST of a centre point 1.07173
 * COST of bearers you can 1.38162
 * COST of charles let them 1.25196
 * COST of doing no service 1.06379
 * COST of empty my father 1.02246
 * COST of friend miss pross 1.11553
 * COST of guard and from 1.04941
 * COST of jacques three is 2.07692
 * COST of stabs and blows 1.13544
 * COST of that he was 1.46258
 * COST of one of the 1.19604
 * COST of it was the 1.23165
 * COST of the mender of 1.72106
 * COST of it was a 1.22916
 * COST of mender of roads 1.32089
 * COST of said miss pross 1.1115
 * COST of there was a 1.61533
 * COST of out of the 1.18742
 * COST of said mr lorry 1.12038
 *
 * Only one quotient even reaches a value of 2. All of the others are fractions
 * equal to values just over 1.0, meaning the the naive string matching
 * algorithm is actually pretty efficient. We would have to see a lot more
 * unnecessary comparisons to see a greater number here. The lowest quotient
 * we would ever see is 1.0, and that is if the only comparisons done are
 * those of the first characer and they fail every time, meaning that there
 * were no extra comparisons. If 1.0 is the best cost we can expect and we are
 * seeing numbers just over 1.0 (usually significantly less than 2.0), it
 * seems as though the naive string matching algorithm is efficient. While it
 * is likely unnecessary to develop a more efficient algorithm for these
 * particular examples, this may vary depending on the type of text being
 * searched. DNA matching, for example, may require a significant number of
 * extra comparisons, unlike the conventional English language text we are
 * searching for this example.
 *
 * Parameters:
 *    none; the pattern and text are read in the 'readPatterns' and
 *    'readText' fuctions respectively
 * Returns::
 *    void; the matches are simply printed using cout and then
 *    filtered using 'grep' in 'zdExecuteScript.txt'
 *   
**/
void SMatch::findMatches()
{

//Initial pattern
string pattern = "";
//Convert text to string and store in 'fullText'
string fullText = toStringText();
//Initialize comparisons to 0
int comps = 0;
//Initialize cost of the algorithm to 0.0
float cost = 0.0;
//Iitialize firstLetter of the pattern to '\0' since we don't know what it is yet
char firstLetter = '\0';

//Initialize map to store key, value pairs for letter frequencies
map<char, int> freqMap;

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
                //cout << "Not a match" << endl;
                break;
            }
            else if(k == pattern.length()-1)
            {
                cout << "MATCH AT " << j << " " << pattern << endl;
                j = (j+pattern.length()-1);
                break;
            }
            comps++;
        }
    }
      cout << "COMPS for " << pattern << " " << comps << endl;

      //Find first letter of the pattern
      firstLetter = pattern.at(0);
      //Calculate cost of the algorithm for this string
      cost = comps/float(freqMap[firstLetter]);
      //Print cost
      cout << "COST of " << pattern << " " << cost << endl;
  }

}


/******************************************************************************
 * Function to read the patterns.
 *
 * Will read the patterns from a text file using Scanner.
 * Each line is stored to the string 'input' and pushed to the vector 
 * 'thePatterns'.
 *
 * Parameters:
 *    Scanner& inScanner used to read in the file
 * Returns::
 *    void
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
 *
 * Will read the full text froma text file using Scanner.
 * Each line of the file is stored to the string 'input' and then pushed onto
 * the vector 'theText'.
 * Parameters:
 *    Scanner& inScanner used to read in the file
 * Returns::
 *    void
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
 *
 * String 's' is initialized to an empty string.
 * For(int i = 0, i < the vector of patterns, i++), concatenate the existing
 * string with the next character in the pattern text until all characters have
 * been reached and we are left with a string of chracters for the entire 
 * pattern.
 * 
 * Parameters:
 *    none
 * Returns::
 *    string 's' containing the full string of the pattern
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
*
 * String 's' is initialized to an empty string.
 * For(int i = 0, i < the vector of text, i++), concatenate the existing
 * string with the next character in the text until all characters have
 * been reached and we are left with a string of chracters for the entire 
 * text.
 * 
 * Parameters:
 *    none
 * Returns::
 *    string 's' containing the full string of the text
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

