LIBS = -lGL -lGLU -lGLEW -lglut -lm


main : Main.c VecLib.c initShader.c 
	gcc -o $@ $^ $(LIBS)





