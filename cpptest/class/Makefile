SRCDIR := CC
INCDIR := include
OBJDIR := obj

HEADERS  := $(INCDIR)/Time.h
HEADERS  += $(INCDIR)/TAI.h
HEADERS  += $(INCDIR)/MJD.h

SOURCES  := $(SRCDIR)/Time.C
SOURCES  += $(SRCDIR)/TAI.C
SOURCES  += $(SRCDIR)/MJD.C
SOURCES  += main.C

OBJS     := $(OBJDIR)/Time.o
OBJS     += $(OBJDIR)/TAI.o
OBJS     += $(OBJDIR)/MJD.o

DEFINES  := -I. -I$(INCDIR) -I$(OBJDIR) `root-config --cflags`

#CXXFLAGS := -O3 -fPIC -qopenmp
CXXFLAGS := -O3 -fPIC
#CXXFLAGS += -D_THIN_

LDFLAGS  := `root-config --libs`
# -lRGL -lEve -lGeom -lMinuit -lTMVA -lXMLIO -lMLP -lTreePlayer -lXrdClient -lGpad -lNet -lHist -lHistPainter -lGraf -lMatrix -lRooFit

all:main.exe

main.exe: $(OBJDIR)/main.o $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

$(OBJDIR)/main.o: main.C
	mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(DEFINES) -c $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.C
	mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(DEFINES) -c $^ -o $@

clean:
	rm -rfv *.exe $(OBJDIR)/* $(OBJDIR)
