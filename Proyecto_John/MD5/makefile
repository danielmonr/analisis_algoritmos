ALL: md5

.PHONY= clean

clean:
	@echo Borrando ejecutable
	\rm -f md5

md5: main.cpp md.cpp
	g++ -std=c++11 main.cpp md.cpp -o md5
