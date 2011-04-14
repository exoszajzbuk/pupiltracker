# simple Makefile for project: Pupil Tracker Demo

CPPFLAGS = -O3 `wx-config --cxxflags --libs --gl-libs` -I/usr/local/include/opencv -L/usr/local/lib -lml -lcvaux -lhighgui -lcv -lcxcore

pupil: main.o gui.o MainFrame.o TrackerModel.o VideoFrame.o OwnCVImage.o ImagePanel.o
	g++ $(CPPFLAGS) -o pupil main.o gui.o MainFrame.o TrackerModel.o VideoFrame.o OwnCVImage.o ImagePanel.o

main.o: main.cpp
	g++ $(CPPFLAGS) -c main.cpp

gui.o: gui.cpp gui.h
	g++ $(CPPFLAGS) -c gui.cpp

MainFrame.o: MainFrame.cpp MainFrame.h gui.cpp gui.h
	g++ $(CPPFLAGS) -c MainFrame.cpp

TrackerModel.o: TrackerModel.cpp TrackerModel.h
	g++ $(CPPFLAGS) -c TrackerModel.cpp

VideoFrame.o: VideoFrame.cpp VideoFrame.h gui.cpp gui.h
	g++ $(CPPFLAGS) -c VideoFrame.cpp

OwnCVImage.o: OwnCVImage.cpp OwnCVImage.h
	g++ $(CPPFLAGS) -c OwnCVImage.cpp

ImagePanel.o: ImagePanel.cpp ImagePanel.h
	g++ $(CPPFLAGS) -c ImagePanel.cpp

clean:
	rm *.o pupil
