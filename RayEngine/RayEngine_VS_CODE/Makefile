VPATH := ./2D
make:
	g++ main.cpp RayEngine_2D.cpp RayCaster_2D.cpp Renderer_2D.cpp ObjectStorage_2D.cpp Ray_2D.cpp Light_2D.cpp -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lpthread -g -o main.exe -std=c++17 -O3
run:
	make
	./main.exe

clean:
	rm main.exe
