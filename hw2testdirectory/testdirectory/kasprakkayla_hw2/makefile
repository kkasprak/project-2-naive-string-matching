GPP = g++ -O3 -Wall -std=c++11

UTILS = ../../Utilities

A = Main.o
M = SMatch.o
R = MyRandom.o
S = Scanner.o
SL = ScanLine.o
U = Utils.o

Aprog: $(A) $(M) $(R) $(S) $(SL) $(U)
	$(GPP) -o Aprog $(A) $(M) $(R) $(S) $(SL) $(U)

Main.o: Main.h Main.cpp
	$(GPP) -c Main.cpp

SMatch.o: SMatch.h SMatch.cpp
	$(GPP) -c SMatch.cpp

MyRandom.o: MyRandom.h MyRandom.cpp
	$(GPP) -c MyRandom.cpp

Scanner.o: $(UTILS)/Scanner.h $(UTILS)/Scanner.cpp
	$(GPP) -c $(UTILS)/Scanner.cpp

ScanLine.o: $(UTILS)/ScanLine.h $(UTILS)/ScanLine.cpp
	$(GPP) -c $(UTILS)/ScanLine.cpp

Utils.o: $(UTILS)/Utils.h $(UTILS)/Utils.cpp
	$(GPP) -c $(UTILS)/Utils.cpp
