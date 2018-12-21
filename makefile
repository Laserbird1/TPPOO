ECHO= @echo
RM = @rm 
COMP = g++ 
EDL = g++

REAL=$(wildcard *.cpp)
INT = $(INT:.cpp=.h)
OBJ=$(REAL:.cpp=.o)
EXE = Utilisation

#options de compilation
EFFACE = clean 
LIBS = -Im 
RMFLAGS = -f
CPPFLAGS = -W -Wall -g -pedantic -O2 -Wextra -ansi -std=c++11 



.PHONY = $(EFFACE)

($EXE):$(OBJ)
	$(ECHO) "EdL de <Test>"TP C++.zip
	$(EDL) -o $(EXE) $(OBJ) $(LIBS)
  
%.o : %.cpp %.h
	$(ECHO) "Compil de <$<>"
	$(COMP) $(CPPFLAGS) -c $<
  
$(EFFACE):
	$(RM) $(RMFLAGS) $(OBJ) $(EXE)


TrajetSimple.o : TrajetSimple.cpp TrajetSimple.h Trajet.h
TrajetCompose.o : TrajetCompose.cpp TrajetCompose.h Tableau.h Trajet.h
Tableau.o : Tableau.cpp Tableau.h Trajet.h TrajetSimple.h TrajetCompose.h 
Catalogue.o : Catalogue.cpp Catalogue.h Tableau.h
Utilisation.o : Utilisation.cpp Utilisation.h Tableau.h TrajetSimple.h TrajetCompose.h Catalogue.h

#valgrind --track-origins=yes --leak-check=full ./Utilisation
